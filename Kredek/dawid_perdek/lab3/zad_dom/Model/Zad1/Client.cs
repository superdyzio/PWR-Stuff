using System.Data;
using System.Data.SqlClient;
using System.Windows.Forms;

namespace DawidPerdekZad3.Model.Zad1
{
    /// <summary>
    /// Klasa modelująca klienta.
    /// </summary>
    public class Client
    {
        /// <summary>
        /// Statyczna metoda pozwalająca na pobranie wszystkich klientów z bazy danych.
        /// </summary>
        /// <param name="sqlConnection">połączenie z bazą SQL</param>
        /// <param name="sqlDataAdapter">zmienna do komunikacji z bazą danych</param>
        /// <param name="dataGridView">kontrolka do wypełnienia danymi</param>
        public static void GetAllClients(SqlConnection sqlConnection, SqlDataAdapter sqlDataAdapter, DataGridView dataGridView)
        {
            dataGridView.DataSource = null;
            sqlDataAdapter = new SqlDataAdapter("Select ID, Name as Imię, Surname as Nazwisko from Clients", sqlConnection);
            DataTable dataTable = new DataTable();
            sqlDataAdapter.Fill(dataTable);
            dataGridView.DataSource = dataTable;
        }

        /// <summary>
        /// Statyczna metoda pozwalająca na pobranie wszystkich klientów wraz z ich łącznym wydatkiem z bazy danych.
        /// </summary>
        /// <param name="sqlConnection">połączenie z bazą SQL</param>
        /// <param name="sqlDataAdapter">zmienna do komunikacji z bazą danych</param>
        /// <param name="dataGridView">kontrolka do wypełnienia danymi</param>
        public static void GetClientsWithTransactionsTotalCost(SqlConnection sqlConnection, SqlDataAdapter sqlDataAdapter, DataGridView dataGridView)
        {
            dataGridView.DataSource = null;
            sqlDataAdapter = new SqlDataAdapter("select k.Name as Imię, k.Surname as Nazwisko, Sum(t.Cost) as 'Łączny wydatek' from Clients k, Transactions t where k.ID = t.ClientID group by k.Surname, k.Name", sqlConnection);
            DataTable dataTable = new DataTable();
            sqlDataAdapter.Fill(dataTable);
            dataGridView.DataSource = dataTable;
        }

        /// <summary>
        /// Statyczna metoda pozwalająca na pobranie wszystkich klientów wraz z liczbą ich dowozów z bazy danych.
        /// </summary>
        /// <param name="sqlConnection">połączenie z bazą SQL</param>
        /// <param name="sqlDataAdapter">zmienna do komunikacji z bazą danych</param>
        /// <param name="dataGridView">kontrolka do wypełnienia danymi</param>
        public static void GetClientsWithDeliveriesCount(SqlConnection sqlConnection, SqlDataAdapter sqlDataAdapter, DataGridView dataGridView)
        {
            dataGridView.DataSource = null;
            sqlDataAdapter = new SqlDataAdapter("select k.Name as Imię, k.Surname as Nazwisko, Count(d.ID) as 'Liczba dowozów' from Clients k, Deliveries d join Transactions t on d.TransactionID = t.ID where k.ID = t.ClientID group by k.Surname, k.Name", sqlConnection);
            DataTable dataTable = new DataTable();
            sqlDataAdapter.Fill(dataTable);
            dataGridView.DataSource = dataTable;
        }
    }
}
