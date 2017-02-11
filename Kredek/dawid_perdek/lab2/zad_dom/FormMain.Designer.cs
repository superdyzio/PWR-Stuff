namespace DawidPerdekZad2
{
    partial class FormMain
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
            this.pictureBoxBackground = new System.Windows.Forms.PictureBox();
            this.buttonHomework0 = new System.Windows.Forms.Button();
            this.buttonHomework1 = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxBackground)).BeginInit();
            this.SuspendLayout();
            // 
            // pictureBoxBackground
            // 
            this.pictureBoxBackground.Image = global::DawidPerdekZad2.Properties.Resources.background;
            this.pictureBoxBackground.Location = new System.Drawing.Point(0, 0);
            this.pictureBoxBackground.Name = "pictureBoxBackground";
            this.pictureBoxBackground.Size = new System.Drawing.Size(391, 357);
            this.pictureBoxBackground.TabIndex = 0;
            this.pictureBoxBackground.TabStop = false;
            // 
            // buttonHomework0
            // 
            this.buttonHomework0.Location = new System.Drawing.Point(12, 12);
            this.buttonHomework0.Name = "buttonHomework0";
            this.buttonHomework0.Size = new System.Drawing.Size(150, 30);
            this.buttonHomework0.TabIndex = 1;
            this.buttonHomework0.Text = "Zadanie domowe 0";
            this.buttonHomework0.UseVisualStyleBackColor = true;
            this.buttonHomework0.Click += new System.EventHandler(this.buttonHomework0_Click);
            // 
            // buttonHomework1
            // 
            this.buttonHomework1.Location = new System.Drawing.Point(223, 12);
            this.buttonHomework1.Name = "buttonHomework1";
            this.buttonHomework1.Size = new System.Drawing.Size(150, 30);
            this.buttonHomework1.TabIndex = 2;
            this.buttonHomework1.Text = "Zadanie domowe 1";
            this.buttonHomework1.UseVisualStyleBackColor = true;
            this.buttonHomework1.Click += new System.EventHandler(this.buttonHomework1_Click);
            // 
            // FormMain
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(384, 342);
            this.Controls.Add(this.buttonHomework1);
            this.Controls.Add(this.buttonHomework0);
            this.Controls.Add(this.pictureBoxBackground);
            this.Name = "FormMain";
            this.Text = "Okno główne aplikacji";
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxBackground)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.PictureBox pictureBoxBackground;
        private System.Windows.Forms.Button buttonHomework0;
        private System.Windows.Forms.Button buttonHomework1;
    }
}

