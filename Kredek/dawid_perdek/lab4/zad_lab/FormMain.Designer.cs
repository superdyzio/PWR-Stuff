namespace DawidPerdekLab4
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
            this.buttonAddNewStudent = new System.Windows.Forms.Button();
            this.labelMyNameAndSurname = new System.Windows.Forms.Label();
            this.dataGridViewStudents = new System.Windows.Forms.DataGridView();
            this.buttonShowStudents = new System.Windows.Forms.Button();
            this.textBoxStudentName = new System.Windows.Forms.TextBox();
            this.textBoxNewStudentName = new System.Windows.Forms.TextBox();
            this.textBoxNewStudentIndex = new System.Windows.Forms.TextBox();
            this.textBoxNewStudentSurname = new System.Windows.Forms.TextBox();
            this.groupBoxStudent = new System.Windows.Forms.GroupBox();
            this.groupBoxStudentAddress = new System.Windows.Forms.GroupBox();
            this.textBoxNewStudentCity = new System.Windows.Forms.TextBox();
            this.textBoxNewStudentPostCode = new System.Windows.Forms.TextBox();
            this.buttonShowAllStudents = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewStudents)).BeginInit();
            this.groupBoxStudent.SuspendLayout();
            this.groupBoxStudentAddress.SuspendLayout();
            this.SuspendLayout();
            // 
            // buttonAddNewStudent
            // 
            this.buttonAddNewStudent.Location = new System.Drawing.Point(140, 335);
            this.buttonAddNewStudent.Name = "buttonAddNewStudent";
            this.buttonAddNewStudent.Size = new System.Drawing.Size(104, 39);
            this.buttonAddNewStudent.TabIndex = 0;
            this.buttonAddNewStudent.Text = "Dodaj studenta";
            this.buttonAddNewStudent.UseVisualStyleBackColor = true;
            this.buttonAddNewStudent.Click += new System.EventHandler(this.buttonAddNewStudent_Click);
            // 
            // labelMyNameAndSurname
            // 
            this.labelMyNameAndSurname.AutoSize = true;
            this.labelMyNameAndSurname.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.labelMyNameAndSurname.Location = new System.Drawing.Point(300, 9);
            this.labelMyNameAndSurname.Name = "labelMyNameAndSurname";
            this.labelMyNameAndSurname.Size = new System.Drawing.Size(139, 24);
            this.labelMyNameAndSurname.TabIndex = 1;
            this.labelMyNameAndSurname.Text = "Dawid Perdek";
            // 
            // dataGridViewStudents
            // 
            this.dataGridViewStudents.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridViewStudents.Location = new System.Drawing.Point(16, 53);
            this.dataGridViewStudents.Name = "dataGridViewStudents";
            this.dataGridViewStudents.Size = new System.Drawing.Size(655, 248);
            this.dataGridViewStudents.TabIndex = 2;
            // 
            // buttonShowStudents
            // 
            this.buttonShowStudents.Location = new System.Drawing.Point(16, 328);
            this.buttonShowStudents.Name = "buttonShowStudents";
            this.buttonShowStudents.Size = new System.Drawing.Size(104, 39);
            this.buttonShowStudents.TabIndex = 3;
            this.buttonShowStudents.Text = "Pokaż studentów";
            this.buttonShowStudents.UseVisualStyleBackColor = true;
            this.buttonShowStudents.Click += new System.EventHandler(this.buttonShowStudents_Click);
            // 
            // textBoxStudentName
            // 
            this.textBoxStudentName.Location = new System.Drawing.Point(20, 380);
            this.textBoxStudentName.Name = "textBoxStudentName";
            this.textBoxStudentName.Size = new System.Drawing.Size(100, 20);
            this.textBoxStudentName.TabIndex = 5;
            // 
            // textBoxNewStudentName
            // 
            this.textBoxNewStudentName.Location = new System.Drawing.Point(6, 19);
            this.textBoxNewStudentName.Name = "textBoxNewStudentName";
            this.textBoxNewStudentName.Size = new System.Drawing.Size(104, 20);
            this.textBoxNewStudentName.TabIndex = 6;
            // 
            // textBoxNewStudentIndex
            // 
            this.textBoxNewStudentIndex.Location = new System.Drawing.Point(6, 71);
            this.textBoxNewStudentIndex.Name = "textBoxNewStudentIndex";
            this.textBoxNewStudentIndex.Size = new System.Drawing.Size(104, 20);
            this.textBoxNewStudentIndex.TabIndex = 7;
            // 
            // textBoxNewStudentSurname
            // 
            this.textBoxNewStudentSurname.Location = new System.Drawing.Point(6, 45);
            this.textBoxNewStudentSurname.Name = "textBoxNewStudentSurname";
            this.textBoxNewStudentSurname.Size = new System.Drawing.Size(104, 20);
            this.textBoxNewStudentSurname.TabIndex = 8;
            // 
            // groupBoxStudent
            // 
            this.groupBoxStudent.Controls.Add(this.textBoxNewStudentName);
            this.groupBoxStudent.Controls.Add(this.textBoxNewStudentSurname);
            this.groupBoxStudent.Controls.Add(this.textBoxNewStudentIndex);
            this.groupBoxStudent.Location = new System.Drawing.Point(250, 309);
            this.groupBoxStudent.Name = "groupBoxStudent";
            this.groupBoxStudent.Size = new System.Drawing.Size(119, 100);
            this.groupBoxStudent.TabIndex = 9;
            this.groupBoxStudent.TabStop = false;
            this.groupBoxStudent.Text = "Dane studenta";
            // 
            // groupBoxStudentAddress
            // 
            this.groupBoxStudentAddress.Controls.Add(this.textBoxNewStudentCity);
            this.groupBoxStudentAddress.Controls.Add(this.textBoxNewStudentPostCode);
            this.groupBoxStudentAddress.Location = new System.Drawing.Point(375, 309);
            this.groupBoxStudentAddress.Name = "groupBoxStudentAddress";
            this.groupBoxStudentAddress.Size = new System.Drawing.Size(119, 100);
            this.groupBoxStudentAddress.TabIndex = 10;
            this.groupBoxStudentAddress.TabStop = false;
            this.groupBoxStudentAddress.Text = "Adres";
            // 
            // textBoxNewStudentCity
            // 
            this.textBoxNewStudentCity.Location = new System.Drawing.Point(6, 19);
            this.textBoxNewStudentCity.Name = "textBoxNewStudentCity";
            this.textBoxNewStudentCity.Size = new System.Drawing.Size(104, 20);
            this.textBoxNewStudentCity.TabIndex = 6;
            // 
            // textBoxNewStudentPostCode
            // 
            this.textBoxNewStudentPostCode.Location = new System.Drawing.Point(6, 71);
            this.textBoxNewStudentPostCode.Name = "textBoxNewStudentPostCode";
            this.textBoxNewStudentPostCode.Size = new System.Drawing.Size(104, 20);
            this.textBoxNewStudentPostCode.TabIndex = 7;
            // 
            // buttonShowAllStudents
            // 
            this.buttonShowAllStudents.Location = new System.Drawing.Point(535, 318);
            this.buttonShowAllStudents.Name = "buttonShowAllStudents";
            this.buttonShowAllStudents.Size = new System.Drawing.Size(104, 39);
            this.buttonShowAllStudents.TabIndex = 11;
            this.buttonShowAllStudents.Text = "Pokaż wszystkich";
            this.buttonShowAllStudents.UseVisualStyleBackColor = true;
            this.buttonShowAllStudents.Click += new System.EventHandler(this.buttonShowAllStudents_Click);
            // 
            // FormMain
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(682, 435);
            this.Controls.Add(this.buttonShowAllStudents);
            this.Controls.Add(this.groupBoxStudentAddress);
            this.Controls.Add(this.groupBoxStudent);
            this.Controls.Add(this.textBoxStudentName);
            this.Controls.Add(this.buttonShowStudents);
            this.Controls.Add(this.dataGridViewStudents);
            this.Controls.Add(this.labelMyNameAndSurname);
            this.Controls.Add(this.buttonAddNewStudent);
            this.Name = "FormMain";
            this.Text = "Okno główne";
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewStudents)).EndInit();
            this.groupBoxStudent.ResumeLayout(false);
            this.groupBoxStudent.PerformLayout();
            this.groupBoxStudentAddress.ResumeLayout(false);
            this.groupBoxStudentAddress.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button buttonAddNewStudent;
        private System.Windows.Forms.Label labelMyNameAndSurname;
        private System.Windows.Forms.DataGridView dataGridViewStudents;
        private System.Windows.Forms.Button buttonShowStudents;
        private System.Windows.Forms.TextBox textBoxStudentName;
        private System.Windows.Forms.TextBox textBoxNewStudentName;
        private System.Windows.Forms.TextBox textBoxNewStudentIndex;
        private System.Windows.Forms.TextBox textBoxNewStudentSurname;
        private System.Windows.Forms.GroupBox groupBoxStudent;
        private System.Windows.Forms.GroupBox groupBoxStudentAddress;
        private System.Windows.Forms.TextBox textBoxNewStudentCity;
        private System.Windows.Forms.TextBox textBoxNewStudentPostCode;
        private System.Windows.Forms.Button buttonShowAllStudents;
    }
}

