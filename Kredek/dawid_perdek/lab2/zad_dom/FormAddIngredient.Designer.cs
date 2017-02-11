namespace DawidPerdekZad2
{
    partial class FormAddIngredient
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
            this.labelNewIngredientName = new System.Windows.Forms.Label();
            this.textBoxNewIngredientName = new System.Windows.Forms.TextBox();
            this.checkBoxNewIngredientIsMeat = new System.Windows.Forms.CheckBox();
            this.buttonAddNewIngredient = new System.Windows.Forms.Button();
            this.buttonCancelNewIngredient = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // labelNewIngredientName
            // 
            this.labelNewIngredientName.AutoSize = true;
            this.labelNewIngredientName.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.labelNewIngredientName.Location = new System.Drawing.Point(22, 26);
            this.labelNewIngredientName.Name = "labelNewIngredientName";
            this.labelNewIngredientName.Size = new System.Drawing.Size(192, 20);
            this.labelNewIngredientName.TabIndex = 0;
            this.labelNewIngredientName.Text = "Nazwa nowego składnika:";
            // 
            // textBoxNewIngredientName
            // 
            this.textBoxNewIngredientName.Location = new System.Drawing.Point(12, 67);
            this.textBoxNewIngredientName.Name = "textBoxNewIngredientName";
            this.textBoxNewIngredientName.Size = new System.Drawing.Size(260, 20);
            this.textBoxNewIngredientName.TabIndex = 1;
            // 
            // checkBoxNewIngredientIsMeat
            // 
            this.checkBoxNewIngredientIsMeat.AutoSize = true;
            this.checkBoxNewIngredientIsMeat.Location = new System.Drawing.Point(104, 117);
            this.checkBoxNewIngredientIsMeat.Name = "checkBoxNewIngredientIsMeat";
            this.checkBoxNewIngredientIsMeat.Size = new System.Drawing.Size(60, 17);
            this.checkBoxNewIngredientIsMeat.TabIndex = 2;
            this.checkBoxNewIngredientIsMeat.Text = "Mięso?";
            this.checkBoxNewIngredientIsMeat.UseVisualStyleBackColor = true;
            // 
            // buttonAddNewIngredient
            // 
            this.buttonAddNewIngredient.Font = new System.Drawing.Font("Microsoft Sans Serif", 16F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.buttonAddNewIngredient.Location = new System.Drawing.Point(12, 180);
            this.buttonAddNewIngredient.Name = "buttonAddNewIngredient";
            this.buttonAddNewIngredient.Size = new System.Drawing.Size(120, 50);
            this.buttonAddNewIngredient.TabIndex = 3;
            this.buttonAddNewIngredient.Text = "Dodaj";
            this.buttonAddNewIngredient.UseVisualStyleBackColor = true;
            this.buttonAddNewIngredient.Click += new System.EventHandler(this.buttonAddNewIngredient_Click);
            // 
            // buttonCancelNewIngredient
            // 
            this.buttonCancelNewIngredient.Font = new System.Drawing.Font("Microsoft Sans Serif", 16F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.buttonCancelNewIngredient.Location = new System.Drawing.Point(152, 180);
            this.buttonCancelNewIngredient.Name = "buttonCancelNewIngredient";
            this.buttonCancelNewIngredient.Size = new System.Drawing.Size(120, 50);
            this.buttonCancelNewIngredient.TabIndex = 4;
            this.buttonCancelNewIngredient.Text = "Anuluj";
            this.buttonCancelNewIngredient.UseVisualStyleBackColor = true;
            this.buttonCancelNewIngredient.Click += new System.EventHandler(this.buttonCancelNewIngredient_Click);
            // 
            // FormAddIngredient
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(284, 262);
            this.Controls.Add(this.buttonCancelNewIngredient);
            this.Controls.Add(this.buttonAddNewIngredient);
            this.Controls.Add(this.checkBoxNewIngredientIsMeat);
            this.Controls.Add(this.textBoxNewIngredientName);
            this.Controls.Add(this.labelNewIngredientName);
            this.Name = "FormAddIngredient";
            this.Text = "Dodawanie składnika";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label labelNewIngredientName;
        private System.Windows.Forms.TextBox textBoxNewIngredientName;
        private System.Windows.Forms.CheckBox checkBoxNewIngredientIsMeat;
        private System.Windows.Forms.Button buttonAddNewIngredient;
        private System.Windows.Forms.Button buttonCancelNewIngredient;
    }
}