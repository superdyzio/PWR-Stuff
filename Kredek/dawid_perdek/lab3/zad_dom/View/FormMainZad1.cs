using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using DawidPerdekZad3.Model.Zad1;
using System.Data.SqlClient;

namespace DawidPerdekZad3.View
{
    public partial class FormMainZad1 : Form
    {
        SqlConnection sqlConnection;    // zmienna reprezentująca połączenie z bazą danych
        SqlDataAdapter sqlDataAdapter;  // zmienna służąca do komunikacji z bazą danych

        public FormMainZad1()
        {
            InitializeComponent();
            sqlConnection = new SqlConnection("Data Source = localhost; database = DawidPerdekRestaurant; Trusted_Connection = yes");
            hideAllControls();
        }

        /// <summary>
        /// Wyświetlenie w DataGridView danych z odpowiedniej tabeli w reakcji na wciśnięcie konkretnego przycisku.
        /// </summary>
        /// <param name="sender">kontrolka wywołująca zdarzenie</param>
        /// <param name="e">argumenty zdarzenia</param>
        private void buttonFillLeftDataGridView_Click(object sender, EventArgs e)
        {
            switch (listBoxDatabaseTableChoosing.SelectedIndex)
            {
                case 0:
                    Deliverer.GetAllDeliverers(sqlConnection, sqlDataAdapter, dataGridViewFirstTable);
                    break;
                case 1:
                    Supply.GetAllSupplies(sqlConnection, sqlDataAdapter, dataGridViewFirstTable);
                    break;
                case 2:
                    Delivery.GetAllDeliveries(sqlConnection, sqlDataAdapter, dataGridViewFirstTable);
                    break;
                case 3:
                    Waiter.GetAllWaiters(sqlConnection, sqlDataAdapter, dataGridViewFirstTable);
                    break;
                case 4:
                    Client.GetAllClients(sqlConnection, sqlDataAdapter, dataGridViewFirstTable);
                    break;
                case 5:
                    Cook.GetAllCooks(sqlConnection, sqlDataAdapter, dataGridViewFirstTable);
                    break;
                case 6:
                    Manager.GetAllManagers(sqlConnection, sqlDataAdapter, dataGridViewFirstTable);
                    break;
                case 7:
                    Meal.GetAllMeals(sqlConnection, sqlDataAdapter, dataGridViewFirstTable);
                    break;
                case 8:
                    MealCategory.GetAllMealCategories(sqlConnection, sqlDataAdapter, dataGridViewFirstTable);
                    break;
                case 9:
                    Car.GetAllCars(sqlConnection, sqlDataAdapter, dataGridViewFirstTable);
                    break;
                case 10:
                    Shopping.GetAllShoppings(sqlConnection, sqlDataAdapter, dataGridViewFirstTable);
                    break;
                case 11:
                    Transaction.GetAllTransactions(sqlConnection, sqlDataAdapter, dataGridViewFirstTable);
                    break;
            }
        }

        /// <summary>
        /// 
        /// </summary>
        /// <param name="sender">kontrolka wywołująca zdarzenie</param>
        /// <param name="e">argumenty zdarzenia</param>
        private void buttonFillRightDataGridView_Click(object sender, EventArgs e)
        {
            switch (listBoxDatabaseTableChoosing.SelectedIndex)
            {
                case 0:
                    Deliverer.GetAllDeliverers(sqlConnection, sqlDataAdapter, dataGridViewSecondTable);
                    break;
                case 1:
                    Supply.GetAllSupplies(sqlConnection, sqlDataAdapter, dataGridViewSecondTable);
                    break;
                case 2:
                    Delivery.GetAllDeliveries(sqlConnection, sqlDataAdapter, dataGridViewSecondTable);
                    break;
                case 3:
                    Waiter.GetAllWaiters(sqlConnection, sqlDataAdapter, dataGridViewSecondTable);
                    break;
                case 4:
                    Client.GetAllClients(sqlConnection, sqlDataAdapter, dataGridViewSecondTable);
                    break;
                case 5:
                    Cook.GetAllCooks(sqlConnection, sqlDataAdapter, dataGridViewSecondTable);
                    break;
                case 6:
                    Manager.GetAllManagers(sqlConnection, sqlDataAdapter, dataGridViewSecondTable);
                    break;
                case 7:
                    Meal.GetAllMeals(sqlConnection, sqlDataAdapter, dataGridViewSecondTable);
                    break;
                case 8:
                    MealCategory.GetAllMealCategories(sqlConnection, sqlDataAdapter, dataGridViewSecondTable);
                    break;
                case 9:
                    Car.GetAllCars(sqlConnection, sqlDataAdapter, dataGridViewSecondTable);
                    break;
                case 10:
                    Shopping.GetAllShoppings(sqlConnection, sqlDataAdapter, dataGridViewSecondTable);
                    break;
                case 11:
                    Transaction.GetAllTransactions(sqlConnection, sqlDataAdapter, dataGridViewSecondTable);
                    break;
            }
        }

