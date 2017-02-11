namespace DawidPerdekZad2
{
    partial class FormAddingPerson
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
            this.textBoxNewPersonName = new System.Windows.Forms.TextBox();
            this.textBoxNewPersonSurname = new System.Windows.Forms.TextBox();
            this.textBoxNewPersonAge = new System.Windows.Forms.TextBox();
            this.labelNewPersonName = new System.Windows.Forms.Label();
            this.labelNewPersonSurname = new System.Windows.Forms.Label();
            this.labelNewPersonAge = new System.Windows.Forms.Label();
            this.buttonConfirmPerson = new System.Windows.Forms.Button();
            this.buttonCancelPerson = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // textBoxNewPersonName
            // 
            this.textBoxNewPersonName.Location = new System.Drawing.Point(148, 28);
            this.textBoxNewPersonName.Name = "textBoxNewPersonName";
            this.textBoxNewPersonName.Size = new System.Drawing.Size(124, 20);
            this.textBoxNewPersonName.TabIndex = 0;
            // 
            // textBoxNewPersonSurname
            // 
            this.textBoxNewPersonSurname.Location = new System.Drawing.Point(148, 80);
            this.textBoxNewPersonSurname.Name = "textBoxNewPersonSurname";
            this.textBoxNewPersonSurname.Size = new System.Drawing.Size(124, 20);
            this.textBoxNewPersonSurname.TabIndex = 1;
            // 
            // textBoxNewPersonAge
            // 
            this.textBoxNewPersonAge.Location = new System.Drawing.Point(148, 130);
            this.textBoxNewPersonAge.Name = "textBoxNewPersonAge";
            this.textBoxNewPersonAge.Size = new System.Drawing.Size(124, 20);
            this.textBoxNewPersonAge.TabIndex = 2;
            // 
            // labelNewPersonName
            // 
            this.labelNewPersonName.AutoSize = true;
            this.labelNewPersonName.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.labelNewPersonName.Location = new System.Drawing.Point(12, 28);
            this.labelNewPersonName.Name = "labelNewPersonName";
            this.labelNewPersonName.Size = new System.Drawing.Size(85, 20);
            this.labelNewPersonName.TabIndex = 3;
            this.labelNewPersonName.Text = "Podaj imię:";
            // 
            // labelNewPersonSurname
            // 
            this.labelNewPersonSurname.AutoSize = true;
            this.labelNewPersonSurname.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.labelNewPersonSurname.Location = new System.Drawing.Point(12, 80);
            this.labelNewPersonSurname.Name = "labelNewPersonSurname";
            this.labelNewPersonSurname.Size = new System.Drawing.Size(122, 20);
            this.labelNewPersonSurname.TabIndex = 4;
            this.labelNewPersonSurname.Text = "Podaj nazwisko:";
            // 
            // labelNewPersonAge
            // 
            this.labelNewPersonAge.AutoSize = true;
            this.labelNewPersonAge.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.labelNewPersonAge.Location = new System.Drawing.Point(12, 128);
            this.labelNewPersonAge.Name = "labelNewPersonAge";
            this.labelNewPersonAge.Size = new System.Drawing.Size(88, 20);
            this.labelNewPersonAge.TabIndex = 5;
            this.labelNewPersonAge.Text = "Podaj wiek:";
            // 
            // buttonConfirmPerson
            // 
            this.buttonConfirmPerson.Location = new System.Drawing.Point(12, 199);
            this.buttonConfirmPerson.Name = "buttonConfirmPerson";
            this.buttonConfirmPerson.Size = new System.Drawing.Size(100, 40);
            this.buttonConfirmPerson.TabIndex = 6;
            this.buttonConfirmPerson.Text = "Zatwierdź";
            this.buttonConfirmPerson.UseVisualStyleBackColor = true;
            this.buttonConfirmPerson.Click += new System.EventHandler(this.buttonConfirmPerson_Click);
            // 
            // buttonCancelPerson
            // 
            this.buttonCancelPerson.Location = new System.Drawing.Point(172, 199);
            this.buttonCancelPerson.Name = "buttonCancelPerson";
            this.buttonCancelPerson.Size = new System.Drawing.Size(100, 40);
            this.buttonCancelPerson.TabIndex = 7;
            this.buttonCancelPerson.Text = "Anuluj";
            this.buttonCancelPerson.UseVisualStyleBackColor = true;
            this.buttonCancelPerson.Click += new System.EventHandler(this.buttonCancelPerson_Click);
            // 
            // FormAddingPerson
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(284, 262);
            this.Controls.Add(this.buttonCancelPerson);
            this.Controls.Add(this.buttonConfirmPerson);
            this.Controls.Add(this.labelNewPersonAge);
            this.Controls.Add(this.labelNewPersonSurname);
            this.Controls.Add(this.labelNewPersonName);
            this.Controls.Add(this.textBoxNewPersonAge);
            this.Controls.Add(this.textBoxNewPersonSurname);
            this.Controls.Add(this.textBoxNewPersonName);
            this.Name = "FormAddingPerson";
            this.Text = "Dodawanie osoby";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox textBoxNewPersonName;
        private System.Windows.Forms.TextBox textBoxNewPersonSurname;
        private System.Windows.Forms.TextBox textBoxNewPersonAge;
        private System.Windows.Forms.Label labelNewPersonName;
        private System.Windows.Forms.Label labelNewPersonSurname;
        private System.Windows.Forms.Label labelNewPersonAge;
        private System.Windows.Forms.Button buttonConfirmPerson;
        private System.Windows.Forms.Button buttonCancelPerson;
    }
}