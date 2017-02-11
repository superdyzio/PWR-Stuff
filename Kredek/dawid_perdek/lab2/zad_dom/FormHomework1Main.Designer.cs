namespace DawidPerdekZad2
{
    partial class FormHomework1Main
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
            this.dataGridViewListOfMeals = new System.Windows.Forms.DataGridView();
            this.labelListOfMeals = new System.Windows.Forms.Label();
            this.labelMealIngredients = new System.Windows.Forms.Label();
            this.textBoxIngredients = new System.Windows.Forms.TextBox();
            this.pictureBoxMealPhoto = new System.Windows.Forms.PictureBox();
            this.labelMealsChangesIndicator = new System.Windows.Forms.Label();
            this.buttonMealsSaveFile = new System.Windows.Forms.Button();
            this.buttonMealsOpenFile = new System.Windows.Forms.Button();
            this.buttonAddIngredient = new System.Windows.Forms.Button();
            this.buttonAddMeal = new System.Windows.Forms.Button();
            this.buttonRemoveMeal = new System.Windows.Forms.Button();
            this.buttonRemoveIngredient = new System.Windows.Forms.Button();
            this.textBoxMealDescription = new System.Windows.Forms.TextBox();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewListOfMeals)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxMealPhoto)).BeginInit();
            this.SuspendLayout();
            // 
            // dataGridViewListOfMeals
            // 
            this.dataGridViewListOfMeals.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridViewListOfMeals.Location = new System.Drawing.Point(12, 38);
            this.dataGridViewListOfMeals.Name = "dataGridViewListOfMeals";
            this.dataGridViewListOfMeals.ReadOnly = true;
            this.dataGridViewListOfMeals.Size = new System.Drawing.Size(506, 317);
            this.dataGridViewListOfMeals.TabIndex = 0;
            this.dataGridViewListOfMeals.CurrentCellChanged += new System.EventHandler(this.dataGridViewListOfMeals_CurrentCellChanged);
            // 
            // labelListOfMeals
            // 
            this.labelListOfMeals.AutoSize = true;
            this.labelListOfMeals.Font = new System.Drawing.Font("Microsoft Sans Serif", 16F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.labelListOfMeals.Location = new System.Drawing.Point(93, 9);
            this.labelListOfMeals.Name = "labelListOfMeals";
            this.labelListOfMeals.Size = new System.Drawing.Size(88, 26);
            this.labelListOfMeals.TabIndex = 1;
            this.labelListOfMeals.Text = "MENU:";
            // 
            // labelMealIngredients
            // 
            this.labelMealIngredients.AutoSize = true;
            this.labelMealIngredients.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.labelMealIngredients.Location = new System.Drawing.Point(524, 38);
            this.labelMealIngredients.Name = "labelMealIngredients";
            this.labelMealIngredients.Size = new System.Drawing.Size(77, 20);
            this.labelMealIngredients.TabIndex = 2;
            this.labelMealIngredients.Text = "Składniki:";
            // 
            // textBoxIngredients
            // 
            this.textBoxIngredients.Location = new System.Drawing.Point(607, 40);
            this.textBoxIngredients.Multiline = true;
            this.textBoxIngredients.Name = "textBoxIngredients";
            this.textBoxIngredients.ReadOnly = true;
            this.textBoxIngredients.Size = new System.Drawing.Size(215, 80);
            this.textBoxIngredients.TabIndex = 3;
            // 
            // pictureBoxMealPhoto
            // 
            this.pictureBoxMealPhoto.Location = new System.Drawing.Point(528, 146);
            this.pictureBoxMealPhoto.Name = "pictureBoxMealPhoto";
            this.pictureBoxMealPhoto.Size = new System.Drawing.Size(294, 166);
            this.pictureBoxMealPhoto.TabIndex = 4;
            this.pictureBoxMealPhoto.TabStop = false;
            // 
            // labelMealsChangesIndicator
            // 
            this.labelMealsChangesIndicator.AutoSize = true;
            this.labelMealsChangesIndicator.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.labelMealsChangesIndicator.Location = new System.Drawing.Point(613, 474);
            this.labelMealsChangesIndicator.Name = "labelMealsChangesIndicator";
            this.labelMealsChangesIndicator.Size = new System.Drawing.Size(200, 13);
            this.labelMealsChangesIndicator.TabIndex = 12;
            this.labelMealsChangesIndicator.Text = "ISTNIEJĄ NIEZAPISANE ZMIANY";
            // 
            // buttonMealsSaveFile
            // 
            this.buttonMealsSaveFile.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.buttonMealsSaveFile.Location = new System.Drawing.Point(399, 433);
            this.buttonMealsSaveFile.Name = "buttonMealsSaveFile";
            this.buttonMealsSaveFile.Size = new System.Drawing.Size(100, 30);
            this.buttonMealsSaveFile.TabIndex = 11;
            this.buttonMealsSaveFile.Text = "Zapisz";
            this.buttonMealsSaveFile.UseVisualStyleBackColor = true;
            this.buttonMealsSaveFile.Click += new System.EventHandler(this.buttonMealsSaveFile_Click);
            // 
            // buttonMealsOpenFile
            // 
            this.buttonMealsOpenFile.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.buttonMealsOpenFile.Location = new System.Drawing.Point(399, 377);
            this.buttonMealsOpenFile.Name = "buttonMealsOpenFile";
            this.buttonMealsOpenFile.Size = new System.Drawing.Size(100, 30);
            this.buttonMealsOpenFile.TabIndex = 10;
            this.buttonMealsOpenFile.Text = "Wczytaj";
            this.buttonMealsOpenFile.UseVisualStyleBackColor = true;
            this.buttonMealsOpenFile.Click += new System.EventHandler(this.buttonMealsOpenFile_Click);
            // 
            // buttonAddIngredient
            // 
            this.buttonAddIngredient.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.buttonAddIngredient.Location = new System.Drawing.Point(222, 361);
            this.buttonAddIngredient.Name = "buttonAddIngredient";
            this.buttonAddIngredient.Size = new System.Drawing.Size(120, 60);
            this.buttonAddIngredient.TabIndex = 14;
            this.buttonAddIngredient.Text = "Dodaj składnik";
            this.buttonAddIngredient.UseVisualStyleBackColor = true;
            this.buttonAddIngredient.Click += new System.EventHandler(this.buttonAddIngredient_Click);
            // 
            // buttonAddMeal
            // 
            this.buttonAddMeal.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.buttonAddMeal.Location = new System.Drawing.Point(12, 361);
            this.buttonAddMeal.Name = "buttonAddMeal";
            this.buttonAddMeal.Size = new System.Drawing.Size(120, 60);
            this.buttonAddMeal.TabIndex = 13;
            this.buttonAddMeal.Text = "Dodaj posiłek";
            this.buttonAddMeal.UseVisualStyleBackColor = true;
            this.buttonAddMeal.Click += new System.EventHandler(this.buttonAddMeal_Click);
            // 
            // buttonRemoveMeal
            // 
            this.buttonRemoveMeal.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.buttonRemoveMeal.Location = new System.Drawing.Point(12, 433);
            this.buttonRemoveMeal.Name = "buttonRemoveMeal";
            this.buttonRemoveMeal.Size = new System.Drawing.Size(120, 60);
            this.buttonRemoveMeal.TabIndex = 15;
            this.buttonRemoveMeal.Text = "Usuń posiłek";
            this.buttonRemoveMeal.UseVisualStyleBackColor = true;
            this.buttonRemoveMeal.Click += new System.EventHandler(this.buttonRemoveMeal_Click);
            // 
            // buttonRemoveIngredient
            // 
            this.buttonRemoveIngredient.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.buttonRemoveIngredient.Location = new System.Drawing.Point(222, 427);
            this.buttonRemoveIngredient.Name = "buttonRemoveIngredient";
            this.buttonRemoveIngredient.Size = new System.Drawing.Size(120, 60);
            this.buttonRemoveIngredient.TabIndex = 16;
            this.buttonRemoveIngredient.Text = "Usuń składnik";
            this.buttonRemoveIngredient.UseVisualStyleBackColor = true;
            this.buttonRemoveIngredient.Click += new System.EventHandler(this.buttonRemoveIngredient_Click);
            // 
            // textBoxMealDescription
            // 
            this.textBoxMealDescription.Location = new System.Drawing.Point(528, 350);
            this.textBoxMealDescription.Multiline = true;
            this.textBoxMealDescription.Name = "textBoxMealDescription";
            this.textBoxMealDescription.ReadOnly = true;
            this.textBoxMealDescription.Size = new System.Drawing.Size(295, 107);
            this.textBoxMealDescription.TabIndex = 17;
            // 
            // FormHomework1Main
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(834, 497);
            this.Controls.Add(this.textBoxMealDescription);
            this.Controls.Add(this.buttonRemoveIngredient);
            this.Controls.Add(this.buttonRemoveMeal);
            this.Controls.Add(this.buttonAddIngredient);
            this.Controls.Add(this.buttonAddMeal);
            this.Controls.Add(this.labelMealsChangesIndicator);
            this.Controls.Add(this.buttonMealsSaveFile);
            this.Controls.Add(this.buttonMealsOpenFile);
            this.Controls.Add(this.pictureBoxMealPhoto);
            this.Controls.Add(this.textBoxIngredients);
            this.Controls.Add(this.labelMealIngredients);
            this.Controls.Add(this.labelListOfMeals);
            this.Controls.Add(this.dataGridViewListOfMeals);
            this.Name = "FormHomework1Main";
            this.Text = "Okno główne zadania 1";
            this.Activated += new System.EventHandler(this.FormHomework1Main_Activated);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewListOfMeals)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxMealPhoto)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataGridView dataGridViewListOfMeals;
        private System.Windows.Forms.Label labelListOfMeals;
        private System.Windows.Forms.Label labelMealIngredients;
        private System.Windows.Forms.TextBox textBoxIngredients;
        private System.Windows.Forms.PictureBox pictureBoxMealPhoto;
        private System.Windows.Forms.Label labelMealsChangesIndicator;
        private System.Windows.Forms.Button buttonMealsSaveFile;
        private System.Windows.Forms.Button buttonMealsOpenFile;
        private System.Windows.Forms.Button buttonAddIngredient;
        private System.Windows.Forms.Button buttonAddMeal;
        private System.Windows.Forms.Button buttonRemoveMeal;
        private System.Windows.Forms.Button buttonRemoveIngredient;
        private System.Windows.Forms.TextBox textBoxMealDescription;
    }
}