        /// <summary>
        /// Metoda pilnująca by interfejs udostępniał tylko przyciski powiązane z aktualnie zaznaczoną tabelą bazy danych.
        /// </summary>
        /// <param name="sender">kontrolka wywołująca zdarzenie</param>
        /// <param name="e">argumenty zdarzenia</param>
        private void listBoxDatabaseTableChoosing_SelectedIndexChanged(object sender, EventArgs e)
        {
            hideAllControls();
            switch (listBoxDatabaseTableChoosing.SelectedIndex)
            {
                case 0:
                    buttonDelivererDeliveries.Show();
                    buttonDeliverersWithoutCar.Show();
                    textBoxDelivererSpecifyID.Show();
                    break;
                case 1:
                    buttonSuppliesWithManagers.Show();
                    buttonSuppliesAfterDate.Show();
                    dateTimePickerSupplySpecifyDate.Show();
                    break;
                case 2:
                    buttonDeliveriesFurtherThan.Show();
                    buttonDeliveriesWithDeliverers.Show();
                    textBoxDeliverySpecifyDistance.Show();
                    break;
                case 3:
                    buttonWaitersWithTotalTips.Show();
                    buttonWaitersWithTransactionsCount.Show();
                    buttonWaitersWithTransactionsTotalCost.Show();
                    break;
                case 4:
                    buttonClientDeliveriesCount.Show();
                    buttonClientTransactionsTotalCost.Show();
                    break;
                case 5:
                    buttonCooksWithShoppings.Show();
                    buttonCookWithMeals.Show();
                    textBoxSpecifyCookIDForMeals.Show();
                    textBoxSpecifyCookIDForShoppings.Show();
                    break;
                case 6:
                    buttonManagersEmployees.Show();
                    buttonManagersYoungerThan30.Show();
                    textBoxSpecifyManagerID.Show();
                    break;
                case 7:
                    buttonMealsWithSpecifiedCategory.Show();
                    buttonMealWithSpecifiedName.Show();
                    textBoxSpecifyMealCategory.Show();
                    textBoxSpecifyMealName.Show();
                    break;
                case 8:
                    buttonMealsFromSpecifiedCategory.Show();
                    textBoxMealCategorySpecifyName.Show();
                    break;
                case 9:
                    buttonCarsWithDeliverers.Show();
                    break;
                case 10:
                    buttonShoppingsBeforeDate.Show();
                    dateTimePickerSpecifyShoppingDate.Show();
                    break;
                case 11:
                    buttonTransactionsMoreExpensiveThan100.Show();
                    buttonTipsGreaterThan10.Show();
                    break;
            }
        }

        /// <summary>
        /// Metoda pomocnicza ukrywająca wszystkie kontrolki zależne od wyboru tabeli.
        /// </summary>
        /// <param name="sender">kontrolka wywołująca zdarzenie</param>
        /// <param name="e">argumenty zdarzenia</param>
        private void hideAllControls()
        {
            buttonDelivererDeliveries.Hide();
            buttonDeliverersWithoutCar.Hide();
            textBoxDelivererSpecifyID.Hide();

            buttonSuppliesWithManagers.Hide();
            buttonSuppliesAfterDate.Hide();
            dateTimePickerSupplySpecifyDate.Hide();

            buttonDeliveriesFurtherThan.Hide();
            buttonDeliveriesWithDeliverers.Hide();
            textBoxDeliverySpecifyDistance.Hide();

            buttonWaitersWithTotalTips.Hide();
            buttonWaitersWithTransactionsCount.Hide();
            buttonWaitersWithTransactionsTotalCost.Hide();

            buttonClientDeliveriesCount.Hide();
            buttonClientTransactionsTotalCost.Hide();

            buttonCooksWithShoppings.Hide();
            buttonCookWithMeals.Hide();
            textBoxSpecifyCookIDForMeals.Hide();
            textBoxSpecifyCookIDForShoppings.Hide();

            buttonManagersEmployees.Hide();
            buttonManagersYoungerThan30.Hide();
            textBoxSpecifyManagerID.Hide();

            buttonMealsWithSpecifiedCategory.Hide();
            buttonMealWithSpecifiedName.Hide();
            textBoxSpecifyMealCategory.Hide();
            textBoxSpecifyMealName.Hide();

            buttonMealsFromSpecifiedCategory.Hide();
            textBoxMealCategorySpecifyName.Hide();

            buttonCarsWithDeliverers.Hide();

            buttonShoppingsBeforeDate.Hide();
            dateTimePickerSpecifyShoppingDate.Hide();

            buttonTransactionsMoreExpensiveThan100.Hide();
            buttonTipsGreaterThan10.Hide();
        }

        

