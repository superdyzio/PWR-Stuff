using System.Data;
using System.Data.SqlClient;
using System.Windows.Forms;

namespace DawidPerdekZad3.Model.Zad1
{
    /// <summary>
    /// Klasa modelująca managera.
    /// </summary>
    public class Manager
    {
        /// <summary>
        /// Statyczna metoda pozwalająca na pobranie wszystkich managerów z bazy danych.
        /// </summary>
        /// <param name="sqlConnection">połączenie z bazą SQL</param>
        /// <param name="sqlDataAdapter">zmienna do komunikacji z bazą danych</param>
        /// <param name="dataGridView">kontrolka do wypełnienia danymi</param>
        public static void GetAllManagers(SqlConnection sqlConnection, SqlDataAdapter sqlDataAdapter, DataGridView dataGridView)
        {
            dataGridView.DataSource = null;
            sqlDataAdapter = new SqlDataAdapter("Select ID, Name as Imię, Surname as Nazwisko, Age as Wiek from Managers", sqlConnection);
            DataTable dataTable = new DataTable();
            sqlDataAdapter.Fill(dataTable);
            dataGridView.DataSource = dataTable;
        }

        /// <summary>
        /// Statyczna metoda pozwalająca na pobranie wszystkich managerów młodszych niż 30 lat z bazy danych.
        /// </summary>
        /// <param name="sqlConnection">połączenie z bazą SQL</param>
        /// <param name="sqlDataAdapter">zmienna do komunikacji z bazą danych</param>
        /// <param name="dataGridView">kontrolka do wypełnienia danymi</param>
        public static void GetManagersYoungerThan30(SqlConnection sqlConnection, SqlDataAdapter sqlDataAdapter, DataGridView dataGridView)
        {
            dataGridView.DataSource = null;
            sqlDataAdapter = new SqlDataAdapter("Select Name as Imię, Surname as Nazwisko, Age as Wiek from Managers where Age < 30", sqlConnection);
            DataTable dataTable = new DataTable();
            sqlDataAdapter.Fill(dataTable);
            dataGridView.DataSource = dataTable;
        }

        /// <summary>
        /// Statyczna metoda pozwalająca na pobranie wszystkich pracowników podanego managera z bazy danych.
        /// </summary>
        /// <param name="sqlConnection">połączenie z bazą SQL</param>
        /// <param name="sqlDataAdapter">zmienna do komunikacji z bazą danych</param>
        /// <param name="dataGridView">kontrolka do wypełnienia danymi</param>
        public static void GetManagersEmployees(SqlConnection sqlConnection, SqlDataAdapter sqlDataAdapter, DataGridView dataGridView, int id)
        {
            dataGridView.DataSource = null;
            sqlDataAdapter = new SqlDataAdapter("select c.Name as Imię, c.Surname as Nazwisko, c.Age as Wiek, c.Salary as Pensja from Managers m, Cooks c where m.ID = c.SupervisorID and m.ID = " + id.ToString() + " union select c.Name as Imię, c.Surname as Nazwisko, c.Age as Wiek, c.Salary as Pensja from Managers m, Waiters c where m.ID = c.SupervisorID and m.ID = " + id.ToString() + " union select c.Name as Imię, c.Surname as Nazwisko, c.Age as Wiek, c.Salary as Pensja from Managers m, Deliverers c where m.ID = c.SupervisorID and m.ID = " + id.ToString(), sqlConnection);
            DataTable dataTable = new DataTable();
            sqlDataAdapter.Fill(dataTable);
            dataGridView.DataSource = dataTable;
        }
    }
}
