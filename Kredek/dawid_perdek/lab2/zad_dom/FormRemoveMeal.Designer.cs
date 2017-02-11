namespace DawidPerdekZad2
{
    partial class FormRemoveMeal
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
            this.buttonCancelRemoveMeal = new System.Windows.Forms.Button();
            this.buttonRemoveMeal = new System.Windows.Forms.Button();
            this.listBoxRemoveMeal = new System.Windows.Forms.ListBox();
            this.labelRemoveMeal = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // buttonCancelRemoveMeal
            // 
            this.buttonCancelRemoveMeal.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.buttonCancelRemoveMeal.Location = new System.Drawing.Point(160, 187);
            this.buttonCancelRemoveMeal.Name = "buttonCancelRemoveMeal";
            this.buttonCancelRemoveMeal.Size = new System.Drawing.Size(107, 65);
            this.buttonCancelRemoveMeal.TabIndex = 8;
            this.buttonCancelRemoveMeal.Text = "Anuluj";
            this.buttonCancelRemoveMeal.UseVisualStyleBackColor = true;
            this.buttonCancelRemoveMeal.Click += new System.EventHandler(this.buttonCancelRemoveMeal_Click);
            // 
            // buttonRemoveMeal
            // 
            this.buttonRemoveMeal.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.buttonRemoveMeal.Location = new System.Drawing.Point(17, 187);
            this.buttonRemoveMeal.Name = "buttonRemoveMeal";
            this.buttonRemoveMeal.Size = new System.Drawing.Size(107, 65);
            this.buttonRemoveMeal.TabIndex = 7;
            this.buttonRemoveMeal.Text = "Usuń";
            this.buttonRemoveMeal.UseVisualStyleBackColor = true;
            this.buttonRemoveMeal.Click += new System.EventHandler(this.buttonRemoveMeal_Click);
            // 
            // listBoxRemoveMeal
            // 
            this.listBoxRemoveMeal.FormattingEnabled = true;
            this.listBoxRemoveMeal.Location = new System.Drawing.Point(74, 34);
            this.listBoxRemoveMeal.Name = "listBoxRemoveMeal";
            this.listBoxRemoveMeal.Size = new System.Drawing.Size(135, 147);
            this.listBoxRemoveMeal.TabIndex = 6;
            // 
            // labelRemoveMeal
            // 
            this.labelRemoveMeal.AutoSize = true;
            this.labelRemoveMeal.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.labelRemoveMeal.Location = new System.Drawing.Point(27, 11);
            this.labelRemoveMeal.Name = "labelRemoveMeal";
            this.labelRemoveMeal.Size = new System.Drawing.Size(216, 20);
            this.labelRemoveMeal.TabIndex = 5;
            this.labelRemoveMeal.Text = "Wybierz posiłek do usunięcia:";
            // 
            // FormRemoveMeal
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(284, 262);
            this.Controls.Add(this.buttonCancelRemoveMeal);
            this.Controls.Add(this.buttonRemoveMeal);
            this.Controls.Add(this.listBoxRemoveMeal);
            this.Controls.Add(this.labelRemoveMeal);
            this.Name = "FormRemoveMeal";
            this.Text = "Usuwanie posiłku";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button buttonCancelRemoveMeal;
        private System.Windows.Forms.Button buttonRemoveMeal;
        private System.Windows.Forms.ListBox listBoxRemoveMeal;
        private System.Windows.Forms.Label labelRemoveMeal;
    }
}