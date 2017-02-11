namespace DawidPerdekLab3.View
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
            this.dataGridViewEmployees = new System.Windows.Forms.DataGridView();
            this.labelMyNameAndSurname = new System.Windows.Forms.Label();
            this.buttonGetEmployees = new System.Windows.Forms.Button();
            this.labelServiceCost = new System.Windows.Forms.Label();
            this.textBoxServiceCost = new System.Windows.Forms.TextBox();
            this.dataGridViewServices = new System.Windows.Forms.DataGridView();
            this.buttonGetServices = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewEmployees)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewServices)).BeginInit();
            this.SuspendLayout();
            // 
            // dataGridViewEmployees
            // 
            this.dataGridViewEmployees.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridViewEmployees.Location = new System.Drawing.Point(12, 81);
            this.dataGridViewEmployees.Name = "dataGridViewEmployees";
            this.dataGridViewEmployees.Size = new System.Drawing.Size(365, 195);
            this.dataGridViewEmployees.TabIndex = 0;
            // 
            // labelMyNameAndSurname
            // 
            this.labelMyNameAndSurname.AutoSize = true;
            this.labelMyNameAndSurname.Font = new System.Drawing.Font("Microsoft Sans Serif", 32F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.labelMyNameAndSurname.Location = new System.Drawing.Point(12, 9);
            this.labelMyNameAndSurname.Name = "labelMyNameAndSurname";
            this.labelMyNameAndSurname.Size = new System.Drawing.Size(302, 51);
            this.labelMyNameAndSurname.TabIndex = 1;
            this.labelMyNameAndSurname.Text = "Dawid Perdek";
            // 
            // buttonGetEmployees
            // 
            this.buttonGetEmployees.Location = new System.Drawing.Point(341, 9);
            this.buttonGetEmployees.Name = "buttonGetEmployees";
            this.buttonGetEmployees.Size = new System.Drawing.Size(146, 51);
            this.buttonGetEmployees.TabIndex = 2;
            this.buttonGetEmployees.Text = "Wyświetl pracowników";
            this.buttonGetEmployees.UseVisualStyleBackColor = true;
            this.buttonGetEmployees.Click += new System.EventHandler(this.buttonGetEmployees_Click);
            // 
            // labelServiceCost
            // 
            this.labelServiceCost.AutoSize = true;
            this.labelServiceCost.Location = new System.Drawing.Point(516, 107);
            this.labelServiceCost.Name = "labelServiceCost";
            this.labelServiceCost.Size = new System.Drawing.Size(122, 13);
            this.labelServiceCost.TabIndex = 3;
            this.labelServiceCost.Text = "Cena minimalna serwisu:";
            // 
            // textBoxServiceCost
            // 
            this.textBoxServiceCost.Location = new System.Drawing.Point(661, 99);
            this.textBoxServiceCost.Name = "textBoxServiceCost";
            this.textBoxServiceCost.Size = new System.Drawing.Size(167, 20);
            this.textBoxServiceCost.TabIndex = 4;
            // 
            // dataGridViewServices
            // 
            this.dataGridViewServices.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridViewServices.Location = new System.Drawing.Point(449, 173);
            this.dataGridViewServices.Name = "dataGridViewServices";
            this.dataGridViewServices.Size = new System.Drawing.Size(365, 195);
            this.dataGridViewServices.TabIndex = 5;
            // 
            // buttonGetServices
            // 
            this.buttonGetServices.Location = new System.Drawing.Point(630, 20);
            this.buttonGetServices.Name = "buttonGetServices";
            this.buttonGetServices.Size = new System.Drawing.Size(146, 51);
            this.buttonGetServices.TabIndex = 6;
            this.buttonGetServices.Text = "Wyświetl naprawy";
            this.buttonGetServices.UseVisualStyleBackColor = true;
            this.buttonGetServices.Click += new System.EventHandler(this.buttonGetServices_Click);
            // 
            // FormMain
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(846, 396);
            this.Controls.Add(this.buttonGetServices);
            this.Controls.Add(this.dataGridViewServices);
            this.Controls.Add(this.textBoxServiceCost);
            this.Controls.Add(this.labelServiceCost);
            this.Controls.Add(this.buttonGetEmployees);
            this.Controls.Add(this.labelMyNameAndSurname);
            this.Controls.Add(this.dataGridViewEmployees);
            this.Name = "FormMain";
            this.Text = "Okno główne";
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewEmployees)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewServices)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataGridView dataGridViewEmployees;
        private System.Windows.Forms.Label labelMyNameAndSurname;
        private System.Windows.Forms.Button buttonGetEmployees;
        private System.Windows.Forms.Label labelServiceCost;
        private System.Windows.Forms.TextBox textBoxServiceCost;
        private System.Windows.Forms.DataGridView dataGridViewServices;
        private System.Windows.Forms.Button buttonGetServices;
    }
}

