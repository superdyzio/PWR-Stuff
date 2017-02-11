namespace DawidPerdekZad3.View
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
            this.buttonStartZad0 = new System.Windows.Forms.Button();
            this.buttonStartZad1 = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // buttonStartZad0
            // 
            this.buttonStartZad0.BackColor = System.Drawing.SystemColors.ControlDarkDark;
            this.buttonStartZad0.Font = new System.Drawing.Font("Microsoft Sans Serif", 16F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.buttonStartZad0.Location = new System.Drawing.Point(22, 35);
            this.buttonStartZad0.Name = "buttonStartZad0";
            this.buttonStartZad0.Size = new System.Drawing.Size(250, 50);
            this.buttonStartZad0.TabIndex = 0;
            this.buttonStartZad0.Text = "Zadanie domowe - 0";
            this.buttonStartZad0.UseVisualStyleBackColor = false;
            this.buttonStartZad0.Click += new System.EventHandler(this.buttonStartZad0_Click);
            // 
            // buttonStartZad1
            // 
            this.buttonStartZad1.BackColor = System.Drawing.SystemColors.ControlDarkDark;
            this.buttonStartZad1.Font = new System.Drawing.Font("Microsoft Sans Serif", 16F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.buttonStartZad1.Location = new System.Drawing.Point(22, 166);
            this.buttonStartZad1.Name = "buttonStartZad1";
            this.buttonStartZad1.Size = new System.Drawing.Size(250, 50);
            this.buttonStartZad1.TabIndex = 1;
            this.buttonStartZad1.Text = "Zadanie domowe - 1";
            this.buttonStartZad1.UseVisualStyleBackColor = false;
            this.buttonStartZad1.Click += new System.EventHandler(this.buttonStartZad1_Click);
            // 
            // FormMain
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(284, 262);
            this.Controls.Add(this.buttonStartZad1);
            this.Controls.Add(this.buttonStartZad0);
            this.Name = "FormMain";
            this.Text = "Okno główne";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button buttonStartZad0;
        private System.Windows.Forms.Button buttonStartZad1;
    }
}

