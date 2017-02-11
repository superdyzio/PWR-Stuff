namespace DawidPerdekZad2
{
    partial class FormAddingPersonGrade
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
            this.labelPersonName = new System.Windows.Forms.Label();
            this.labelNewGradeValue = new System.Windows.Forms.Label();
            this.labelNewGradeName = new System.Windows.Forms.Label();
            this.textBoxNewGradeValue = new System.Windows.Forms.TextBox();
            this.textBoxNewGradeName = new System.Windows.Forms.TextBox();
            this.buttonConfirmGrade = new System.Windows.Forms.Button();
            this.buttonCancelGrade = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // labelPersonName
            // 
            this.labelPersonName.AutoSize = true;
            this.labelPersonName.Font = new System.Drawing.Font("Microsoft Sans Serif", 16F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.labelPersonName.Location = new System.Drawing.Point(12, 21);
            this.labelPersonName.Name = "labelPersonName";
            this.labelPersonName.Size = new System.Drawing.Size(0, 26);
            this.labelPersonName.TabIndex = 0;
            // 
            // labelNewGradeValue
            // 
            this.labelNewGradeValue.AutoSize = true;
            this.labelNewGradeValue.Location = new System.Drawing.Point(25, 77);
            this.labelNewGradeValue.Name = "labelNewGradeValue";
            this.labelNewGradeValue.Size = new System.Drawing.Size(42, 13);
            this.labelNewGradeValue.TabIndex = 1;
            this.labelNewGradeValue.Text = "Ocena:";
            // 
            // labelNewGradeName
            // 
            this.labelNewGradeName.AutoSize = true;
            this.labelNewGradeName.Location = new System.Drawing.Point(36, 107);
            this.labelNewGradeName.Name = "labelNewGradeName";
            this.labelNewGradeName.Size = new System.Drawing.Size(31, 13);
            this.labelNewGradeName.TabIndex = 2;
            this.labelNewGradeName.Text = "Opis:";
            // 
            // textBoxNewGradeValue
            // 
            this.textBoxNewGradeValue.Location = new System.Drawing.Point(105, 74);
            this.textBoxNewGradeValue.Name = "textBoxNewGradeValue";
            this.textBoxNewGradeValue.Size = new System.Drawing.Size(130, 20);
            this.textBoxNewGradeValue.TabIndex = 3;
            this.textBoxNewGradeValue.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // textBoxNewGradeName
            // 
            this.textBoxNewGradeName.Location = new System.Drawing.Point(105, 107);
            this.textBoxNewGradeName.Name = "textBoxNewGradeName";
            this.textBoxNewGradeName.Size = new System.Drawing.Size(130, 20);
            this.textBoxNewGradeName.TabIndex = 4;
            this.textBoxNewGradeName.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // buttonConfirmGrade
            // 
            this.buttonConfirmGrade.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.buttonConfirmGrade.Location = new System.Drawing.Point(12, 170);
            this.buttonConfirmGrade.Name = "buttonConfirmGrade";
            this.buttonConfirmGrade.Size = new System.Drawing.Size(100, 80);
            this.buttonConfirmGrade.TabIndex = 5;
            this.buttonConfirmGrade.Text = "Zatwierdź";
            this.buttonConfirmGrade.UseVisualStyleBackColor = true;
            this.buttonConfirmGrade.Click += new System.EventHandler(this.buttonConfirmGrade_Click);
            // 
            // buttonCancelGrade
            // 
            this.buttonCancelGrade.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.buttonCancelGrade.Location = new System.Drawing.Point(160, 170);
            this.buttonCancelGrade.Name = "buttonCancelGrade";
            this.buttonCancelGrade.Size = new System.Drawing.Size(100, 80);
            this.buttonCancelGrade.TabIndex = 6;
            this.buttonCancelGrade.Text = "Anuluj";
            this.buttonCancelGrade.UseVisualStyleBackColor = true;
            this.buttonCancelGrade.Click += new System.EventHandler(this.buttonCancelGrade_Click);
            // 
            // FormAddingPersonGrade
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(284, 262);
            this.Controls.Add(this.buttonCancelGrade);
            this.Controls.Add(this.buttonConfirmGrade);
            this.Controls.Add(this.textBoxNewGradeName);
            this.Controls.Add(this.textBoxNewGradeValue);
            this.Controls.Add(this.labelNewGradeName);
            this.Controls.Add(this.labelNewGradeValue);
            this.Controls.Add(this.labelPersonName);
            this.Name = "FormAddingPersonGrade";
            this.Text = "Dodawanie oceny";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label labelPersonName;
        private System.Windows.Forms.Label labelNewGradeValue;
        private System.Windows.Forms.Label labelNewGradeName;
        private System.Windows.Forms.TextBox textBoxNewGradeValue;
        private System.Windows.Forms.TextBox textBoxNewGradeName;
        private System.Windows.Forms.Button buttonConfirmGrade;
        private System.Windows.Forms.Button buttonCancelGrade;
    }
}