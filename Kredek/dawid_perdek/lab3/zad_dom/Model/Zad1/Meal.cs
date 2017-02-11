using System.Data;
using System.Data.SqlClient;
using System.Windows.Forms;

namespace DawidPerdekZad3.Model.Zad1
{
    /// <summary>
    /// Klasa modelująca pojedynczy posiłek.
    /// </summary>
    public class Meal
    {
        /// <summary>
        /// Statyczna metoda pozwalająca na pobranie wszystkich posiłków z bazy danych.
        /// </summary>
        /// <param name="sqlConnection">połączenie z bazą SQL</param>
        /// <param name="sqlDataAdapter">zmienna do komunikacji z bazą danych</param>
        /// <param name="dataGridView">kontrolka do wypełnienia danymi</param>
        public static void GetAllMeals(SqlConnection sqlConnection, SqlDataAdapter sqlDataAdapter, DataGridView dataGridView)
        {
            dataGridView.DataSource = null;
            sqlDataAdapter = new SqlDataAdapter("Select ID, MealCategoryID as Rodzaj, CookID as Kucharz, Price as Cena, Name as Nazwa from Meals", sqlConnection);
            DataTable dataTable = new DataTable();
            sqlDataAdapter.Fill(dataTable);
            dataGridView.DataSource = dataTable;
        }

        /// <summary>
        /// Statyczna metoda pozwalająca na pobranie posiłku o konkretnej nazwie z bazy danych.
        /// </summary>
        /// <param name="sqlConnection">połączenie z bazą SQL</param>
        /// <param name="sqlDataAdapter">zmienna do komunikacji z bazą danych</param>
        /// <param name="dataGridView">kontrolka do wypełnienia danymi</param>
        public static void GetMealWithSpecifiedName(SqlConnection sqlConnection, SqlDataAdapter sqlDataAdapter, DataGridView dataGridView, string mealName)
        {
            dataGridView.DataSource = null;
            sqlDataAdapter = new SqlDataAdapter("select Name as Nazwa, Price as Cena, CookID as Kucharz from Meals where Name = '" + mealName + "'", sqlConnection);
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
        public static void GetMealsWithSpecifiedCategory(SqlConnection sqlConnection, SqlDataAdapter sqlDataAdapter, DataGridView dataGridView, string mealCategory)
        {
            dataGridView.DataSource = null;
            sqlDataAdapter = new SqlDataAdapter("select m.Name as Nazwa, m.Price as Cena, m.CookID as Kucharz from Meals m join MealCategories c on m.MealCategoryID = c.ID where c.Category = '" + mealCategory + "'", sqlConnection);
            DataTable dataTable = new DataTable();
            sqlDataAdapter.Fill(dataTable);
            dataGridView.DataSource = dataTable;
        }
    }
}
