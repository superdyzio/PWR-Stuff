namespace DawidPerdekLab2
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
            this.labelMyNameAndSurname = new System.Windows.Forms.Label();
            this.buttonShowPerson = new System.Windows.Forms.Button();
            this.buttonShowHiperPerson = new System.Windows.Forms.Button();
            this.dataGridViewListOfPeople = new System.Windows.Forms.DataGridView();
            this.textBoxNewPersonName = new System.Windows.Forms.TextBox();
            this.textBoxNewPersonSurname = new System.Windows.Forms.TextBox();
            this.textBoxNewPersonAge = new System.Windows.Forms.TextBox();
            this.buttonShow = new System.Windows.Forms.Button();
            this.buttonAddPerson = new System.Windows.Forms.Button();
            this.labelListOfPeople = new System.Windows.Forms.Label();
            this.dataGridViewGrades = new System.Windows.Forms.DataGridView();
            this.labelGrades = new System.Windows.Forms.Label();
            this.textBoxGrade = new System.Windows.Forms.TextBox();
            this.buttonAddGrade = new System.Windows.Forms.Button();
            this.pictureBoxGrades = new System.Windows.Forms.PictureBox();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewListOfPeople)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewGrades)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxGrades)).BeginInit();
            this.SuspendLayout();
            // 
            // labelMyNameAndSurname
            // 
            this.labelMyNameAndSurname.AutoSize = true;
            this.labelMyNameAndSurname.Font = new System.Drawing.Font("Microsoft Sans Serif", 24F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.labelMyNameAndSurname.ForeColor = System.Drawing.SystemColors.HotTrack;
            this.labelMyNameAndSurname.Location = new System.Drawing.Point(21, 9);
            this.labelMyNameAndSurname.Name = "labelMyNameAndSurname";
            this.labelMyNameAndSurname.Size = new System.Drawing.Size(227, 37);
            this.labelMyNameAndSurname.TabIndex = 0;
            this.labelMyNameAndSurname.Text = "Dawid Perdek";
            // 
            // buttonShowPerson
            // 
            this.buttonShowPerson.Location = new System.Drawing.Point(400, 6);
            this.buttonShowPerson.Name = "buttonShowPerson";
            this.buttonShowPerson.Size = new System.Drawing.Size(150, 40);
            this.buttonShowPerson.TabIndex = 1;
            this.buttonShowPerson.Text = "Pokaż dane osoby";
            this.buttonShowPerson.UseVisualStyleBackColor = true;
            this.buttonShowPerson.Click += new System.EventHandler(this.buttonShowPerson_Click);
            // 
            // buttonShowHiperPerson
            // 
            this.buttonShowHiperPerson.Location = new System.Drawing.Point(592, 6);
            this.buttonShowHiperPerson.Name = "buttonShowHiperPerson";
            this.buttonShowHiperPerson.Size = new System.Drawing.Size(150, 40);
            this.buttonShowHiperPerson.TabIndex = 2;
            this.buttonShowHiperPerson.Text = "Pokaż dane hiperosoby";
            this.buttonShowHiperPerson.UseVisualStyleBackColor = true;
            this.buttonShowHiperPerson.Click += new System.EventHandler(this.buttonShowHiperPerson_Click);
            // 
            // dataGridViewListOfPeople
            // 
            this.dataGridViewListOfPeople.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridViewListOfPeople.Location = new System.Drawing.Point(28, 110);
            this.dataGridViewListOfPeople.Name = "dataGridViewListOfPeople";
            this.dataGridViewListOfPeople.Size = new System.Drawing.Size(347, 267);
            this.dataGridViewListOfPeople.TabIndex = 3;
            // 
            // textBoxNewPersonName
            // 
            this.textBoxNewPersonName.Location = new System.Drawing.Point(400, 73);
            this.textBoxNewPersonName.Name = "textBoxNewPersonName";
            this.textBoxNewPersonName.Size = new System.Drawing.Size(150, 20);
            this.textBoxNewPersonName.TabIndex = 4;
            // 
            // textBoxNewPersonSurname
            // 
            this.textBoxNewPersonSurname.Location = new System.Drawing.Point(400, 110);
            this.textBoxNewPersonSurname.Name = "textBoxNewPersonSurname";
            this.textBoxNewPersonSurname.Size = new System.Drawing.Size(150, 20);
            this.textBoxNewPersonSurname.TabIndex = 5;
            // 
            // textBoxNewPersonAge
            // 
            this.textBoxNewPersonAge.Location = new System.Drawing.Point(400, 146);
            this.textBoxNewPersonAge.Name = "textBoxNewPersonAge";
            this.textBoxNewPersonAge.Size = new System.Drawing.Size(150, 20);
            this.textBoxNewPersonAge.TabIndex = 6;
            // 
            // buttonShow
            // 
            this.buttonShow.Location = new System.Drawing.Point(592, 62);
            this.buttonShow.Name = "buttonShow";
            this.buttonShow.Size = new System.Drawing.Size(150, 40);
            this.buttonShow.TabIndex = 7;
            this.buttonShow.Text = "Wyświetl";
            this.buttonShow.UseVisualStyleBackColor = true;
            this.buttonShow.Click += new System.EventHandler(this.buttonShow_Click);
            // 
            // buttonAddPerson
            // 
            this.buttonAddPerson.Location = new System.Drawing.Point(592, 126);
            this.buttonAddPerson.Name = "buttonAddPerson";
            this.buttonAddPerson.Size = new System.Drawing.Size(150, 40);
            this.buttonAddPerson.TabIndex = 8;
            this.buttonAddPerson.Text = "Dodaj osobę";
            this.buttonAddPerson.UseVisualStyleBackColor = true;
            this.buttonAddPerson.Click += new System.EventHandler(this.buttonAddPerson_Click);
            // 
            // labelListOfPeople
            // 
            this.labelListOfPeople.AutoSize = true;
            this.labelListOfPeople.Location = new System.Drawing.Point(25, 80);
            this.labelListOfPeople.Name = "labelListOfPeople";
            this.labelListOfPeople.Size = new System.Drawing.Size(56, 13);
            this.labelListOfPeople.TabIndex = 9;
            this.labelListOfPeople.Text = "Lista ludzi:";
            // 
            // dataGridViewGrades
            // 
            this.dataGridViewGrades.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridViewGrades.Location = new System.Drawing.Point(400, 215);
            this.dataGridViewGrades.Name = "dataGridViewGrades";
            this.dataGridViewGrades.Size = new System.Drawing.Size(238, 162);
            this.dataGridViewGrades.TabIndex = 10;
            // 
            // labelGrades
            // 
            this.labelGrades.AutoSize = true;
            this.labelGrades.Location = new System.Drawing.Point(397, 197);
            this.labelGrades.Name = "labelGrades";
            this.labelGrades.Size = new System.Drawing.Size(41, 13);
            this.labelGrades.TabIndex = 11;
            this.labelGrades.Text = "Oceny:";
            // 
            // textBoxGrade
            // 
            this.textBoxGrade.Location = new System.Drawing.Point(400, 403);
            this.textBoxGrade.Name = "textBoxGrade";
            this.textBoxGrade.Size = new System.Drawing.Size(150, 20);
            this.textBoxGrade.TabIndex = 12;
            // 
            // buttonAddGrade
            // 
            this.buttonAddGrade.Location = new System.Drawing.Point(592, 392);
            this.buttonAddGrade.Name = "buttonAddGrade";
            this.buttonAddGrade.Size = new System.Drawing.Size(150, 40);
            this.buttonAddGrade.TabIndex = 13;
            this.buttonAddGrade.Text = "Dodaj ocenę";
            this.buttonAddGrade.UseVisualStyleBackColor = true;
            this.buttonAddGrade.Click += new System.EventHandler(this.buttonAddGrade_Click);
            // 
            // pictureBoxGrades
            // 
            this.pictureBoxGrades.Location = new System.Drawing.Point(644, 215);
            this.pictureBoxGrades.Name = "pictureBoxGrades";
            this.pictureBoxGrades.Size = new System.Drawing.Size(128, 109);
            this.pictureBoxGrades.TabIndex = 14;
            this.pictureBoxGrades.TabStop = false;
            // 
            // FormMain
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(784, 462);
            this.Controls.Add(this.pictureBoxGrades);
            this.Controls.Add(this.buttonAddGrade);
            this.Controls.Add(this.textBoxGrade);
            this.Controls.Add(this.labelGrades);
            this.Controls.Add(this.dataGridViewGrades);
            this.Controls.Add(this.labelListOfPeople);
            this.Controls.Add(this.buttonAddPerson);
            this.Controls.Add(this.buttonShow);
            this.Controls.Add(this.textBoxNewPersonAge);
            this.Controls.Add(this.textBoxNewPersonSurname);
            this.Controls.Add(this.textBoxNewPersonName);
            this.Controls.Add(this.dataGridViewListOfPeople);
            this.Controls.Add(this.buttonShowHiperPerson);
            this.Controls.Add(this.buttonShowPerson);
            this.Controls.Add(this.labelMyNameAndSurname);
            this.Name = "FormMain";
            this.Text = "FormMain";
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewListOfPeople)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewGrades)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxGrades)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label labelMyNameAndSurname;
        private System.Windows.Forms.Button buttonShowPerson;
        private System.Windows.Forms.Button buttonShowHiperPerson;
        private System.Windows.Forms.DataGridView dataGridViewListOfPeople;
        private System.Windows.Forms.TextBox textBoxNewPersonName;
        private System.Windows.Forms.TextBox textBoxNewPersonSurname;
        private System.Windows.Forms.TextBox textBoxNewPersonAge;
        private System.Windows.Forms.Button buttonShow;
        private System.Windows.Forms.Button buttonAddPerson;
        private System.Windows.Forms.Label labelListOfPeople;
        private System.Windows.Forms.DataGridView dataGridViewGrades;
        private System.Windows.Forms.Label labelGrades;
        private System.Windows.Forms.TextBox textBoxGrade;
        private System.Windows.Forms.Button buttonAddGrade;
        private System.Windows.Forms.PictureBox pictureBoxGrades;
    }
}

