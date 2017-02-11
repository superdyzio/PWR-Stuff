namespace DawidPerdekZad3.View
{
    partial class FormMainZad0
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
            this.dataGridViewDataFromDatabase = new System.Windows.Forms.DataGridView();
            this.labelChooseTable = new System.Windows.Forms.Label();
            this.buttonShowClients = new System.Windows.Forms.Button();
            this.buttonShowComputers = new System.Windows.Forms.Button();
            this.buttonShowEmployees = new System.Windows.Forms.Button();
            this.buttonShowServices = new System.Windows.Forms.Button();
            this.buttonShowServicesWithMinimalCost = new System.Windows.Forms.Button();
            this.textBoxMinimalServiceCost = new System.Windows.Forms.TextBox();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewDataFromDatabase)).BeginInit();
            this.SuspendLayout();
            // 
            // dataGridViewDataFromDatabase
            // 
            this.dataGridViewDataFromDatabase.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridViewDataFromDatabase.Location = new System.Drawing.Point(12, 12);
            this.dataGridViewDataFromDatabase.Name = "dataGridViewDataFromDatabase";
            this.dataGridViewDataFromDatabase.Size = new System.Drawing.Size(439, 304);
            this.dataGridViewDataFromDatabase.TabIndex = 0;
            // 
            // labelChooseTable
            // 
            this.labelChooseTable.AutoSize = true;
            this.labelChooseTable.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.labelChooseTable.Location = new System.Drawing.Point(520, 12);
            this.labelChooseTable.Name = "labelChooseTable";
            this.labelChooseTable.Size = new System.Drawing.Size(268, 24);
            this.labelChooseTable.TabIndex = 1;
            this.labelChooseTable.Text = "Wybierz dane do wyświetlenia:";
            // 
            // buttonShowClients
            // 
            this.buttonShowClients.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.buttonShowClients.Location = new System.Drawing.Point(572, 52);
            this.buttonShowClients.Name = "buttonShowClients";
            this.buttonShowClients.Size = new System.Drawing.Size(180, 40);
            this.buttonShowClients.TabIndex = 2;
            this.buttonShowClients.Text = "Klienci";
            this.buttonShowClients.UseVisualStyleBackColor = true;
            this.buttonShowClients.Click += new System.EventHandler(this.buttonShowClients_Click);
            // 
            // buttonShowComputers
            // 
            this.buttonShowComputers.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.buttonShowComputers.Location = new System.Drawing.Point(572, 98);
            this.buttonShowComputers.Name = "buttonShowComputers";
            this.buttonShowComputers.Size = new System.Drawing.Size(180, 40);
            this.buttonShowComputers.TabIndex = 3;
            this.buttonShowComputers.Text = "Komputery";
            this.buttonShowComputers.UseVisualStyleBackColor = true;
            this.buttonShowComputers.Click += new System.EventHandler(this.buttonShowComputers_Click);
            // 
            // buttonShowEmployees
            // 
            this.buttonShowEmployees.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.buttonShowEmployees.Location = new System.Drawing.Point(572, 144);
            this.buttonShowEmployees.Name = "buttonShowEmployees";
            this.buttonShowEmployees.Size = new System.Drawing.Size(180, 40);
            this.buttonShowEmployees.TabIndex = 4;
            this.buttonShowEmployees.Text = "Pracownicy";
            this.buttonShowEmployees.UseVisualStyleBackColor = true;
            this.buttonShowEmployees.Click += new System.EventHandler(this.buttonShowEmployees_Click);
            // 
            // buttonShowServices
            // 
            this.buttonShowServices.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.buttonShowServices.Location = new System.Drawing.Point(572, 190);
            this.buttonShowServices.Name = "buttonShowServices";
            this.buttonShowServices.Size = new System.Drawing.Size(180, 40);
            this.buttonShowServices.TabIndex = 5;
            this.buttonShowServices.Text = "Naprawy";
            this.buttonShowServices.UseVisualStyleBackColor = true;
            this.buttonShowServices.Click += new System.EventHandler(this.buttonShowServices_Click);
            // 
            // buttonShowServicesWithMinimalCost
            // 
            this.buttonShowServicesWithMinimalCost.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.buttonShowServicesWithMinimalCost.Location = new System.Drawing.Point(457, 254);
            this.buttonShowServicesWithMinimalCost.Name = "buttonShowServicesWithMinimalCost";
            this.buttonShowServicesWithMinimalCost.Size = new System.Drawing.Size(295, 40);
            this.buttonShowServicesWithMinimalCost.TabIndex = 6;
            this.buttonShowServicesWithMinimalCost.Text = "Naprawy o koszcie ponad:";
            this.buttonShowServicesWithMinimalCost.UseVisualStyleBackColor = true;
            this.buttonShowServicesWithMinimalCost.Click += new System.EventHandler(this.buttonShowServicesWithMinimalCost_Click);
            // 
            // textBoxMinimalServiceCost
            // 
            this.textBoxMinimalServiceCost.Location = new System.Drawing.Point(758, 267);
            this.textBoxMinimalServiceCost.Name = "textBoxMinimalServiceCost";
            this.textBoxMinimalServiceCost.Size = new System.Drawing.Size(100, 20);
            this.textBoxMinimalServiceCost.TabIndex = 7;
            this.textBoxMinimalServiceCost.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // FormMainZad0
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(879, 339);
            this.Controls.Add(this.textBoxMinimalServiceCost);
            this.Controls.Add(this.buttonShowServicesWithMinimalCost);
            this.Controls.Add(this.buttonShowServices);
            this.Controls.Add(this.buttonShowEmployees);
            this.Controls.Add(this.buttonShowComputers);
            this.Controls.Add(this.buttonShowClients);
            this.Controls.Add(this.labelChooseTable);
            this.Controls.Add(this.dataGridViewDataFromDatabase);
            this.Name = "FormMainZad0";
            this.Text = "Okno główne zadania 0";
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewDataFromDatabase)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataGridView dataGridViewDataFromDatabase;
        private System.Windows.Forms.Label labelChooseTable;
        private System.Windows.Forms.Button buttonShowClients;
        private System.Windows.Forms.Button buttonShowComputers;
        private System.Windows.Forms.Button buttonShowEmployees;
        private System.Windows.Forms.Button buttonShowServices;
        private System.Windows.Forms.Button buttonShowServicesWithMinimalCost;
        private System.Windows.Forms.TextBox textBoxMinimalServiceCost;
    }
}