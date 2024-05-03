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
            
            label1.Text = ((int)e.KeyCode).ToString();

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
            game = new ModelNET();
            controller = new Controller(game);

            ShowStepCntNET showStepCnt = new ShowStepCntNET(game, this);
            game.addObserver(showStepCnt);

            ShowCollectedCoinNET showCollectedCoin = new ShowCollectedCoinNET(game, this);
            game.addObserver(showCollectedCoin);

            ShowHPNET showHP = new ShowHPNET(game, this);
            game.addObserver(showHP);
        }

        private void panel1_Paint(object sender, PaintEventArgs e)
        {
            ;
        }
    }
}
