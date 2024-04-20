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
        public Form1()
        {
            InitializeComponent();
        }

        public ModelNET game;

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
                lblStepCnt.Location = new Point(10, 10 + 20 * game.getObsCnt());
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
                lblCollectedCoin.Location = new Point(10, 10 + 20 * game.getObsCnt());
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
                lblHP.Location = new Point(10, 10 + 20 * game.getObsCnt());
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
                panelAround.Location = new Point(10, 10 + 20 * game.getObsCnt());
                panelAround.Size = new Size(100, 100);
                panelAround.BackColor = Color.White;
                panelAround.BorderStyle = BorderStyle.FixedSingle;

                form.Controls.Add(panelAround);
            }

            override public void event_m(ModelNET game)
            {
                Graphics g = panelAround.CreateGraphics();
                game.paintAround(g);
            }

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            game = new ModelNET();

            /*
            ShowStepCnt showStepCnt = new ShowStepCnt(10, 10, game, this);
            ShowCollectedCoin showCollectedCoin = new ShowCollectedCoin(10, 30, game, this);
            ShowHP showHP = new ShowHP(10, 50, game, this);

            game.addObserver(showStepCnt);
            game.addObserver(showCollectedCoin);
            game.addObserver(showHP);
            */

            ShowStepCnt showStepCnt = new ShowStepCnt(game, this);
            game.addObserver(showStepCnt);

            ShowCollectedCoin showCollectedCoin = new ShowCollectedCoin(game, this);
            game.addObserver(showCollectedCoin);

            ShowHP showHP = new ShowHP(game, this);
            game.addObserver(showHP);

            ShowAround showAround = new ShowAround(game, this);
            game.addObserver(showAround);


        }

        private void panel1_Paint(object sender, PaintEventArgs e)
        {
            ;
        }
    }
}
