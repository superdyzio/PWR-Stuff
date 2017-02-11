namespace DawidPerdekZad1
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
            this.labelMainWindow = new System.Windows.Forms.Label();
            this.buttonClassicCalculator = new System.Windows.Forms.Button();
            this.buttonAdvancedCalculator = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // labelMainWindow
            // 
            this.labelMainWindow.AutoSize = true;
            this.labelMainWindow.Font = new System.Drawing.Font("Microsoft Sans Serif", 16F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.labelMainWindow.Location = new System.Drawing.Point(10, 20);
            this.labelMainWindow.Name = "labelMainWindow";
            this.labelMainWindow.Size = new System.Drawing.Size(267, 26);
            this.labelMainWindow.TabIndex = 0;
            this.labelMainWindow.Text = "Wybierz typ kalkulatora:";
            // 
            // buttonClassicCalculator
            // 
            this.buttonClassicCalculator.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.buttonClassicCalculator.ForeColor = System.Drawing.SystemColors.GrayText;
            this.buttonClassicCalculator.Location = new System.Drawing.Point(70, 80);
            this.buttonClassicCalculator.Name = "buttonClassicCalculator";
            this.buttonClassicCalculator.Size = new System.Drawing.Size(150, 50);
            this.buttonClassicCalculator.TabIndex = 1;
            this.buttonClassicCalculator.Text = "Kalkulator klasyczny";
            this.buttonClassicCalculator.UseVisualStyleBackColor = true;
            this.buttonClassicCalculator.Click += new System.EventHandler(this.buttonClassicCalculator_Click);
            // 
            // buttonAdvancedCalculator
            // 
            this.buttonAdvancedCalculator.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.buttonAdvancedCalculator.ForeColor = System.Drawing.SystemColors.GrayText;
            this.buttonAdvancedCalculator.Location = new System.Drawing.Point(70, 160);
            this.buttonAdvancedCalculator.Name = "buttonAdvancedCalculator";
            this.buttonAdvancedCalculator.Size = new System.Drawing.Size(150, 50);
            this.buttonAdvancedCalculator.TabIndex = 2;
            this.buttonAdvancedCalculator.Text = "Kalkulator zaawansowany";
            this.buttonAdvancedCalculator.UseVisualStyleBackColor = true;
            this.buttonAdvancedCalculator.Click += new System.EventHandler(this.buttonAdvancedCalculator_Click);
            // 
            // FormMain
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(284, 262);
            this.Controls.Add(this.buttonAdvancedCalculator);
            this.Controls.Add(this.buttonClassicCalculator);
            this.Controls.Add(this.labelMainWindow);
            this.Name = "FormMain";
            this.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.Text = "Okno główne";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label labelMainWindow;
        private System.Windows.Forms.Button buttonClassicCalculator;
        private System.Windows.Forms.Button buttonAdvancedCalculator;
    }
}

