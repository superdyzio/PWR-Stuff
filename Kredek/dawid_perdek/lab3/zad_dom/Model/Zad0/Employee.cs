using System.Data.SqlClient;
using System.Data;
using System.Windows.Forms;

namespace DawidPerdekZad3.Model.Zad0
{
    /// <summary>
    /// Klasa modelująca pracownika.
    /// </summary>
    public class Employee
    {
        /// <summary>
        /// Statyczna metoda pozwalająca na pobranie wszystkich pracowników z bazy danych.
        /// </summary>
        /// <param name="sqlConnection">połączenie z bazą SQL</param>
        /// <param name="sqlDataAdapter">zmienna do komunikacji z bazą danych</param>
        /// <param name="dataGridView">kontrolka do wypełnienia danymi</param>
        public static void GetAllEmployees(SqlConnection sqlConnection, SqlDataAdapter sqlDataAdapter, DataGridView dataGridView)
        {
            dataGridView.DataSource = null;
            sqlDataAdapter = new SqlDataAdapter("Select ID, Name as Imię, Surname as Nazwisko, Age as Wiek from Employees", sqlConnection);
            DataTable dataTable = new DataTable();
            sqlDataAdapter.Fill(dataTable);
            dataGridView.DataSource = dataTable;
        }
    }
}