        //  blok funkcji obsługi zdarzeń kliknięcia na poszczególne przyciski - zależnie od przycisku wykonywane jest
        // odpowiednie zapytanie do bazy danych i wyświetlane są wyniki



        private void buttonDelivererDeliveries_Click(object sender, EventArgs e)
        {
            int ID;
            try
            {
                ID = int.Parse(textBoxDelivererSpecifyID.Text);
                if (ID < 1)
                {
                    textBoxDelivererSpecifyID.Text = "1";
                    ID = 1;
                }
            }
            catch
            {
                ID = 1;
                textBoxDelivererSpecifyID.Text = "1";
            }
            Deliverer.GetDelivererDeliveries(sqlConnection, sqlDataAdapter, checkBoxFillingRightTable.Checked ? dataGridViewSecondTable : dataGridViewFirstTable, ID);
        }

        private void buttonDeliverersWithoutCar_Click(object sender, EventArgs e)
        {
            Deliverer.GetDeliverersWithoutCar(sqlConnection, sqlDataAdapter, checkBoxFillingRightTable.Checked ? dataGridViewSecondTable : dataGridViewFirstTable);
        }

        private void buttonSuppliesAfterDate_Click(object sender, EventArgs e)
        {
            Supply.GetSuppliesAfterDate(sqlConnection, sqlDataAdapter, checkBoxFillingRightTable.Checked ? dataGridViewSecondTable : dataGridViewFirstTable, dateTimePickerSupplySpecifyDate.Value.ToString().Substring(0, 10));
        }

        private void buttonSuppliesWithManagers_Click(object sender, EventArgs e)
        {
            Supply.GetSuppliesWithManagers(sqlConnection, sqlDataAdapter, checkBoxFillingRightTable.Checked ? dataGridViewSecondTable : dataGridViewFirstTable);
        }

        private void buttonDeliveriesWithDeliverers_Click(object sender, EventArgs e)
        {
            Delivery.GetDeliveriesWithDeliverers(sqlConnection, sqlDataAdapter, checkBoxFillingRightTable.Checked ? dataGridViewSecondTable : dataGridViewFirstTable);
        }

        private void buttonDeliveriesFurtherThan_Click(object sender, EventArgs e)
        {
            int distance;
            try
            {
                distance = int.Parse(textBoxDeliverySpecifyDistance.Text);
                if (distance < 0)
                {
                    textBoxDeliverySpecifyDistance.Text = "0";
                    distance = 0;
                }
            }
            catch
            {
                distance = 0;
                textBoxDeliverySpecifyDistance.Text = "0";
            }
            Delivery.GetDeliveriesWithMinimalDistance(sqlConnection, sqlDataAdapter, checkBoxFillingRightTable.Checked ? dataGridViewSecondTable : dataGridViewFirstTable, distance);
        }

        private void buttonWaitersWithTotalTips_Click(object sender, EventArgs e)
        {
            Waiter.GetWaitersWithTotalTips(sqlConnection, sqlDataAdapter, checkBoxFillingRightTable.Checked ? dataGridViewSecondTable : dataGridViewFirstTable);
        }

        private void buttonWaitersWithTransactionsCount_Click(object sender, EventArgs e)
        {
            Waiter.GetWaitersWithTransactionsCount(sqlConnection, sqlDataAdapter, checkBoxFillingRightTable.Checked ? dataGridViewSecondTable : dataGridViewFirstTable);
        }

        private void buttonWaitersWithTransactionsTotalCost_Click(object sender, EventArgs e)
        {
            Waiter.GetWaitersWithTransactionsTotalCost(sqlConnection, sqlDataAdapter, checkBoxFillingRightTable.Checked ? dataGridViewSecondTable : dataGridViewFirstTable);
        }

        private void buttonClientTransactionsTotalCost_Click(object sender, EventArgs e)
        {
            Client.GetClientsWithTransactionsTotalCost(sqlConnection, sqlDataAdapter, checkBoxFillingRightTable.Checked ? dataGridViewSecondTable : dataGridViewFirstTable);
        }

        private void buttonClientDeliveriesCount_Click(object sender, EventArgs e)
        {
            Client.GetClientsWithDeliveriesCount(sqlConnection, sqlDataAdapter, checkBoxFillingRightTable.Checked ? dataGridViewSecondTable : dataGridViewFirstTable);
        }

