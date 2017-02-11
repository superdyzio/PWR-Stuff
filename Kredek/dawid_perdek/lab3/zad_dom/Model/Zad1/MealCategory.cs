using System.Data;
using System.Data.SqlClient;
using System.Windows.Forms;

namespace DawidPerdekZad3.Model.Zad1
{
    /// <summary>
    /// Klasa modelująca rodzaj posiłku.
    /// </summary>
    public class MealCategory
    {
        /// <summary>
        /// Statyczna metoda pozwalająca na pobranie wszystkich rodzajów posiłków z bazy danych.
        /// </summary>
        /// <param name="sqlConnection">połączenie z bazą SQL</param>
        /// <param name="sqlDataAdapter">zmienna do komunikacji z bazą danych</param>
        /// <param name="dataGridView">kontrolka do wypełnienia danymi</param>
        public static void GetAllMealCategories(SqlConnection sqlConnection, SqlDataAdapter sqlDataAdapter, DataGridView dataGridView)
        {
            dataGridView.DataSource = null;
            sqlDataAdapter = new SqlDataAdapter("Select ID, Category as Rodzaj from MealCategories", sqlConnection);
            DataTable dataTable = new DataTable();
            sqlDataAdapter.Fill(dataTable);
            dataGridView.DataSource = dataTable;
        }

        /// <summary>
        /// Statyczna metoda pozwalająca na pobranie wszystkich posiłków danego rodzaju z bazy danych.
        /// </summary>
        /// <param name="sqlConnection">połączenie z bazą SQL</param>
        /// <param name="sqlDataAdapter">zmienna do komunikacji z bazą danych</param>
        /// <param name="dataGridView">kontrolka do wypełnienia danymi</param>
        public static void GetMealsFromOneCategory(SqlConnection sqlConnection, SqlDataAdapter sqlDataAdapter, DataGridView dataGridView, string mealCategory)
        {
            dataGridView.DataSource = null;
            sqlDataAdapter = new SqlDataAdapter("select m.Name as Nazwa, m.Price as Cena from Meals m join MealCategories c on m.MealCategoryID = c.ID where c.Category = '" + mealCategory + "'", sqlConnection);
            DataTable dataTable = new DataTable();
            sqlDataAdapter.Fill(dataTable);
            dataGridView.DataSource = dataTable;
        }
    }
}
