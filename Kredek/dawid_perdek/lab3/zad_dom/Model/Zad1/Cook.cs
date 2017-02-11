using System.Data;
using System.Data.SqlClient;
using System.Windows.Forms;

namespace DawidPerdekZad3.Model.Zad1
{
    /// <summary>
    /// Klasa modelująca kucharza.
    /// </summary>
    public class Cook
    {
        /// <summary>
        /// Statyczna metoda pozwalająca na pobranie wszystkich kucharzy z bazy danych.
        /// </summary>
        /// <param name="sqlConnection">połączenie z bazą SQL</param>
        /// <param name="sqlDataAdapter">zmienna do komunikacji z bazą danych</param>
        /// <param name="dataGridView">kontrolka do wypełnienia danymi</param>
        public static void GetAllCooks(SqlConnection sqlConnection, SqlDataAdapter sqlDataAdapter, DataGridView dataGridView)
        {
            dataGridView.DataSource = null;
            sqlDataAdapter = new SqlDataAdapter("Select ID, SupervisorID as Przełożony, Name as Imię, Surname as Nazwisko, Age as Wiek, Sex as Płeć, Salary as Pensja from Cooks", sqlConnection);
            DataTable dataTable = new DataTable();
            sqlDataAdapter.Fill(dataTable);
            dataGridView.DataSource = dataTable;
        }

        /// <summary>
        /// Statyczna metoda pozwalająca na pobranie wszystkich zakupów danego kucharza z bazy danych.
        /// </summary>
        /// <param name="sqlConnection">połączenie z bazą SQL</param>
        /// <param name="sqlDataAdapter">zmienna do komunikacji z bazą danych</param>
        /// <param name="dataGridView">kontrolka do wypełnienia danymi</param>
        public static void GetCooksWithShoppings(SqlConnection sqlConnection, SqlDataAdapter sqlDataAdapter, DataGridView dataGridView, int id)
        {
            dataGridView.DataSource = null;
            sqlDataAdapter = new SqlDataAdapter("select s.Date as Data, s.Cost as Koszt from Shoppings s where s.CookID = " + id.ToString(), sqlConnection);
            DataTable dataTable = new DataTable();
            sqlDataAdapter.Fill(dataTable);
            dataGridView.DataSource = dataTable;
        }

        /// <summary>
        /// Statyczna metoda pozwalająca na pobranie wszystkich posiłków danego kucharza z bazy danych.
        /// </summary>
        /// <param name="sqlConnection">połączenie z bazą SQL</param>
        /// <param name="sqlDataAdapter">zmienna do komunikacji z bazą danych</param>
        /// <param name="dataGridView">kontrolka do wypełnienia danymi</param>
        public static void GetCooksWithMeals(SqlConnection sqlConnection, SqlDataAdapter sqlDataAdapter, DataGridView dataGridView, int id)
        {
            dataGridView.DataSource = null;
            sqlDataAdapter = new SqlDataAdapter("select c.Category as Rodzaj, m.Name as Nazwa from Meals m join MealCategories c on m.MealCategoryID = c.ID where m.CookID = " + id.ToString(), sqlConnection);
            DataTable dataTable = new DataTable();
            sqlDataAdapter.Fill(dataTable);
            dataGridView.DataSource = dataTable;
        }
    }
}
