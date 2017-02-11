namespace DawidPerdekZad2
{
    partial class FormHomework0Main
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
            this.labelListOfPeople = new System.Windows.Forms.Label();
            this.dataGridViewListOfPeople = new System.Windows.Forms.DataGridView();
            this.labelListOfGrades = new System.Windows.Forms.Label();
            this.dataGridViewListOfGrades = new System.Windows.Forms.DataGridView();
            this.buttonAddPerson = new System.Windows.Forms.Button();
            this.buttonAddGrade = new System.Windows.Forms.Button();
            this.buttonPersonOpenFile = new System.Windows.Forms.Button();
            this.buttonPersonSaveFile = new System.Windows.Forms.Button();
            this.labelPersonChangesIndicator = new System.Windows.Forms.Label();
            this.pictureBoxFace = new System.Windows.Forms.PictureBox();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewListOfPeople)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewListOfGrades)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxFace)).BeginInit();
            this.SuspendLayout();
            // 
            // labelListOfPeople
            // 
            this.labelListOfPeople.AutoSize = true;
            this.labelListOfPeople.Font = new System.Drawing.Font("Microsoft Sans Serif", 16F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.labelListOfPeople.Location = new System.Drawing.Point(12, 9);
            this.labelListOfPeople.Name = "labelListOfPeople";
            this.labelListOfPeople.Size = new System.Drawing.Size(115, 26);
            this.labelListOfPeople.TabIndex = 0;
            this.labelListOfPeople.Text = "Lista ludzi:";
            // 
            // dataGridViewListOfPeople
            // 
            this.dataGridViewListOfPeople.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridViewListOfPeople.Location = new System.Drawing.Point(12, 38);
            this.dataGridViewListOfPeople.Name = "dataGridViewListOfPeople";
            this.dataGridViewListOfPeople.Size = new System.Drawing.Size(250, 235);
            this.dataGridViewListOfPeople.TabIndex = 1;
            this.dataGridViewListOfPeople.CurrentCellChanged += new System.EventHandler(this.dataGridViewListOfPeople_CurrentCellChanged);
            // 
            // labelListOfGrades
            // 
            this.labelListOfGrades.AutoSize = true;
            this.labelListOfGrades.Font = new System.Drawing.Font("Microsoft Sans Serif", 16F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.labelListOfGrades.Location = new System.Drawing.Point(346, 9);
            this.labelListOfGrades.Name = "labelListOfGrades";
            this.labelListOfGrades.Size = new System.Drawing.Size(117, 26);
            this.labelListOfGrades.TabIndex = 2;
            this.labelListOfGrades.Text = "Lista ocen:";
            // 
            // dataGridViewListOfGrades
            // 
            this.dataGridViewListOfGrades.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridViewListOfGrades.Location = new System.Drawing.Point(314, 38);
            this.dataGridViewListOfGrades.Name = "dataGridViewListOfGrades";
            this.dataGridViewListOfGrades.Size = new System.Drawing.Size(235, 169);
            this.dataGridViewListOfGrades.TabIndex = 3;
            // 
            // buttonAddPerson
            // 
            this.buttonAddPerson.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.buttonAddPerson.Location = new System.Drawing.Point(12, 286);
            this.buttonAddPerson.Name = "buttonAddPerson";
            this.buttonAddPerson.Size = new System.Drawing.Size(120, 80);
            this.buttonAddPerson.TabIndex = 5;
            this.buttonAddPerson.Text = "Dodaj osobę";
            this.buttonAddPerson.UseVisualStyleBackColor = true;
            this.buttonAddPerson.Click += new System.EventHandler(this.buttonAddPerson_Click);
            // 
            // buttonAddGrade
            // 
            this.buttonAddGrade.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.buttonAddGrade.Location = new System.Drawing.Point(142, 285);
            this.buttonAddGrade.Name = "buttonAddGrade";
            this.buttonAddGrade.Size = new System.Drawing.Size(120, 80);
            this.buttonAddGrade.TabIndex = 6;
            this.buttonAddGrade.Text = "Dodaj ocenę";
            this.buttonAddGrade.UseVisualStyleBackColor = true;
            this.buttonAddGrade.Click += new System.EventHandler(this.buttonAddGrade_Click);
            // 
            // buttonPersonOpenFile
            // 
            this.buttonPersonOpenFile.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.buttonPersonOpenFile.Location = new System.Drawing.Point(472, 243);
            this.buttonPersonOpenFile.Name = "buttonPersonOpenFile";
            this.buttonPersonOpenFile.Size = new System.Drawing.Size(100, 30);
            this.buttonPersonOpenFile.TabIndex = 7;
            this.buttonPersonOpenFile.Text = "Wczytaj";
            this.buttonPersonOpenFile.UseVisualStyleBackColor = true;
            this.buttonPersonOpenFile.Click += new System.EventHandler(this.buttonPersonOpenFile_Click);
            // 
            // buttonPersonSaveFile
            // 
            this.buttonPersonSaveFile.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.buttonPersonSaveFile.Location = new System.Drawing.Point(472, 301);
            this.buttonPersonSaveFile.Name = "buttonPersonSaveFile";
            this.buttonPersonSaveFile.Size = new System.Drawing.Size(100, 30);
            this.buttonPersonSaveFile.TabIndex = 8;
            this.buttonPersonSaveFile.Text = "Zapisz";
            this.buttonPersonSaveFile.UseVisualStyleBackColor = true;
            this.buttonPersonSaveFile.Click += new System.EventHandler(this.buttonPersonSaveFile_Click);
            // 
            // labelPersonChangesIndicator
            // 
            this.labelPersonChangesIndicator.AutoSize = true;
            this.labelPersonChangesIndicator.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.labelPersonChangesIndicator.Location = new System.Drawing.Point(281, 346);
            this.labelPersonChangesIndicator.Name = "labelPersonChangesIndicator";
            this.labelPersonChangesIndicator.Size = new System.Drawing.Size(200, 13);
            this.labelPersonChangesIndicator.TabIndex = 9;
            this.labelPersonChangesIndicator.Text = "ISTNIEJĄ NIEZAPISANE ZMIANY";
            // 
            // pictureBoxFace
            // 
            this.pictureBoxFace.Location = new System.Drawing.Point(314, 223);
            this.pictureBoxFace.Name = "pictureBoxFace";
            this.pictureBoxFace.Size = new System.Drawing.Size(134, 96);
            this.pictureBoxFace.TabIndex = 4;
            this.pictureBoxFace.TabStop = false;
            // 
            // FormHomework0Main
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(584, 377);
            this.Controls.Add(this.labelPersonChangesIndicator);
            this.Controls.Add(this.buttonPersonSaveFile);
            this.Controls.Add(this.buttonPersonOpenFile);
            this.Controls.Add(this.buttonAddGrade);
            this.Controls.Add(this.buttonAddPerson);
            this.Controls.Add(this.pictureBoxFace);
            this.Controls.Add(this.dataGridViewListOfGrades);
            this.Controls.Add(this.labelListOfGrades);
            this.Controls.Add(this.dataGridViewListOfPeople);
            this.Controls.Add(this.labelListOfPeople);
            this.Name = "FormHomework0Main";
            this.Text = "Okno główne zadania 0";
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewListOfPeople)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewListOfGrades)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxFace)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label labelListOfPeople;
        private System.Windows.Forms.DataGridView dataGridViewListOfPeople;
        private System.Windows.Forms.Label labelListOfGrades;
        private System.Windows.Forms.DataGridView dataGridViewListOfGrades;
        private System.Windows.Forms.PictureBox pictureBoxFace;
        private System.Windows.Forms.Button buttonAddPerson;
        private System.Windows.Forms.Button buttonAddGrade;
        private System.Windows.Forms.Button buttonPersonOpenFile;
        private System.Windows.Forms.Button buttonPersonSaveFile;
        private System.Windows.Forms.Label labelPersonChangesIndicator;
    }
}