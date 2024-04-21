using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

/*
ToDo:
1. Fix coin check for win (ExicCell(COINS))
2. Add color to panel
*/


namespace WindowsApp
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            this.KeyPreview = true;
            this.KeyDown += new KeyEventHandler(FormKeyDown);
        }

        private object ex;
        private void FormKeyDown(object sender, KeyEventArgs e)
        {
            int keyCode = (int)e.KeyCode;

            label1.Text = keyCode.ToString();
            try
            {
                controller.step(keyCode);
            }
            catch (ExceptionZeroHPNET ex) {
                MessageBox.Show("Congratulations! You lose.", "Loser!", MessageBoxButtons.OK, MessageBoxIcon.Information);
                this.Close();
            }
            catch (ExceptionWinNET ex) {
                MessageBox.Show("Congratulations! You win.", "Victory!", MessageBoxButtons.OK, MessageBoxIcon.Information);
                this.Close();
            }
        }


        private ModelNET game;
        private Controller controller;
        List<Color> colors = new List<Color>();
        

        void CreateColorList(List<Color> colors)
        {
            colors.Add(Color.Black);
            colors.Add(Color.Blue);
            colors.Add(Color.Green);
            colors.Add(Color.Cyan);
            colors.Add(Color.Red);
            colors.Add(Color.Magenta);
            colors.Add(Color.Yellow);
            colors.Add(Color.White);
        }

        class ShowStepCnt : IObserverDLL
        {
            Label lblStepCnt;

            public ShowStepCnt(int x, int y, ModelNET game, Form form) {
                lblStepCnt = new Label();
                lblStepCnt.Text = "Count step: " + game.getStepCnt().ToString();
                lblStepCnt.AutoSize = true;
                lblStepCnt.Location = new Point(x, y);
                lblStepCnt.Font = new Font("Arial", 12);
                form.Controls.Add(lblStepCnt);
            }
            public ShowStepCnt(ModelNET game, Form form)
            {
                lblStepCnt = new Label();
                lblStepCnt.Text = "Count step: " + game.getStepCnt().ToString();
                lblStepCnt.AutoSize = true;
                lblStepCnt.Location = new Point(10, 10 + game.getObsDeltaY());
                lblStepCnt.Font = new Font("Arial", 12);
                form.Controls.Add(lblStepCnt);
            }

            override public void event_m(ModelNET game)
            {
                lblStepCnt.Text = "Count step: " + game.getStepCnt().ToString();
            }
        }

        class ShowCollectedCoin : IObserverDLL
        {
            Label lblCollectedCoin;

            public ShowCollectedCoin(int x, int y, ModelNET game, Form form)
            {
                lblCollectedCoin = new Label();
                lblCollectedCoin.Text = "Coins collected: " + game.getCollectedCoins().ToString();
                lblCollectedCoin.AutoSize = true;
                lblCollectedCoin.Location = new Point(x, y);
                lblCollectedCoin.Font = new Font("Arial", 12);
                form.Controls.Add(lblCollectedCoin);
            }

            public ShowCollectedCoin(ModelNET game, Form form)
            {
                lblCollectedCoin = new Label();
                lblCollectedCoin.Text = "Coins collected: " + game.getCollectedCoins().ToString();
                lblCollectedCoin.AutoSize = true;
                lblCollectedCoin.Location = new Point(10, 10 + game.getObsDeltaY());
                lblCollectedCoin.Font = new Font("Arial", 12);
                form.Controls.Add(lblCollectedCoin);
            }

            override public void event_m(ModelNET game)
            {
                lblCollectedCoin.Text = "Coins collected: " + game.getCollectedCoins().ToString();
            }
        }

        class ShowHP : IObserverDLL
        {
            Label lblHP;

            public ShowHP(int x, int y, ModelNET game, Form form)
            {
                lblHP = new Label();
                lblHP.Text = "HP: " + game.getHp().ToString();
                lblHP.AutoSize = true;
                lblHP.Location = new Point(x, y);
                lblHP.Font = new Font("Arial", 12);
                form.Controls.Add(lblHP);
            }

            public ShowHP(ModelNET game, Form form)
            {
                lblHP = new Label();
                lblHP.Text = "HP: " + game.getHp().ToString();
                lblHP.AutoSize = true;
                lblHP.Location = new Point(10, 10 + game.getObsDeltaY());
                lblHP.Font = new Font("Arial", 12);
                form.Controls.Add(lblHP);
            }

            override public void event_m(ModelNET game)
            {
                lblHP.Text = "HP: " + game.getHp().ToString();
            }
        }

        class ShowAround : IObserverDLL
        {
            Panel panelAround;

            public ShowAround(ModelNET game, Form form)
            {
                panelAround = new Panel();
                panelAround.Location = new Point(10, 10 + game.getObsDeltaY());
                game.addObsDeltaY((game.getViewField() * 2) * 14);
                panelAround.Size = new Size((game.getViewField() * 2 + 1) * 13, (game.getViewField() * 2 + 1) * 13);
                panelAround.BackColor = Color.White;
                panelAround.BorderStyle = BorderStyle.FixedSingle;

                form.Controls.Add(panelAround);
            }

            override public void event_m(ModelNET game)
            {
                game.paintAround(panelAround);
            }
        }

        class ShowAll : IObserverDLL
        {
            Panel panelAll;

            public ShowAll(ModelNET game, Form form)
            {
                panelAll = new Panel();
                panelAll.Location = new Point(10, 10 + game.getObsDeltaY());
                panelAll.Size = new Size(game.getLabW() * 13, game.getLabH() * 13);
                panelAll.BackColor = Color.White;
                panelAll.BorderStyle = BorderStyle.FixedSingle;

                form.Controls.Add(panelAll);
            }

            override public void event_m(ModelNET game)
            {
                game.paintAll(panelAll);
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            CreateColorList(colors);
            game = new ModelNET(5, 5);
            controller = new Controller(game);

            /*
            ShowStepCnt showStepCnt = new ShowStepCnt(10, 10, game, this);
            ShowCollectedCoin showCollectedCoin = new ShowCollectedCoin(10, 30, game, this);
            ShowHP showHP = new ShowHP(10, 50, game, this);

            game.addObserver(showStepCnt);
            game.addObserver(showCollectedCoin);
            game.addObserver(showHP);
            */

            game.genMaze();

            ShowStepCnt showStepCnt = new ShowStepCnt(game, this);
            game.addObserver(showStepCnt);

            ShowCollectedCoin showCollectedCoin = new ShowCollectedCoin(game, this);
            game.addObserver(showCollectedCoin);

            ShowHP showHP = new ShowHP(game, this);
            game.addObserver(showHP);

            ShowAround showAround = new ShowAround(game, this);
            game.addObserver(showAround);

            ShowAll showAll = new ShowAll(game, this);
            game.addObserver(showAll);
        }

        
        private void panel1_Paint(object sender, PaintEventArgs e)
        {
            ;
        }
    }
}
