namespace DawidPerdekZad3.View
{
    partial class FormMainZad1
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
            this.listBoxDatabaseTableChoosing = new System.Windows.Forms.ListBox();
            this.dataGridViewFirstTable = new System.Windows.Forms.DataGridView();
            this.dataGridViewSecondTable = new System.Windows.Forms.DataGridView();
            this.labelAllTableColumnsDisplay = new System.Windows.Forms.Label();
            this.labelOtherQueries = new System.Windows.Forms.Label();
            this.buttonDeliverersWithoutCar = new System.Windows.Forms.Button();
            this.buttonDelivererDeliveries = new System.Windows.Forms.Button();
            this.buttonFillLeftDataGridView = new System.Windows.Forms.Button();
            this.buttonFillRightDataGridView = new System.Windows.Forms.Button();
            this.textBoxDelivererSpecifyID = new System.Windows.Forms.TextBox();
            this.checkBoxFillingRightTable = new System.Windows.Forms.CheckBox();
            this.buttonSuppliesWithManagers = new System.Windows.Forms.Button();
            this.buttonSuppliesAfterDate = new System.Windows.Forms.Button();
            this.dateTimePickerSupplySpecifyDate = new System.Windows.Forms.DateTimePicker();
            this.buttonDeliveriesWithDeliverers = new System.Windows.Forms.Button();
            this.buttonDeliveriesFurtherThan = new System.Windows.Forms.Button();
            this.textBoxDeliverySpecifyDistance = new System.Windows.Forms.TextBox();
            this.buttonWaitersWithTotalTips = new System.Windows.Forms.Button();
            this.buttonWaitersWithTransactionsCount = new System.Windows.Forms.Button();
            this.buttonWaitersWithTransactionsTotalCost = new System.Windows.Forms.Button();
            this.buttonClientTransactionsTotalCost = new System.Windows.Forms.Button();
            this.buttonClientDeliveriesCount = new System.Windows.Forms.Button();
            this.buttonCookWithMeals = new System.Windows.Forms.Button();
            this.textBoxSpecifyCookIDForMeals = new System.Windows.Forms.TextBox();
            this.buttonCooksWithShoppings = new System.Windows.Forms.Button();
            this.textBoxSpecifyCookIDForShoppings = new System.Windows.Forms.TextBox();
            this.buttonManagersYoungerThan30 = new System.Windows.Forms.Button();
            this.buttonManagersEmployees = new System.Windows.Forms.Button();
            this.textBoxSpecifyManagerID = new System.Windows.Forms.TextBox();
            this.buttonMealWithSpecifiedName = new System.Windows.Forms.Button();
            this.buttonMealsWithSpecifiedCategory = new System.Windows.Forms.Button();
            this.textBoxSpecifyMealName = new System.Windows.Forms.TextBox();
            this.textBoxSpecifyMealCategory = new System.Windows.Forms.TextBox();
            this.buttonMealsFromSpecifiedCategory = new System.Windows.Forms.Button();
            this.textBoxMealCategorySpecifyName = new System.Windows.Forms.TextBox();
            this.buttonCarsWithDeliverers = new System.Windows.Forms.Button();
            this.buttonTransactionsMoreExpensiveThan100 = new System.Windows.Forms.Button();
            this.buttonTipsGreaterThan10 = new System.Windows.Forms.Button();
            this.buttonShoppingsBeforeDate = new System.Windows.Forms.Button();
            this.dateTimePickerSpecifyShoppingDate = new System.Windows.Forms.DateTimePicker();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewFirstTable)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewSecondTable)).BeginInit();
            this.SuspendLayout();
            // 
            // listBoxDatabaseTableChoosing
            // 
            this.listBoxDatabaseTableChoosing.FormattingEnabled = true;
            this.listBoxDatabaseTableChoosing.Items.AddRange(new object[] {
            "Dowoziciele",
            "Dostawy towarów",
            "Dowozy",
            "Kelnerzy",
            "Klienci",
            "Kucharze",
            "Managerowie",
            "Posiłki",
            "Rodzaje posiłków",
            "Samochody dostawcze",
            "Zakupy towarów",
            "Zamówienia"});
            this.listBoxDatabaseTableChoosing.Location = new System.Drawing.Point(12, 24);
            this.listBoxDatabaseTableChoosing.Name = "listBoxDatabaseTableChoosing";
            this.listBoxDatabaseTableChoosing.Size = new System.Drawing.Size(191, 43);
            this.listBoxDatabaseTableChoosing.TabIndex = 2;
            this.listBoxDatabaseTableChoosing.SelectedIndexChanged += new System.EventHandler(this.listBoxDatabaseTableChoosing_SelectedIndexChanged);
            // 
            // dataGridViewFirstTable
            // 
            this.dataGridViewFirstTable.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridViewFirstTable.Location = new System.Drawing.Point(12, 78);
            this.dataGridViewFirstTable.Name = "dataGridViewFirstTable";
            this.dataGridViewFirstTable.Size = new System.Drawing.Size(550, 350);
            this.dataGridViewFirstTable.TabIndex = 3;
            // 
            // dataGridViewSecondTable
            // 
            this.dataGridViewSecondTable.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridViewSecondTable.Location = new System.Drawing.Point(618, 78);
            this.dataGridViewSecondTable.Name = "dataGridViewSecondTable";
            this.dataGridViewSecondTable.Size = new System.Drawing.Size(550, 350);
            this.dataGridViewSecondTable.TabIndex = 4;
            // 
            // labelAllTableColumnsDisplay
            // 
            this.labelAllTableColumnsDisplay.AutoSize = true;
            this.labelAllTableColumnsDisplay.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.labelAllTableColumnsDisplay.Location = new System.Drawing.Point(12, 8);
            this.labelAllTableColumnsDisplay.Name = "labelAllTableColumnsDisplay";
            this.labelAllTableColumnsDisplay.Size = new System.Drawing.Size(191, 13);
            this.labelAllTableColumnsDisplay.TabIndex = 5;
            this.labelAllTableColumnsDisplay.Text = "Wyświetlanie kompletnych tabeli";
            // 
            // labelOtherQueries
            // 
            this.labelOtherQueries.AutoSize = true;
            this.labelOtherQueries.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.labelOtherQueries.Location = new System.Drawing.Point(352, 8);
            this.labelOtherQueries.Name = "labelOtherQueries";
            this.labelOtherQueries.Size = new System.Drawing.Size(94, 13);
            this.labelOtherQueries.TabIndex = 6;
            this.labelOtherQueries.Text = "Inne zapytania:";
            // 
            // buttonDeliverersWithoutCar
            // 
            this.buttonDeliverersWithoutCar.Location = new System.Drawing.Point(412, 33);
            this.buttonDeliverersWithoutCar.Name = "buttonDeliverersWithoutCar";
            this.buttonDeliverersWithoutCar.Size = new System.Drawing.Size(150, 30);
            this.buttonDeliverersWithoutCar.TabIndex = 7;
            this.buttonDeliverersWithoutCar.Text = "Dowoziciele bez auta";
            this.buttonDeliverersWithoutCar.UseVisualStyleBackColor = true;
            this.buttonDeliverersWithoutCar.Click += new System.EventHandler(this.buttonDeliverersWithoutCar_Click);
            // 
            // buttonDelivererDeliveries
            // 
            this.buttonDelivererDeliveries.Location = new System.Drawing.Point(618, 33);
            this.buttonDelivererDeliveries.Name = "buttonDelivererDeliveries";
            this.buttonDelivererDeliveries.Size = new System.Drawing.Size(150, 30);
            this.buttonDelivererDeliveries.TabIndex = 8;
            this.buttonDelivererDeliveries.Text = "Dowozy dowoziciela o ID:";
            this.buttonDelivererDeliveries.UseVisualStyleBackColor = true;
            this.buttonDelivererDeliveries.Click += new System.EventHandler(this.buttonDelivererDeliveries_Click);
            // 
            // buttonFillLeftDataGridView
            // 
            this.buttonFillLeftDataGridView.Location = new System.Drawing.Point(209, 22);
            this.buttonFillLeftDataGridView.Name = "buttonFillLeftDataGridView";
            this.buttonFillLeftDataGridView.Size = new System.Drawing.Size(80, 20);
            this.buttonFillLeftDataGridView.TabIndex = 9;
            this.buttonFillLeftDataGridView.Text = "Lewa tab.";
            this.buttonFillLeftDataGridView.UseVisualStyleBackColor = true;
            this.buttonFillLeftDataGridView.Click += new System.EventHandler(this.buttonFillLeftDataGridView_Click);
            // 
            // buttonFillRightDataGridView
            // 
            this.buttonFillRightDataGridView.Location = new System.Drawing.Point(209, 48);
            this.buttonFillRightDataGridView.Name = "buttonFillRightDataGridView";
            this.buttonFillRightDataGridView.Size = new System.Drawing.Size(80, 20);
            this.buttonFillRightDataGridView.TabIndex = 10;
            this.buttonFillRightDataGridView.Text = "Prawa tab.";
            this.buttonFillRightDataGridView.UseVisualStyleBackColor = true;
            this.buttonFillRightDataGridView.Click += new System.EventHandler(this.buttonFillRightDataGridView_Click);
            // 
            // textBoxDelivererSpecifyID
            // 
            this.textBoxDelivererSpecifyID.Location = new System.Drawing.Point(774, 39);
            this.textBoxDelivererSpecifyID.Name = "textBoxDelivererSpecifyID";
            this.textBoxDelivererSpecifyID.Size = new System.Drawing.Size(100, 20);
            this.textBoxDelivererSpecifyID.TabIndex = 11;
            this.textBoxDelivererSpecifyID.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // checkBoxFillingRightTable
            // 
            this.checkBoxFillingRightTable.AutoSize = true;
            this.checkBoxFillingRightTable.Location = new System.Drawing.Point(524, 7);
            this.checkBoxFillingRightTable.Name = "checkBoxFillingRightTable";
            this.checkBoxFillingRightTable.Size = new System.Drawing.Size(153, 17);
            this.checkBoxFillingRightTable.TabIndex = 12;
            this.checkBoxFillingRightTable.Text = "Wypełnianie prawej tablicy";
            this.checkBoxFillingRightTable.UseVisualStyleBackColor = true;
            // 
            // buttonSuppliesWithManagers
            // 
            this.buttonSuppliesWithManagers.Location = new System.Drawing.Point(362, 33);
            this.buttonSuppliesWithManagers.Name = "buttonSuppliesWithManagers";
            this.buttonSuppliesWithManagers.Size = new System.Drawing.Size(200, 30);
            this.buttonSuppliesWithManagers.TabIndex = 13;
            this.buttonSuppliesWithManagers.Text = "Dostawy wraz z managerami";
            this.buttonSuppliesWithManagers.UseVisualStyleBackColor = true;
            this.buttonSuppliesWithManagers.Click += new System.EventHandler(this.buttonSuppliesWithManagers_Click);
            // 
            // buttonSuppliesAfterDate
            // 
            this.buttonSuppliesAfterDate.Location = new System.Drawing.Point(618, 33);
            this.buttonSuppliesAfterDate.Name = "buttonSuppliesAfterDate";
            this.buttonSuppliesAfterDate.Size = new System.Drawing.Size(200, 30);
            this.buttonSuppliesAfterDate.TabIndex = 14;
            this.buttonSuppliesAfterDate.Text = "Dostawy po dniu:";
            this.buttonSuppliesAfterDate.UseVisualStyleBackColor = true;
            this.buttonSuppliesAfterDate.Click += new System.EventHandler(this.buttonSuppliesAfterDate_Click);
            // 
            // dateTimePickerSupplySpecifyDate
            // 
            this.dateTimePickerSupplySpecifyDate.Location = new System.Drawing.Point(837, 39);
            this.dateTimePickerSupplySpecifyDate.Name = "dateTimePickerSupplySpecifyDate";
            this.dateTimePickerSupplySpecifyDate.Size = new System.Drawing.Size(200, 20);
            this.dateTimePickerSupplySpecifyDate.TabIndex = 16;
            // 
            // buttonDeliveriesWithDeliverers
            // 
            this.buttonDeliveriesWithDeliverers.Location = new System.Drawing.Point(362, 33);
            this.buttonDeliveriesWithDeliverers.Name = "buttonDeliveriesWithDeliverers";
            this.buttonDeliveriesWithDeliverers.Size = new System.Drawing.Size(200, 30);
            this.buttonDeliveriesWithDeliverers.TabIndex = 17;
            this.buttonDeliveriesWithDeliverers.Text = "Dowozy wraz z dowozicielami";
            this.buttonDeliveriesWithDeliverers.UseVisualStyleBackColor = true;
            this.buttonDeliveriesWithDeliverers.Click += new System.EventHandler(this.buttonDeliveriesWithDeliverers_Click);
            // 
            // buttonDeliveriesFurtherThan
            // 
            this.buttonDeliveriesFurtherThan.Location = new System.Drawing.Point(618, 33);
            this.buttonDeliveriesFurtherThan.Name = "buttonDeliveriesFurtherThan";
            this.buttonDeliveriesFurtherThan.Size = new System.Drawing.Size(200, 30);
            this.buttonDeliveriesFurtherThan.TabIndex = 18;
            this.buttonDeliveriesFurtherThan.Text = "Dowozy o odległości ponad:";
            this.buttonDeliveriesFurtherThan.UseVisualStyleBackColor = true;
            this.buttonDeliveriesFurtherThan.Click += new System.EventHandler(this.buttonDeliveriesFurtherThan_Click);
            // 
            // textBoxDeliverySpecifyDistance
            // 
            this.textBoxDeliverySpecifyDistance.Location = new System.Drawing.Point(837, 39);
            this.textBoxDeliverySpecifyDistance.Name = "textBoxDeliverySpecifyDistance";
            this.textBoxDeliverySpecifyDistance.Size = new System.Drawing.Size(100, 20);
            this.textBoxDeliverySpecifyDistance.TabIndex = 19;
            this.textBoxDeliverySpecifyDistance.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // buttonWaitersWithTotalTips
            // 
            this.buttonWaitersWithTotalTips.Location = new System.Drawing.Point(362, 33);
            this.buttonWaitersWithTotalTips.Name = "buttonWaitersWithTotalTips";
            this.buttonWaitersWithTotalTips.Size = new System.Drawing.Size(200, 30);
            this.buttonWaitersWithTotalTips.TabIndex = 20;
            this.buttonWaitersWithTotalTips.Text = "Suma napiwków kelnerów";
            this.buttonWaitersWithTotalTips.UseVisualStyleBackColor = true;
            this.buttonWaitersWithTotalTips.Click += new System.EventHandler(this.buttonWaitersWithTotalTips_Click);
            // 
            // buttonWaitersWithTransactionsCount
            // 
            this.buttonWaitersWithTransactionsCount.Location = new System.Drawing.Point(618, 33);
            this.buttonWaitersWithTransactionsCount.Name = "buttonWaitersWithTransactionsCount";
            this.buttonWaitersWithTransactionsCount.Size = new System.Drawing.Size(200, 30);
            this.buttonWaitersWithTransactionsCount.TabIndex = 21;
            this.buttonWaitersWithTransactionsCount.Text = "Liczba transakcji kelnerów";
            this.buttonWaitersWithTransactionsCount.UseVisualStyleBackColor = true;
            this.buttonWaitersWithTransactionsCount.Click += new System.EventHandler(this.buttonWaitersWithTransactionsCount_Click);
            // 
            // buttonWaitersWithTransactionsTotalCost
            // 
            this.buttonWaitersWithTransactionsTotalCost.Location = new System.Drawing.Point(968, 33);
            this.buttonWaitersWithTransactionsTotalCost.Name = "buttonWaitersWithTransactionsTotalCost";
            this.buttonWaitersWithTransactionsTotalCost.Size = new System.Drawing.Size(200, 30);
            this.buttonWaitersWithTransactionsTotalCost.TabIndex = 22;
            this.buttonWaitersWithTransactionsTotalCost.Text = "Suma transakcji kelnerów";
            this.buttonWaitersWithTransactionsTotalCost.UseVisualStyleBackColor = true;
            this.buttonWaitersWithTransactionsTotalCost.Click += new System.EventHandler(this.buttonWaitersWithTransactionsTotalCost_Click);
            // 
            // buttonClientTransactionsTotalCost
            // 
            this.buttonClientTransactionsTotalCost.Location = new System.Drawing.Point(362, 33);
            this.buttonClientTransactionsTotalCost.Name = "buttonClientTransactionsTotalCost";
            this.buttonClientTransactionsTotalCost.Size = new System.Drawing.Size(200, 30);
            this.buttonClientTransactionsTotalCost.TabIndex = 23;
            this.buttonClientTransactionsTotalCost.Text = "Łączny wydatek klientów";
            this.buttonClientTransactionsTotalCost.UseVisualStyleBackColor = true;
            this.buttonClientTransactionsTotalCost.Click += new System.EventHandler(this.buttonClientTransactionsTotalCost_Click);
            // 
            // buttonClientDeliveriesCount
            // 
            this.buttonClientDeliveriesCount.Location = new System.Drawing.Point(618, 33);
            this.buttonClientDeliveriesCount.Name = "buttonClientDeliveriesCount";
            this.buttonClientDeliveriesCount.Size = new System.Drawing.Size(200, 30);
            this.buttonClientDeliveriesCount.TabIndex = 24;
            this.buttonClientDeliveriesCount.Text = "Liczba dowozów klientów";
            this.buttonClientDeliveriesCount.UseVisualStyleBackColor = true;
            this.buttonClientDeliveriesCount.Click += new System.EventHandler(this.buttonClientDeliveriesCount_Click);
            // 
            // buttonCookWithMeals
            // 
            this.buttonCookWithMeals.Location = new System.Drawing.Point(811, 33);
            this.buttonCookWithMeals.Name = "buttonCookWithMeals";
            this.buttonCookWithMeals.Size = new System.Drawing.Size(200, 30);
            this.buttonCookWithMeals.TabIndex = 25;
            this.buttonCookWithMeals.Text = "Posiłki kucharza nr:";
            this.buttonCookWithMeals.UseVisualStyleBackColor = true;
            this.buttonCookWithMeals.Click += new System.EventHandler(this.buttonCookWithMeals_Click);
            // 
            // textBoxSpecifyCookIDForMeals
            // 
            this.textBoxSpecifyCookIDForMeals.Location = new System.Drawing.Point(1068, 39);
            this.textBoxSpecifyCookIDForMeals.Name = "textBoxSpecifyCookIDForMeals";
            this.textBoxSpecifyCookIDForMeals.Size = new System.Drawing.Size(100, 20);
            this.textBoxSpecifyCookIDForMeals.TabIndex = 26;
            this.textBoxSpecifyCookIDForMeals.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // buttonCooksWithShoppings
            // 
            this.buttonCooksWithShoppings.Location = new System.Drawing.Point(362, 33);
            this.buttonCooksWithShoppings.Name = "buttonCooksWithShoppings";
            this.buttonCooksWithShoppings.Size = new System.Drawing.Size(200, 30);
            this.buttonCooksWithShoppings.TabIndex = 27;
            this.buttonCooksWithShoppings.Text = "Zakupy dla kucharza nr:";
            this.buttonCooksWithShoppings.UseVisualStyleBackColor = true;
            this.buttonCooksWithShoppings.Click += new System.EventHandler(this.buttonCooksWithShoppings_Click);
            // 
            // textBoxSpecifyCookIDForShoppings
            // 
            this.textBoxSpecifyCookIDForShoppings.Location = new System.Drawing.Point(603, 39);
            this.textBoxSpecifyCookIDForShoppings.Name = "textBoxSpecifyCookIDForShoppings";
            this.textBoxSpecifyCookIDForShoppings.Size = new System.Drawing.Size(100, 20);
            this.textBoxSpecifyCookIDForShoppings.TabIndex = 28;
            this.textBoxSpecifyCookIDForShoppings.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // buttonManagersYoungerThan30
            // 
            this.buttonManagersYoungerThan30.Location = new System.Drawing.Point(362, 33);
            this.buttonManagersYoungerThan30.Name = "buttonManagersYoungerThan30";
            this.buttonManagersYoungerThan30.Size = new System.Drawing.Size(200, 30);
            this.buttonManagersYoungerThan30.TabIndex = 29;
            this.buttonManagersYoungerThan30.Text = "Managarowie młodsi niż 30 lat";
            this.buttonManagersYoungerThan30.UseVisualStyleBackColor = true;
            this.buttonManagersYoungerThan30.Click += new System.EventHandler(this.buttonManagersYoungerThan30_Click);
            // 
            // buttonManagersEmployees
            // 
            this.buttonManagersEmployees.Location = new System.Drawing.Point(618, 33);
            this.buttonManagersEmployees.Name = "buttonManagersEmployees";
            this.buttonManagersEmployees.Size = new System.Drawing.Size(200, 30);
            this.buttonManagersEmployees.TabIndex = 30;
            this.buttonManagersEmployees.Text = "Podwładni managera nr:";
            this.buttonManagersEmployees.UseVisualStyleBackColor = true;
            this.buttonManagersEmployees.Click += new System.EventHandler(this.buttonManagersEmployees_Click);
            // 
            // textBoxSpecifyManagerID
            // 
            this.textBoxSpecifyManagerID.Location = new System.Drawing.Point(837, 39);
            this.textBoxSpecifyManagerID.Name = "textBoxSpecifyManagerID";
            this.textBoxSpecifyManagerID.Size = new System.Drawing.Size(100, 20);
            this.textBoxSpecifyManagerID.TabIndex = 31;
            this.textBoxSpecifyManagerID.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // buttonMealWithSpecifiedName
            // 
            this.buttonMealWithSpecifiedName.Location = new System.Drawing.Point(362, 33);
            this.buttonMealWithSpecifiedName.Name = "buttonMealWithSpecifiedName";
            this.buttonMealWithSpecifiedName.Size = new System.Drawing.Size(200, 30);
            this.buttonMealWithSpecifiedName.TabIndex = 32;
            this.buttonMealWithSpecifiedName.Text = "Wyszukiwanie posiłków po nazwie";
            this.buttonMealWithSpecifiedName.UseVisualStyleBackColor = true;
            this.buttonMealWithSpecifiedName.Click += new System.EventHandler(this.buttonMealWithSpecifiedName_Click);
            // 
            // buttonMealsWithSpecifiedCategory
            // 
            this.buttonMealsWithSpecifiedCategory.Location = new System.Drawing.Point(811, 36);
            this.buttonMealsWithSpecifiedCategory.Name = "buttonMealsWithSpecifiedCategory";
            this.buttonMealsWithSpecifiedCategory.Size = new System.Drawing.Size(200, 30);
            this.buttonMealsWithSpecifiedCategory.TabIndex = 33;
            this.buttonMealsWithSpecifiedCategory.Text = "Wyszukiwanie posiłków po rodzaju";
            this.buttonMealsWithSpecifiedCategory.UseVisualStyleBackColor = true;
            this.buttonMealsWithSpecifiedCategory.Click += new System.EventHandler(this.buttonMealsWithSpecifiedCategory_Click);
            // 
            // textBoxSpecifyMealName
            // 
            this.textBoxSpecifyMealName.Location = new System.Drawing.Point(603, 39);
            this.textBoxSpecifyMealName.Name = "textBoxSpecifyMealName";
            this.textBoxSpecifyMealName.Size = new System.Drawing.Size(100, 20);
            this.textBoxSpecifyMealName.TabIndex = 34;
            this.textBoxSpecifyMealName.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // textBoxSpecifyMealCategory
            // 
            this.textBoxSpecifyMealCategory.Location = new System.Drawing.Point(1068, 39);
            this.textBoxSpecifyMealCategory.Name = "textBoxSpecifyMealCategory";
            this.textBoxSpecifyMealCategory.Size = new System.Drawing.Size(100, 20);
            this.textBoxSpecifyMealCategory.TabIndex = 35;
            this.textBoxSpecifyMealCategory.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // buttonMealsFromSpecifiedCategory
            // 
            this.buttonMealsFromSpecifiedCategory.Location = new System.Drawing.Point(362, 33);
            this.buttonMealsFromSpecifiedCategory.Name = "buttonMealsFromSpecifiedCategory";
            this.buttonMealsFromSpecifiedCategory.Size = new System.Drawing.Size(200, 30);
            this.buttonMealsFromSpecifiedCategory.TabIndex = 36;
            this.buttonMealsFromSpecifiedCategory.Text = "Wszystkie posiłki podanej kategorii";
            this.buttonMealsFromSpecifiedCategory.UseVisualStyleBackColor = true;
            this.buttonMealsFromSpecifiedCategory.Click += new System.EventHandler(this.buttonMealsFromSpecifiedCategory_Click);
            // 
            // textBoxMealCategorySpecifyName
            // 
            this.textBoxMealCategorySpecifyName.Location = new System.Drawing.Point(603, 39);
            this.textBoxMealCategorySpecifyName.Name = "textBoxMealCategorySpecifyName";
            this.textBoxMealCategorySpecifyName.Size = new System.Drawing.Size(100, 20);
            this.textBoxMealCategorySpecifyName.TabIndex = 37;
            this.textBoxMealCategorySpecifyName.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // buttonCarsWithDeliverers
            // 
            this.buttonCarsWithDeliverers.Location = new System.Drawing.Point(362, 33);
            this.buttonCarsWithDeliverers.Name = "buttonCarsWithDeliverers";
            this.buttonCarsWithDeliverers.Size = new System.Drawing.Size(200, 30);
            this.buttonCarsWithDeliverers.TabIndex = 38;
            this.buttonCarsWithDeliverers.Text = "Samochody przypisane do dowozicieli";
            this.buttonCarsWithDeliverers.UseVisualStyleBackColor = true;
            this.buttonCarsWithDeliverers.Click += new System.EventHandler(this.buttonCarsWithDeliverers_Click);
            // 
            // buttonTransactionsMoreExpensiveThan100
            // 
            this.buttonTransactionsMoreExpensiveThan100.Location = new System.Drawing.Point(362, 33);
            this.buttonTransactionsMoreExpensiveThan100.Name = "buttonTransactionsMoreExpensiveThan100";
            this.buttonTransactionsMoreExpensiveThan100.Size = new System.Drawing.Size(200, 30);
            this.buttonTransactionsMoreExpensiveThan100.TabIndex = 39;
            this.buttonTransactionsMoreExpensiveThan100.Text = "Transakcje na kwotę ponad 100 zł";
            this.buttonTransactionsMoreExpensiveThan100.UseVisualStyleBackColor = true;
            this.buttonTransactionsMoreExpensiveThan100.Click += new System.EventHandler(this.buttonTransactionsMoreExpensiveThan100_Click);
            // 
            // buttonTipsGreaterThan10
            // 
            this.buttonTipsGreaterThan10.Location = new System.Drawing.Point(618, 33);
            this.buttonTipsGreaterThan10.Name = "buttonTipsGreaterThan10";
            this.buttonTipsGreaterThan10.Size = new System.Drawing.Size(200, 30);
            this.buttonTipsGreaterThan10.TabIndex = 40;
            this.buttonTipsGreaterThan10.Text = "Transakcje z napiwkiem ponad 10 zł";
            this.buttonTipsGreaterThan10.UseVisualStyleBackColor = true;
            this.buttonTipsGreaterThan10.Click += new System.EventHandler(this.buttonTipsGreaterThan10_Click);
            // 
            // buttonShoppingsBeforeDate
            // 
            this.buttonShoppingsBeforeDate.Location = new System.Drawing.Point(362, 33);
            this.buttonShoppingsBeforeDate.Name = "buttonShoppingsBeforeDate";
            this.buttonShoppingsBeforeDate.Size = new System.Drawing.Size(200, 30);
            this.buttonShoppingsBeforeDate.TabIndex = 41;
            this.buttonShoppingsBeforeDate.Text = "Zakupy wykonane przed datą:";
            this.buttonShoppingsBeforeDate.UseVisualStyleBackColor = true;
            this.buttonShoppingsBeforeDate.Click += new System.EventHandler(this.buttonShoppingsBeforeDate_Click);
            // 
            // dateTimePickerSpecifyShoppingDate
            // 
            this.dateTimePickerSpecifyShoppingDate.Location = new System.Drawing.Point(605, 39);
            this.dateTimePickerSpecifyShoppingDate.Name = "dateTimePickerSpecifyShoppingDate";
            this.dateTimePickerSpecifyShoppingDate.Size = new System.Drawing.Size(200, 20);
            this.dateTimePickerSpecifyShoppingDate.TabIndex = 44;
            // 
            // FormMainZad1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1193, 448);
            this.Controls.Add(this.dateTimePickerSpecifyShoppingDate);
            this.Controls.Add(this.buttonShoppingsBeforeDate);
            this.Controls.Add(this.buttonTipsGreaterThan10);
            this.Controls.Add(this.buttonTransactionsMoreExpensiveThan100);
            this.Controls.Add(this.buttonCarsWithDeliverers);
            this.Controls.Add(this.textBoxMealCategorySpecifyName);
            this.Controls.Add(this.buttonMealsFromSpecifiedCategory);
            this.Controls.Add(this.textBoxSpecifyMealCategory);
            this.Controls.Add(this.textBoxSpecifyMealName);
            this.Controls.Add(this.buttonMealsWithSpecifiedCategory);
            this.Controls.Add(this.buttonMealWithSpecifiedName);
            this.Controls.Add(this.textBoxSpecifyManagerID);
            this.Controls.Add(this.buttonManagersEmployees);
            this.Controls.Add(this.buttonManagersYoungerThan30);
            this.Controls.Add(this.textBoxSpecifyCookIDForShoppings);
            this.Controls.Add(this.buttonCooksWithShoppings);
            this.Controls.Add(this.textBoxSpecifyCookIDForMeals);
            this.Controls.Add(this.buttonCookWithMeals);
            this.Controls.Add(this.buttonClientDeliveriesCount);
            this.Controls.Add(this.buttonClientTransactionsTotalCost);
            this.Controls.Add(this.buttonWaitersWithTransactionsTotalCost);
            this.Controls.Add(this.buttonWaitersWithTransactionsCount);
            this.Controls.Add(this.buttonWaitersWithTotalTips);
            this.Controls.Add(this.textBoxDeliverySpecifyDistance);
            this.Controls.Add(this.buttonDeliveriesFurtherThan);
            this.Controls.Add(this.buttonDeliveriesWithDeliverers);
            this.Controls.Add(this.dateTimePickerSupplySpecifyDate);
            this.Controls.Add(this.buttonSuppliesAfterDate);
            this.Controls.Add(this.buttonSuppliesWithManagers);
            this.Controls.Add(this.checkBoxFillingRightTable);
            this.Controls.Add(this.textBoxDelivererSpecifyID);
            this.Controls.Add(this.buttonFillRightDataGridView);
            this.Controls.Add(this.buttonFillLeftDataGridView);
            this.Controls.Add(this.buttonDelivererDeliveries);
            this.Controls.Add(this.buttonDeliverersWithoutCar);
            this.Controls.Add(this.labelOtherQueries);
            this.Controls.Add(this.labelAllTableColumnsDisplay);
            this.Controls.Add(this.dataGridViewSecondTable);
            this.Controls.Add(this.dataGridViewFirstTable);
            this.Controls.Add(this.listBoxDatabaseTableChoosing);
            this.Name = "FormMainZad1";
            this.Text = "Okno główne zadania 1";
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewFirstTable)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewSecondTable)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.ListBox listBoxDatabaseTableChoosing;
        private System.Windows.Forms.DataGridView dataGridViewFirstTable;
        private System.Windows.Forms.DataGridView dataGridViewSecondTable;
        private System.Windows.Forms.Label labelAllTableColumnsDisplay;
        private System.Windows.Forms.Label labelOtherQueries;
        private System.Windows.Forms.Button buttonDeliverersWithoutCar;
        private System.Windows.Forms.Button buttonDelivererDeliveries;
        private System.Windows.Forms.Button buttonFillLeftDataGridView;
        private System.Windows.Forms.Button buttonFillRightDataGridView;
        private System.Windows.Forms.TextBox textBoxDelivererSpecifyID;
        private System.Windows.Forms.CheckBox checkBoxFillingRightTable;
        private System.Windows.Forms.Button buttonSuppliesWithManagers;
        private System.Windows.Forms.Button buttonSuppliesAfterDate;
        private System.Windows.Forms.DateTimePicker dateTimePickerSupplySpecifyDate;
        private System.Windows.Forms.Button buttonDeliveriesWithDeliverers;
        private System.Windows.Forms.Button buttonDeliveriesFurtherThan;
        private System.Windows.Forms.TextBox textBoxDeliverySpecifyDistance;
        private System.Windows.Forms.Button buttonWaitersWithTotalTips;
        private System.Windows.Forms.Button buttonWaitersWithTransactionsCount;
        private System.Windows.Forms.Button buttonWaitersWithTransactionsTotalCost;
        private System.Windows.Forms.Button buttonClientTransactionsTotalCost;
        private System.Windows.Forms.Button buttonClientDeliveriesCount;
        private System.Windows.Forms.Button buttonCookWithMeals;
        private System.Windows.Forms.TextBox textBoxSpecifyCookIDForMeals;
        private System.Windows.Forms.Button buttonCooksWithShoppings;
        private System.Windows.Forms.TextBox textBoxSpecifyCookIDForShoppings;
        private System.Windows.Forms.Button buttonManagersYoungerThan30;
        private System.Windows.Forms.Button buttonManagersEmployees;
        private System.Windows.Forms.TextBox textBoxSpecifyManagerID;
        private System.Windows.Forms.Button buttonMealWithSpecifiedName;
        private System.Windows.Forms.Button buttonMealsWithSpecifiedCategory;
        private System.Windows.Forms.TextBox textBoxSpecifyMealName;
        private System.Windows.Forms.TextBox textBoxSpecifyMealCategory;
        private System.Windows.Forms.Button buttonMealsFromSpecifiedCategory;
        private System.Windows.Forms.TextBox textBoxMealCategorySpecifyName;
        private System.Windows.Forms.Button buttonCarsWithDeliverers;
        private System.Windows.Forms.Button buttonTransactionsMoreExpensiveThan100;
        private System.Windows.Forms.Button buttonTipsGreaterThan10;
        private System.Windows.Forms.Button buttonShoppingsBeforeDate;
        private System.Windows.Forms.DateTimePicker dateTimePickerSpecifyShoppingDate;
    }
}