namespace DawidPerdekZad2
{
    partial class FormAddingMeal
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
            this.listBoxNewMealType = new System.Windows.Forms.ListBox();
            this.labelNewMealType = new System.Windows.Forms.Label();
            this.labelNewMealName = new System.Windows.Forms.Label();
            this.labelNewMealPrice = new System.Windows.Forms.Label();
            this.textBoxNewMealName = new System.Windows.Forms.TextBox();
            this.textBoxNewMealPrice = new System.Windows.Forms.TextBox();
            this.labelNewMealWeight = new System.Windows.Forms.Label();
            this.labelNewMealDescription = new System.Windows.Forms.Label();
            this.textBoxNewMealWeight = new System.Windows.Forms.TextBox();
            this.textBoxNewMealDescription = new System.Windows.Forms.TextBox();
            this.listBoxNewMealIngredients = new System.Windows.Forms.ListBox();
            this.labelNewMealIngredients = new System.Windows.Forms.Label();
            this.labelNewMealPhoto = new System.Windows.Forms.Label();
            this.textBoxNewMealPhoto = new System.Windows.Forms.TextBox();
            this.pictureBoxNewMealPicture = new System.Windows.Forms.PictureBox();
            this.buttonConfirmMealAdding = new System.Windows.Forms.Button();
            this.buttonCancelMealAdding = new System.Windows.Forms.Button();
            this.labelNewBurgerLevel = new System.Windows.Forms.Label();
            this.listBoxNewBurgerLevel = new System.Windows.Forms.ListBox();
            this.labelNewPastaType = new System.Windows.Forms.Label();
            this.listBoxNewPastaType = new System.Windows.Forms.ListBox();
            this.checkBoxNewPizzaThickCrust = new System.Windows.Forms.CheckBox();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxNewMealPicture)).BeginInit();
            this.SuspendLayout();
            // 
            // listBoxNewMealType
            // 
            this.listBoxNewMealType.FormattingEnabled = true;
            this.listBoxNewMealType.Location = new System.Drawing.Point(110, 12);
            this.listBoxNewMealType.Name = "listBoxNewMealType";
            this.listBoxNewMealType.Size = new System.Drawing.Size(120, 30);
            this.listBoxNewMealType.TabIndex = 0;
            this.listBoxNewMealType.SelectedIndexChanged += new System.EventHandler(this.listBoxNewMealType_SelectedIndexChanged);
            // 
            // labelNewMealType
            // 
            this.labelNewMealType.AutoSize = true;
            this.labelNewMealType.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.labelNewMealType.Location = new System.Drawing.Point(12, 12);
            this.labelNewMealType.Name = "labelNewMealType";
            this.labelNewMealType.Size = new System.Drawing.Size(92, 20);
            this.labelNewMealType.TabIndex = 1;
            this.labelNewMealType.Text = "Typ posiłku:";
            // 
            // labelNewMealName
            // 
            this.labelNewMealName.AutoSize = true;
            this.labelNewMealName.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.labelNewMealName.Location = new System.Drawing.Point(43, 55);
            this.labelNewMealName.Name = "labelNewMealName";
            this.labelNewMealName.Size = new System.Drawing.Size(61, 20);
            this.labelNewMealName.TabIndex = 2;
            this.labelNewMealName.Text = "Nazwa:";
            // 
            // labelNewMealPrice
            // 
            this.labelNewMealPrice.AutoSize = true;
            this.labelNewMealPrice.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.labelNewMealPrice.Location = new System.Drawing.Point(53, 94);
            this.labelNewMealPrice.Name = "labelNewMealPrice";
            this.labelNewMealPrice.Size = new System.Drawing.Size(51, 20);
            this.labelNewMealPrice.TabIndex = 3;
            this.labelNewMealPrice.Text = "Cena:";
            // 
            // textBoxNewMealName
            // 
            this.textBoxNewMealName.Location = new System.Drawing.Point(110, 57);
            this.textBoxNewMealName.Name = "textBoxNewMealName";
            this.textBoxNewMealName.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.textBoxNewMealName.Size = new System.Drawing.Size(120, 20);
            this.textBoxNewMealName.TabIndex = 4;
            this.textBoxNewMealName.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // textBoxNewMealPrice
            // 
            this.textBoxNewMealPrice.Location = new System.Drawing.Point(110, 96);
            this.textBoxNewMealPrice.Name = "textBoxNewMealPrice";
            this.textBoxNewMealPrice.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.textBoxNewMealPrice.Size = new System.Drawing.Size(120, 20);
            this.textBoxNewMealPrice.TabIndex = 5;
            this.textBoxNewMealPrice.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // labelNewMealWeight
            // 
            this.labelNewMealWeight.AutoSize = true;
            this.labelNewMealWeight.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.labelNewMealWeight.Location = new System.Drawing.Point(277, 12);
            this.labelNewMealWeight.Name = "labelNewMealWeight";
            this.labelNewMealWeight.Size = new System.Drawing.Size(55, 20);
            this.labelNewMealWeight.TabIndex = 6;
            this.labelNewMealWeight.Text = "Waga:";
            // 
            // labelNewMealDescription
            // 
            this.labelNewMealDescription.AutoSize = true;
            this.labelNewMealDescription.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.labelNewMealDescription.Location = new System.Drawing.Point(287, 55);
            this.labelNewMealDescription.Name = "labelNewMealDescription";
            this.labelNewMealDescription.Size = new System.Drawing.Size(45, 20);
            this.labelNewMealDescription.TabIndex = 7;
            this.labelNewMealDescription.Text = "Opis:";
            // 
            // textBoxNewMealWeight
            // 
            this.textBoxNewMealWeight.Location = new System.Drawing.Point(357, 12);
            this.textBoxNewMealWeight.Name = "textBoxNewMealWeight";
            this.textBoxNewMealWeight.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.textBoxNewMealWeight.Size = new System.Drawing.Size(168, 20);
            this.textBoxNewMealWeight.TabIndex = 8;
            this.textBoxNewMealWeight.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // textBoxNewMealDescription
            // 
            this.textBoxNewMealDescription.Location = new System.Drawing.Point(357, 55);
            this.textBoxNewMealDescription.Multiline = true;
            this.textBoxNewMealDescription.Name = "textBoxNewMealDescription";
            this.textBoxNewMealDescription.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.textBoxNewMealDescription.Size = new System.Drawing.Size(168, 59);
            this.textBoxNewMealDescription.TabIndex = 9;
            this.textBoxNewMealDescription.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // listBoxNewMealIngredients
            // 
            this.listBoxNewMealIngredients.FormattingEnabled = true;
            this.listBoxNewMealIngredients.Location = new System.Drawing.Point(110, 159);
            this.listBoxNewMealIngredients.Name = "listBoxNewMealIngredients";
            this.listBoxNewMealIngredients.SelectionMode = System.Windows.Forms.SelectionMode.MultiSimple;
            this.listBoxNewMealIngredients.Size = new System.Drawing.Size(170, 147);
            this.listBoxNewMealIngredients.TabIndex = 10;
            // 
            // labelNewMealIngredients
            // 
            this.labelNewMealIngredients.AutoSize = true;
            this.labelNewMealIngredients.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.labelNewMealIngredients.Location = new System.Drawing.Point(27, 159);
            this.labelNewMealIngredients.Name = "labelNewMealIngredients";
            this.labelNewMealIngredients.Size = new System.Drawing.Size(77, 20);
            this.labelNewMealIngredients.TabIndex = 11;
            this.labelNewMealIngredients.Text = "Składniki:";
            // 
            // labelNewMealPhoto
            // 
            this.labelNewMealPhoto.AutoSize = true;
            this.labelNewMealPhoto.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.labelNewMealPhoto.Location = new System.Drawing.Point(334, 136);
            this.labelNewMealPhoto.Name = "labelNewMealPhoto";
            this.labelNewMealPhoto.Size = new System.Drawing.Size(114, 20);
            this.labelNewMealPhoto.TabIndex = 12;
            this.labelNewMealPhoto.Text = "Nazwa zdjęcia:";
            // 
            // textBoxNewMealPhoto
            // 
            this.textBoxNewMealPhoto.Location = new System.Drawing.Point(357, 169);
            this.textBoxNewMealPhoto.Name = "textBoxNewMealPhoto";
            this.textBoxNewMealPhoto.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.textBoxNewMealPhoto.Size = new System.Drawing.Size(168, 20);
            this.textBoxNewMealPhoto.TabIndex = 13;
            this.textBoxNewMealPhoto.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.textBoxNewMealPhoto.Leave += new System.EventHandler(this.textBoxNewMealPhoto_Leave);
            // 
            // pictureBoxNewMealPicture
            // 
            this.pictureBoxNewMealPicture.Location = new System.Drawing.Point(357, 211);
            this.pictureBoxNewMealPicture.Name = "pictureBoxNewMealPicture";
            this.pictureBoxNewMealPicture.Size = new System.Drawing.Size(168, 95);
            this.pictureBoxNewMealPicture.TabIndex = 14;
            this.pictureBoxNewMealPicture.TabStop = false;
            // 
            // buttonConfirmMealAdding
            // 
            this.buttonConfirmMealAdding.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.buttonConfirmMealAdding.Location = new System.Drawing.Point(31, 339);
            this.buttonConfirmMealAdding.Name = "buttonConfirmMealAdding";
            this.buttonConfirmMealAdding.Size = new System.Drawing.Size(120, 60);
            this.buttonConfirmMealAdding.TabIndex = 15;
            this.buttonConfirmMealAdding.Text = "Dodaj";
            this.buttonConfirmMealAdding.UseVisualStyleBackColor = true;
            this.buttonConfirmMealAdding.Click += new System.EventHandler(this.buttonConfirmMealAdding_Click);
            // 
            // buttonCancelMealAdding
            // 
            this.buttonCancelMealAdding.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.buttonCancelMealAdding.Location = new System.Drawing.Point(201, 339);
            this.buttonCancelMealAdding.Name = "buttonCancelMealAdding";
            this.buttonCancelMealAdding.Size = new System.Drawing.Size(120, 60);
            this.buttonCancelMealAdding.TabIndex = 16;
            this.buttonCancelMealAdding.Text = "Anuluj";
            this.buttonCancelMealAdding.UseVisualStyleBackColor = true;
            this.buttonCancelMealAdding.Click += new System.EventHandler(this.buttonCancelMealAdding_Click);
            // 
            // labelNewBurgerLevel
            // 
            this.labelNewBurgerLevel.AutoSize = true;
            this.labelNewBurgerLevel.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.labelNewBurgerLevel.Location = new System.Drawing.Point(353, 327);
            this.labelNewBurgerLevel.Name = "labelNewBurgerLevel";
            this.labelNewBurgerLevel.Size = new System.Drawing.Size(158, 20);
            this.labelNewBurgerLevel.TabIndex = 17;
            this.labelNewBurgerLevel.Text = "Stopień wysmażenia:";
            // 
            // listBoxNewBurgerLevel
            // 
            this.listBoxNewBurgerLevel.FormattingEnabled = true;
            this.listBoxNewBurgerLevel.Location = new System.Drawing.Point(357, 350);
            this.listBoxNewBurgerLevel.Name = "listBoxNewBurgerLevel";
            this.listBoxNewBurgerLevel.Size = new System.Drawing.Size(154, 30);
            this.listBoxNewBurgerLevel.TabIndex = 18;
            // 
            // labelNewPastaType
            // 
            this.labelNewPastaType.AutoSize = true;
            this.labelNewPastaType.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.labelNewPastaType.Location = new System.Drawing.Point(363, 327);
            this.labelNewPastaType.Name = "labelNewPastaType";
            this.labelNewPastaType.Size = new System.Drawing.Size(138, 20);
            this.labelNewPastaType.TabIndex = 19;
            this.labelNewPastaType.Text = "Rodzaj makaronu:";
            // 
            // listBoxNewPastaType
            // 
            this.listBoxNewPastaType.FormattingEnabled = true;
            this.listBoxNewPastaType.Location = new System.Drawing.Point(357, 350);
            this.listBoxNewPastaType.Name = "listBoxNewPastaType";
            this.listBoxNewPastaType.Size = new System.Drawing.Size(154, 30);
            this.listBoxNewPastaType.TabIndex = 20;
            // 
            // checkBoxNewPizzaThickCrust
            // 
            this.checkBoxNewPizzaThickCrust.AutoSize = true;
            this.checkBoxNewPizzaThickCrust.Location = new System.Drawing.Point(382, 350);
            this.checkBoxNewPizzaThickCrust.Name = "checkBoxNewPizzaThickCrust";
            this.checkBoxNewPizzaThickCrust.Size = new System.Drawing.Size(86, 17);
            this.checkBoxNewPizzaThickCrust.TabIndex = 22;
            this.checkBoxNewPizzaThickCrust.Text = "Grube ciasto";
            this.checkBoxNewPizzaThickCrust.UseVisualStyleBackColor = true;
            // 
            // FormAddingMeal
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(544, 412);
            this.Controls.Add(this.checkBoxNewPizzaThickCrust);
            this.Controls.Add(this.listBoxNewPastaType);
            this.Controls.Add(this.labelNewPastaType);
            this.Controls.Add(this.listBoxNewBurgerLevel);
            this.Controls.Add(this.labelNewBurgerLevel);
            this.Controls.Add(this.buttonCancelMealAdding);
            this.Controls.Add(this.buttonConfirmMealAdding);
            this.Controls.Add(this.pictureBoxNewMealPicture);
            this.Controls.Add(this.textBoxNewMealPhoto);
            this.Controls.Add(this.labelNewMealPhoto);
            this.Controls.Add(this.labelNewMealIngredients);
            this.Controls.Add(this.listBoxNewMealIngredients);
            this.Controls.Add(this.textBoxNewMealDescription);
            this.Controls.Add(this.textBoxNewMealWeight);
            this.Controls.Add(this.labelNewMealDescription);
            this.Controls.Add(this.labelNewMealWeight);
            this.Controls.Add(this.textBoxNewMealPrice);
            this.Controls.Add(this.textBoxNewMealName);
            this.Controls.Add(this.labelNewMealPrice);
            this.Controls.Add(this.labelNewMealName);
            this.Controls.Add(this.labelNewMealType);
            this.Controls.Add(this.listBoxNewMealType);
            this.Name = "FormAddingMeal";
            this.Text = "Dodawanie posiłku";
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxNewMealPicture)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ListBox listBoxNewMealType;
        private System.Windows.Forms.Label labelNewMealType;
        private System.Windows.Forms.Label labelNewMealName;
        private System.Windows.Forms.Label labelNewMealPrice;
        private System.Windows.Forms.TextBox textBoxNewMealName;
        private System.Windows.Forms.TextBox textBoxNewMealPrice;
        private System.Windows.Forms.Label labelNewMealWeight;
        private System.Windows.Forms.Label labelNewMealDescription;
        private System.Windows.Forms.TextBox textBoxNewMealWeight;
        private System.Windows.Forms.TextBox textBoxNewMealDescription;
        private System.Windows.Forms.ListBox listBoxNewMealIngredients;
        private System.Windows.Forms.Label labelNewMealIngredients;
        private System.Windows.Forms.Label labelNewMealPhoto;
        private System.Windows.Forms.TextBox textBoxNewMealPhoto;
        private System.Windows.Forms.PictureBox pictureBoxNewMealPicture;
        private System.Windows.Forms.Button buttonConfirmMealAdding;
        private System.Windows.Forms.Button buttonCancelMealAdding;
        private System.Windows.Forms.Label labelNewBurgerLevel;
        private System.Windows.Forms.ListBox listBoxNewBurgerLevel;
        private System.Windows.Forms.Label labelNewPastaType;
        private System.Windows.Forms.ListBox listBoxNewPastaType;
        private System.Windows.Forms.CheckBox checkBoxNewPizzaThickCrust;
    }
}