using System.Data;
using System.Data.SqlClient;
using System.Windows.Forms;

namespace DawidPerdekZad3.Model.Zad1
{
    /// <summary>
    /// Klasa modelująca pojedynczą dostawę towarów.
    /// </summary>
    public class Supply
    {
        /// <summary>
        /// Statyczna metoda pozwalająca na pobranie wszystkich dostaw towaru z bazy danych.
        /// </summary>
        /// <param name="sqlConnection">połączenie z bazą SQL</param>
        /// <param name="sqlDataAdapter">zmienna do komunikacji z bazą danych</param>
        /// <param name="dataGridView">kontrolka do wypełnienia danymi</param>
        public static void GetAllSupplies(SqlConnection sqlConnection, SqlDataAdapter sqlDataAdapter, DataGridView dataGridView)
        {
            dataGridView.DataSource = null;
            sqlDataAdapter = new SqlDataAdapter("Select ID, ShoppingID as Zakup, ReceivingManagerID as Manager, Date as Data from Supplies", sqlConnection);
            DataTable dataTable = new DataTable();
            sqlDataAdapter.Fill(dataTable);
            dataGridView.DataSource = dataTable;
        }

        /// <summary>
        /// Statyczna metoda pozwalająca na pobranie wszystkich dostaw towaru wraz z managerami je odbierającymi z bazy danych.
        /// </summary>
        /// <param name="sqlConnection">połączenie z bazą SQL</param>
        /// <param name="sqlDataAdapter">zmienna do komunikacji z bazą danych</param>
        /// <param name="dataGridView">kontrolka do wypełnienia danymi</param>
        public static void GetSuppliesWithManagers(SqlConnection sqlConnection, SqlDataAdapter sqlDataAdapter, DataGridView dataGridView)
        {
            dataGridView.DataSource = null;
            sqlDataAdapter = new SqlDataAdapter("select z.ShoppingID as Zakupy, z.Date as Data, m.Name as Imię, m.Surname as Nazwisko from Supplies z, Managers m where z.ReceivingManagerID = m.ID", sqlConnection);
            DataTable dataTable = new DataTable();
            sqlDataAdapter.Fill(dataTable);
            dataGridView.DataSource = dataTable;
        }

        /// <summary>
        /// Statyczna metoda pozwalająca na pobranie wszystkich dostaw towaru z bazy danych, które miały miejsce po podanej dacie.
        /// </summary>
        /// <param name="sqlConnection">połączenie z bazą SQL</param>
        /// <param name="sqlDataAdapter">zmienna do komunikacji z bazą danych</param>
        /// <param name="dataGridView">kontrolka do wypełnienia danymi</param>
        public static void GetSuppliesAfterDate(SqlConnection sqlConnection, SqlDataAdapter sqlDataAdapter, DataGridView dataGridView, string date)
        {
            dataGridView.DataSource = null;
            sqlDataAdapter = new SqlDataAdapter("select z.ShoppingID as Zakupy, z.Date as Data, m.Name as Imię, m.Surname as Nazwisko from Supplies z, Managers m where z.ReceivingManagerID = m.ID and z.Date > '" + date + "'", sqlConnection);
            DataTable dataTable = new DataTable();
            sqlDataAdapter.Fill(dataTable);
            dataGridView.DataSource = dataTable;
        }
    }
}
