namespace DawidPerdekZad4.View
{
    partial class FormStartNewGame
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
            this.labelPlayerName = new System.Windows.Forms.Label();
            this.textBoxPlayerName = new System.Windows.Forms.TextBox();
            this.buttonStartPlaying = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // labelPlayerName
            // 
            this.labelPlayerName.AutoSize = true;
            this.labelPlayerName.Font = new System.Drawing.Font("Microsoft Sans Serif", 18F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.labelPlayerName.Location = new System.Drawing.Point(73, 39);
            this.labelPlayerName.Name = "labelPlayerName";
            this.labelPlayerName.Size = new System.Drawing.Size(134, 29);
            this.labelPlayerName.TabIndex = 0;
            this.labelPlayerName.Text = "Podaj imię:";
            // 
            // textBoxPlayerName
            // 
            this.textBoxPlayerName.Location = new System.Drawing.Point(64, 96);
            this.textBoxPlayerName.Name = "textBoxPlayerName";
            this.textBoxPlayerName.Size = new System.Drawing.Size(158, 20);
            this.textBoxPlayerName.TabIndex = 1;
            // 
            // buttonStartPlaying
            // 
            this.buttonStartPlaying.Font = new System.Drawing.Font("Microsoft Sans Serif", 13F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.buttonStartPlaying.Location = new System.Drawing.Point(78, 170);
            this.buttonStartPlaying.Name = "buttonStartPlaying";
            this.buttonStartPlaying.Size = new System.Drawing.Size(129, 52);
            this.buttonStartPlaying.TabIndex = 2;
            this.buttonStartPlaying.Text = "Zaczynamy!";
            this.buttonStartPlaying.UseVisualStyleBackColor = true;
            this.buttonStartPlaying.Click += new System.EventHandler(this.buttonStartPlaying_Click);
            // 
            // FormStartNewGame
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(284, 262);
            this.Controls.Add(this.buttonStartPlaying);
            this.Controls.Add(this.textBoxPlayerName);
            this.Controls.Add(this.labelPlayerName);
            this.Name = "FormStartNewGame";
            this.Text = "Nowa gra";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label labelPlayerName;
        private System.Windows.Forms.TextBox textBoxPlayerName;
        private System.Windows.Forms.Button buttonStartPlaying;
    }
}