        private void buttonCooksWithShoppings_Click(object sender, EventArgs e)
        {
            int ID;
            try
            {
                ID = int.Parse(textBoxSpecifyCookIDForShoppings.Text);
                if (ID < 1)
                {
                    textBoxSpecifyCookIDForShoppings.Text = "1";
                    ID = 1;
                }
            }
            catch
            {
                ID = 1;
                textBoxSpecifyCookIDForShoppings.Text = "1";
            }
            Cook.GetCooksWithShoppings(sqlConnection, sqlDataAdapter, checkBoxFillingRightTable.Checked ? dataGridViewSecondTable : dataGridViewFirstTable, ID);
        }

        private void buttonCookWithMeals_Click(object sender, EventArgs e)
        {
            int ID;
            try
            {
                ID = int.Parse(textBoxSpecifyCookIDForMeals.Text);
                if (ID < 1)
                {
                    textBoxSpecifyCookIDForMeals.Text = "1";
                    ID = 1;
                }
            }
            catch
            {
                ID = 1;
                textBoxSpecifyCookIDForMeals.Text = "1";
            }
            Cook.GetCooksWithMeals(sqlConnection, sqlDataAdapter, checkBoxFillingRightTable.Checked ? dataGridViewSecondTable : dataGridViewFirstTable, ID);
        }
        
        private void buttonManagersYoungerThan30_Click(object sender, EventArgs e)
        {
            Manager.GetManagersYoungerThan30(sqlConnection, sqlDataAdapter, checkBoxFillingRightTable.Checked ? dataGridViewSecondTable : dataGridViewFirstTable);
        }

        private void buttonManagersEmployees_Click(object sender, EventArgs e)
        {
            int ID;
            try
            {
                ID = int.Parse(textBoxSpecifyManagerID.Text);
                if (ID < 1)
                {
                    textBoxSpecifyManagerID.Text = "1";
                    ID = 1;
                }
            }
            catch
            {
                ID = 1;
                textBoxSpecifyManagerID.Text = "1";
            }
            Manager.GetManagersEmployees(sqlConnection, sqlDataAdapter, checkBoxFillingRightTable.Checked ? dataGridViewSecondTable : dataGridViewFirstTable, ID);
        }

        private void buttonMealsWithSpecifiedCategory_Click(object sender, EventArgs e)
        {
            Meal.GetMealsWithSpecifiedCategory(sqlConnection, sqlDataAdapter, checkBoxFillingRightTable.Checked ? dataGridViewSecondTable : dataGridViewFirstTable, textBoxSpecifyMealCategory.Text.ToString());
        }

        private void buttonMealWithSpecifiedName_Click(object sender, EventArgs e)
        {
            Meal.GetMealWithSpecifiedName(sqlConnection, sqlDataAdapter, checkBoxFillingRightTable.Checked ? dataGridViewSecondTable : dataGridViewFirstTable, textBoxSpecifyMealName.Text.ToString());
        }

        private void buttonMealsFromSpecifiedCategory_Click(object sender, EventArgs e)
        {
            MealCategory.GetMealsFromOneCategory(sqlConnection, sqlDataAdapter, checkBoxFillingRightTable.Checked? dataGridViewSecondTable : dataGridViewFirstTable, textBoxMealCategorySpecifyName.Text.ToString());
        }

        private void buttonCarsWithDeliverers_Click(object sender, EventArgs e)
        {
            Car.GetCarsWithDeliverers(sqlConnection, sqlDataAdapter, checkBoxFillingRightTable.Checked? dataGridViewSecondTable : dataGridViewFirstTable);
        }

        private void buttonTransactionsMoreExpensiveThan100_Click(object sender, EventArgs e)
        {
            Transaction.GetTransactionsMoreExpensiveThan100(sqlConnection, sqlDataAdapter, checkBoxFillingRightTable.Checked ? dataGridViewSecondTable : dataGridViewFirstTable);
        }

        private void buttonTipsGreaterThan10_Click(object sender, EventArgs e)
        {
            Transaction.GetTransactionWithTipsGreaterThan10(sqlConnection, sqlDataAdapter, checkBoxFillingRightTable.Checked ? dataGridViewSecondTable : dataGridViewFirstTable);
        }

        private void buttonShoppingsBeforeDate_Click(object sender, EventArgs e)
        {
            Shopping.GetShoppingsBeforeDate(sqlConnection, sqlDataAdapter, checkBoxFillingRightTable.Checked ? dataGridViewSecondTable : dataGridViewFirstTable, dateTimePickerSpecifyShoppingDate.Value.ToString().Substring(0, 10));
        }
    }
}
