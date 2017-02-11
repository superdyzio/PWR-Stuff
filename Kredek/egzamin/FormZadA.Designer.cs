namespace DawidPerdek
{
    partial class FormZadA
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
            this.dataGridViewNorthwind = new System.Windows.Forms.DataGridView();
            this.buttonSuppliers = new System.Windows.Forms.Button();
            this.buttonProducts = new System.Windows.Forms.Button();
            this.dataGridViewProductsAndSuppliers = new System.Windows.Forms.DataGridView();
            this.textBoxPrice = new System.Windows.Forms.TextBox();
            this.buttonPrices = new System.Windows.Forms.Button();
            this.textBoxChange = new System.Windows.Forms.TextBox();
            this.buttonPriceChange = new System.Windows.Forms.Button();
            this.buttonJoin = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewNorthwind)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewProductsAndSuppliers)).BeginInit();
            this.SuspendLayout();
            // 
            // dataGridViewNorthwind
            // 
            this.dataGridViewNorthwind.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridViewNorthwind.Location = new System.Drawing.Point(22, 156);
            this.dataGridViewNorthwind.Name = "dataGridViewNorthwind";
            this.dataGridViewNorthwind.Size = new System.Drawing.Size(349, 255);
            this.dataGridViewNorthwind.TabIndex = 0;
            // 
            // buttonSuppliers
            // 
            this.buttonSuppliers.Location = new System.Drawing.Point(22, 12);
            this.buttonSuppliers.Name = "buttonSuppliers";
            this.buttonSuppliers.Size = new System.Drawing.Size(90, 25);
            this.buttonSuppliers.TabIndex = 1;
            this.buttonSuppliers.Text = "A1 Dostawcy";
            this.buttonSuppliers.UseVisualStyleBackColor = true;
            this.buttonSuppliers.Click += new System.EventHandler(this.buttonSuppliers_Click);
            // 
            // buttonProducts
            // 
            this.buttonProducts.Location = new System.Drawing.Point(175, 12);
            this.buttonProducts.Name = "buttonProducts";
            this.buttonProducts.Size = new System.Drawing.Size(90, 25);
            this.buttonProducts.TabIndex = 2;
            this.buttonProducts.Text = "A1 Produkty";
            this.buttonProducts.UseVisualStyleBackColor = true;
            this.buttonProducts.Click += new System.EventHandler(this.buttonProducts_Click);
            // 
            // dataGridViewProductsAndSuppliers
            // 
            this.dataGridViewProductsAndSuppliers.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridViewProductsAndSuppliers.Location = new System.Drawing.Point(382, 156);
            this.dataGridViewProductsAndSuppliers.Name = "dataGridViewProductsAndSuppliers";
            this.dataGridViewProductsAndSuppliers.Size = new System.Drawing.Size(361, 255);
            this.dataGridViewProductsAndSuppliers.TabIndex = 3;
            // 
            // textBoxPrice
            // 
            this.textBoxPrice.Location = new System.Drawing.Point(175, 53);
            this.textBoxPrice.Name = "textBoxPrice";
            this.textBoxPrice.Size = new System.Drawing.Size(100, 20);
            this.textBoxPrice.TabIndex = 4;
            // 
            // buttonPrices
            // 
            this.buttonPrices.Location = new System.Drawing.Point(22, 48);
            this.buttonPrices.Name = "buttonPrices";
            this.buttonPrices.Size = new System.Drawing.Size(90, 25);
            this.buttonPrices.TabIndex = 5;
            this.buttonPrices.Text = "A.3 Ceny";
            this.buttonPrices.UseVisualStyleBackColor = true;
            this.buttonPrices.Click += new System.EventHandler(this.buttonPrices_Click);
            // 
            // textBoxChange
            // 
            this.textBoxChange.Location = new System.Drawing.Point(175, 95);
            this.textBoxChange.Name = "textBoxChange";
            this.textBoxChange.Size = new System.Drawing.Size(100, 20);
            this.textBoxChange.TabIndex = 6;
            // 
            // buttonPriceChange
            // 
            this.buttonPriceChange.Location = new System.Drawing.Point(22, 92);
            this.buttonPriceChange.Name = "buttonPriceChange";
            this.buttonPriceChange.Size = new System.Drawing.Size(90, 25);
            this.buttonPriceChange.TabIndex = 7;
            this.buttonPriceChange.Text = "A.4 Zmiana";
            this.buttonPriceChange.UseVisualStyleBackColor = true;
            this.buttonPriceChange.Click += new System.EventHandler(this.buttonPriceChange_Click);
            // 
            // buttonJoin
            // 
            this.buttonJoin.Location = new System.Drawing.Point(511, 95);
            this.buttonJoin.Name = "buttonJoin";
            this.buttonJoin.Size = new System.Drawing.Size(90, 25);
            this.buttonJoin.TabIndex = 8;
            this.buttonJoin.Text = "A.2 Join";
            this.buttonJoin.UseVisualStyleBackColor = true;
            this.buttonJoin.Click += new System.EventHandler(this.buttonJoin_Click);
            // 
            // FormZadA
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(810, 472);
            this.Controls.Add(this.buttonJoin);
            this.Controls.Add(this.buttonPriceChange);
            this.Controls.Add(this.textBoxChange);
            this.Controls.Add(this.buttonPrices);
            this.Controls.Add(this.textBoxPrice);
            this.Controls.Add(this.dataGridViewProductsAndSuppliers);
            this.Controls.Add(this.buttonProducts);
            this.Controls.Add(this.buttonSuppliers);
            this.Controls.Add(this.dataGridViewNorthwind);
            this.Name = "FormZadA";
            this.Text = "FormZadA";
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewNorthwind)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewProductsAndSuppliers)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataGridView dataGridViewNorthwind;
        private System.Windows.Forms.Button buttonSuppliers;
        private System.Windows.Forms.Button buttonProducts;
        private System.Windows.Forms.DataGridView dataGridViewProductsAndSuppliers;
        private System.Windows.Forms.TextBox textBoxPrice;
        private System.Windows.Forms.Button buttonPrices;
        private System.Windows.Forms.TextBox textBoxChange;
        private System.Windows.Forms.Button buttonPriceChange;
        private System.Windows.Forms.Button buttonJoin;
    }
}