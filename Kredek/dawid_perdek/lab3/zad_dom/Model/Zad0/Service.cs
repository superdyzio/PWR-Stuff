using System.Data;
using System.Data.SqlClient;
using System.Windows.Forms;

namespace DawidPerdekZad3.Model.Zad0
{
    /// <summary>
    /// Klasa modelująca naprawę.
    /// </summary>
    public class Service
    {
        /// <summary>
        /// Statyczna metoda pozwalająca na pobranie wszystkich napraw z bazy danych.
        /// </summary>
        /// <param name="sqlConnection">połączenie z bazą SQL</param>
        /// <param name="sqlDataAdapter">zmienna do komunikacji z bazą danych</param>
        /// <param name="dataGridView">kontrolka do wypełnienia danymi</param>
        public static void GetAllServices(SqlConnection sqlConnection, SqlDataAdapter sqlDataAdapter, DataGridView dataGridView)
        {
            dataGridView.DataSource = null;
            sqlDataAdapter = new SqlDataAdapter("Select ID, ComputerID as Komputer, EmployeeID as Pracownik, Cost as Koszt, Description as Opis from Services", sqlConnection);
            DataTable dataTable = new DataTable();
            sqlDataAdapter.Fill(dataTable);
            dataGridView.DataSource = dataTable;
        }

        /// <summary>
        /// Statyczna metoda pozwalająca na pobranie z bazy danych wszystkich napraw o cenie wyższej od podanej.
        /// </summary>
        /// <param name="sqlConnection">połączenie z bazą SQL</param>
        /// <param name="sqlDataAdapter">zmienna do komunikacji z bazą danych</param>
        /// <param name="dataGridView">kontrolka do wypełnienia danymi</param>
        /// <param name="minimalCost">cena podana przez użytkownika, zwrócone zostaną tylko rekordy o cenie wyższej od niej</param>
        public static void GetServicesWithMinimalCost(SqlConnection sqlConnection, SqlDataAdapter sqlDataAdapter, DataGridView dataGridView, int minimalCost)
        {
            dataGridView.DataSource = null;
            sqlDataAdapter = new SqlDataAdapter("Select ID, ComputerID as Komputer, EmployeeID as Pracownik, Cost as Koszt, Description as Opis FROM Services WHERE Cost > " + minimalCost.ToString(), sqlConnection);
            DataTable dataTable = new DataTable();
            sqlDataAdapter.Fill(dataTable);
            dataGridView.DataSource = dataTable;
        }
    }
}
