namespace WindowsApp
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.label_step = new System.Windows.Forms.Label();
            this.label_hp = new System.Windows.Forms.Label();
            this.label_coin = new System.Windows.Forms.Label();
            this.panel_around = new System.Windows.Forms.Panel();
            this.panel_all = new System.Windows.Forms.Panel();
            this.SuspendLayout();
            // 
            // label_step
            // 
            this.label_step.AutoSize = true;
            this.label_step.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label_step.ForeColor = System.Drawing.Color.White;
            this.label_step.Location = new System.Drawing.Point(12, 9);
            this.label_step.Name = "label_step";
            this.label_step.Size = new System.Drawing.Size(95, 24);
            this.label_step.TabIndex = 2;
            this.label_step.Text = "label_step";
            // 
            // label_hp
            // 
            this.label_hp.AutoSize = true;
            this.label_hp.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label_hp.ForeColor = System.Drawing.Color.White;
            this.label_hp.Location = new System.Drawing.Point(12, 57);
            this.label_hp.Name = "label_hp";
            this.label_hp.Size = new System.Drawing.Size(82, 24);
            this.label_hp.TabIndex = 3;
            this.label_hp.Text = "label_hp";
            // 
            // label_coin
            // 
            this.label_coin.AutoSize = true;
            this.label_coin.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label_coin.ForeColor = System.Drawing.Color.White;
            this.label_coin.Location = new System.Drawing.Point(12, 33);
            this.label_coin.Name = "label_coin";
            this.label_coin.Size = new System.Drawing.Size(96, 24);
            this.label_coin.TabIndex = 4;
            this.label_coin.Text = "label_coin";
            // 
            // panel_around
            // 
            this.panel_around.BackColor = System.Drawing.Color.Black;
            this.panel_around.Location = new System.Drawing.Point(11, 94);
            this.panel_around.Margin = new System.Windows.Forms.Padding(2);
            this.panel_around.Name = "panel_around";
            this.panel_around.Size = new System.Drawing.Size(238, 227);
            this.panel_around.TabIndex = 5;
            this.panel_around.Paint += new System.Windows.Forms.PaintEventHandler(this.panel_around_Paint);
            // 
            // panel_all
            // 
            this.panel_all.BackColor = System.Drawing.Color.Black;
            this.panel_all.Location = new System.Drawing.Point(253, 9);
            this.panel_all.Margin = new System.Windows.Forms.Padding(2);
            this.panel_all.Name = "panel_all";
            this.panel_all.Size = new System.Drawing.Size(1416, 962);
            this.panel_all.TabIndex = 6;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.Black;
            this.ClientSize = new System.Drawing.Size(1754, 982);
            this.Controls.Add(this.panel_all);
            this.Controls.Add(this.panel_around);
            this.Controls.Add(this.label_coin);
            this.Controls.Add(this.label_hp);
            this.Controls.Add(this.label_step);
            this.DoubleBuffered = true;
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Label label_step;
        private System.Windows.Forms.Label label_hp;
        private System.Windows.Forms.Label label_coin;
        private System.Windows.Forms.Panel panel_all;
        private System.Windows.Forms.Panel panel_around;
    }
}

