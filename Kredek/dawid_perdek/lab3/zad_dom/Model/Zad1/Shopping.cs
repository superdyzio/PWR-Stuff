using System.Data;
using System.Data.SqlClient;
using System.Windows.Forms;

namespace DawidPerdekZad3.Model.Zad1
{
    /// <summary>
    /// Klasa modelująca pojedynczy zakup towaru.
    /// </summary>
    public class Shopping
    {
        /// <summary>
        /// Statyczna metoda pozwalająca na pobranie wszystkich zakupów towaru z bazy danych.
        /// </summary>
        /// <param name="sqlConnection">połączenie z bazą SQL</param>
        /// <param name="sqlDataAdapter">zmienna do komunikacji z bazą danych</param>
        /// <param name="dataGridView">kontrolka do wypełnienia danymi</param>
        public static void GetAllShoppings(SqlConnection sqlConnection, SqlDataAdapter sqlDataAdapter, DataGridView dataGridView)
        {
            dataGridView.DataSource = null;
            sqlDataAdapter = new SqlDataAdapter("Select ID, ManagerID as Manager, CookID as Kucharz, Cost as Koszt, Date as Data from Shoppings", sqlConnection);
            DataTable dataTable = new DataTable();
            sqlDataAdapter.Fill(dataTable);
            dataGridView.DataSource = dataTable;
        }

        /// <summary>
        /// Statyczna metoda pozwalająca na pobranie wszystkich zakupów towaru sprzed podanej daty z bazy danych.
        /// </summary>
        /// <param name="sqlConnection">połączenie z bazą SQL</param>
        /// <param name="sqlDataAdapter">zmienna do komunikacji z bazą danych</param>
        /// <param name="dataGridView">kontrolka do wypełnienia danymi</param>
        public static void GetShoppingsBeforeDate(SqlConnection sqlConnection, SqlDataAdapter sqlDataAdapter, DataGridView dataGridView, string date)
        {
            dataGridView.DataSource = null;
            sqlDataAdapter = new SqlDataAdapter("select z.ID as Zakupy, z.Date as Data, m.Name as Imię, m.Surname as Nazwisko from Shoppings z, Managers m where z.ManagerID = m.ID and z.Date < '" + date + "'", sqlConnection);
            DataTable dataTable = new DataTable();
            sqlDataAdapter.Fill(dataTable);
            dataGridView.DataSource = dataTable;
        }
    }
}
