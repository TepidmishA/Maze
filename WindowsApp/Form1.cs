using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsApp
{
    public partial class Form1 : Form
    {
        Pen p = new Pen(Color.Black, 3);

        public Form1()
        {
            InitializeComponent();

            this.KeyPreview = true;
            this.KeyDown += new KeyEventHandler(FormKeyDown);
        }

        private void FormKeyDown(object sender, KeyEventArgs e)
        {
            int keyCode = (int)e.KeyCode;
            // невозможно передать KeyEventArgs в controller.step() ???
            try
            {
                controller.step(keyCode);
            }
            catch (ExceptionZeroHPNET ex)
            {
                MessageBox.Show("Congratulations! You lose.", "Loser!", MessageBoxButtons.OK, MessageBoxIcon.Information);
                this.Close();
            }
            catch (ExceptionWinNET ex)
            {
                MessageBox.Show("Congratulations! You win.", "Victory!", MessageBoxButtons.OK, MessageBoxIcon.Information);
                this.Close();
            }
        }

        public ModelNET game;
        private Controller controller;

        private void Form1_Load(object sender, EventArgs e)
        {
            game = new ModelNET(20, 20);
            controller = new Controller(game);

            game.addObserver(new ShowStepCntNET(label_step));
            game.addObserver(new ShowCollectedCoinNET(label_coin));
            game.addObserver(new ShowHPNET(label_hp));
            game.addObserver(new ShowAroundNET(panel_around));
            game.addObserver(new ShowAllNET(panel_all));

            initControls(game);
        }

        private void initControls(ModelNET game)
        {
            wall thing = new wall();
            thing.Location = new Point(0, 0);

            game.initUserControl("wall", new wall());
            game.initUserControl("hero", new hero());
            game.initUserControl("coin", new coin());
            game.initUserControl("emptyCell", new emptyCell());
            game.initUserControl("monster", new monster());
        }
        private void panel_around_Paint(object sender, PaintEventArgs e)
        {
            game.update();
        }
    }
}
