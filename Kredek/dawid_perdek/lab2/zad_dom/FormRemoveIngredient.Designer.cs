namespace DawidPerdekZad2
{
    partial class FormRemoveIngredient
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
            this.labelRemoveIngredient = new System.Windows.Forms.Label();
            this.listBoxRemoveIngredient = new System.Windows.Forms.ListBox();
            this.buttonRemoveIngredient = new System.Windows.Forms.Button();
            this.buttonCancelRemoveIngredient = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // labelRemoveIngredient
            // 
            this.labelRemoveIngredient.AutoSize = true;
            this.labelRemoveIngredient.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.labelRemoveIngredient.Location = new System.Drawing.Point(22, 9);
            this.labelRemoveIngredient.Name = "labelRemoveIngredient";
            this.labelRemoveIngredient.Size = new System.Drawing.Size(224, 20);
            this.labelRemoveIngredient.TabIndex = 1;
            this.labelRemoveIngredient.Text = "Wybierz składnik do usunięcia:";
            // 
            // listBoxRemoveIngredient
            // 
            this.listBoxRemoveIngredient.FormattingEnabled = true;
            this.listBoxRemoveIngredient.Location = new System.Drawing.Point(69, 32);
            this.listBoxRemoveIngredient.Name = "listBoxRemoveIngredient";
            this.listBoxRemoveIngredient.Size = new System.Drawing.Size(135, 147);
            this.listBoxRemoveIngredient.TabIndex = 2;
            // 
            // buttonRemoveIngredient
            // 
            this.buttonRemoveIngredient.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.buttonRemoveIngredient.Location = new System.Drawing.Point(12, 185);
            this.buttonRemoveIngredient.Name = "buttonRemoveIngredient";
            this.buttonRemoveIngredient.Size = new System.Drawing.Size(107, 65);
            this.buttonRemoveIngredient.TabIndex = 3;
            this.buttonRemoveIngredient.Text = "Usuń";
            this.buttonRemoveIngredient.UseVisualStyleBackColor = true;
            this.buttonRemoveIngredient.Click += new System.EventHandler(this.buttonRemoveIngredient_Click);
            // 
            // buttonCancelRemoveIngredient
            // 
            this.buttonCancelRemoveIngredient.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.buttonCancelRemoveIngredient.Location = new System.Drawing.Point(155, 185);
            this.buttonCancelRemoveIngredient.Name = "buttonCancelRemoveIngredient";
            this.buttonCancelRemoveIngredient.Size = new System.Drawing.Size(107, 65);
            this.buttonCancelRemoveIngredient.TabIndex = 4;
            this.buttonCancelRemoveIngredient.Text = "Anuluj";
            this.buttonCancelRemoveIngredient.UseVisualStyleBackColor = true;
            this.buttonCancelRemoveIngredient.Click += new System.EventHandler(this.buttonCancelRemoveIngredient_Click);
            // 
            // FormRemoveIngredient
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(284, 262);
            this.Controls.Add(this.buttonCancelRemoveIngredient);
            this.Controls.Add(this.buttonRemoveIngredient);
            this.Controls.Add(this.listBoxRemoveIngredient);
            this.Controls.Add(this.labelRemoveIngredient);
            this.Name = "FormRemoveIngredient";
            this.Text = "Usuwanie składnika";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label labelRemoveIngredient;
        private System.Windows.Forms.ListBox listBoxRemoveIngredient;
        private System.Windows.Forms.Button buttonRemoveIngredient;
        private System.Windows.Forms.Button buttonCancelRemoveIngredient;
    }
}