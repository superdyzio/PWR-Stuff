using System.Data;
using System.Data.SqlClient;
using System.Windows.Forms;

namespace DawidPerdekZad3.Model.Zad1
{
    /// <summary>
    /// Klasa modelująca pojedynczą dostawę.
    /// </summary>
    public class Delivery
    {
        /// <summary>
        /// Statyczna metoda pozwalająca na pobranie wszystkich dostaw z bazy danych.
        /// </summary>
        /// <param name="sqlConnection">połączenie z bazą SQL</param>
        /// <param name="sqlDataAdapter">zmienna do komunikacji z bazą danych</param>
        /// <param name="dataGridView">kontrolka do wypełnienia danymi</param>
        public static void GetAllDeliveries(SqlConnection sqlConnection, SqlDataAdapter sqlDataAdapter, DataGridView dataGridView)
        {
            dataGridView.DataSource = null;
            sqlDataAdapter = new SqlDataAdapter("Select ID, TransactionID as Zamówienie, DelivererID as Dostawca, DeliveryDistance as Odległość, DeliveryCost as Koszt, Tip as Napiwek from Deliveries", sqlConnection);
            DataTable dataTable = new DataTable();
            sqlDataAdapter.Fill(dataTable);
            dataGridView.DataSource = dataTable;
        }

        /// <summary>
        /// Statyczna metoda pozwalająca na pobranie wszystkich dostaw wraz z dostawcami z bazy danych.
        /// </summary>
        /// <param name="sqlConnection">połączenie z bazą SQL</param>
        /// <param name="sqlDataAdapter">zmienna do komunikacji z bazą danych</param>
        /// <param name="dataGridView">kontrolka do wypełnienia danymi</param>
        public static void GetDeliveriesWithDeliverers(SqlConnection sqlConnection, SqlDataAdapter sqlDataAdapter, DataGridView dataGridView)
        {
            dataGridView.DataSource = null;
            sqlDataAdapter = new SqlDataAdapter("select d.DeliveryDistance as Odległość, d.DeliveryCost as Koszt, dr.Name as Imię, dr.Surname as Nazwisko from Deliveries d join Deliverers dr on d.DelivererID = dr.ID", sqlConnection);
            DataTable dataTable = new DataTable();
            sqlDataAdapter.Fill(dataTable);
            dataGridView.DataSource = dataTable;
        }

        /// <summary>
        /// Statyczna metoda pozwalająca na pobranie wszystkich dostaw na odległość dalszą niż podana przez użytkownika z bazy danych.
        /// </summary>
        /// <param name="sqlConnection">połączenie z bazą SQL</param>
        /// <param name="sqlDataAdapter">zmienna do komunikacji z bazą danych</param>
        /// <param name="dataGridView">kontrolka do wypełnienia danymi</param>
        public static void GetDeliveriesWithMinimalDistance(SqlConnection sqlConnection, SqlDataAdapter sqlDataAdapter, DataGridView dataGridView, int distance)
        {
            dataGridView.DataSource = null;
            sqlDataAdapter = new SqlDataAdapter("select d.DeliveryDistance as Odległość, d.DeliveryCost as Koszt, dr.Name as Imię, dr.Surname as Nazwisko from Deliveries d join Deliverers dr on d.DelivererID = dr.ID and d.DeliveryDistance > " + distance.ToString(), sqlConnection);
            DataTable dataTable = new DataTable();
            sqlDataAdapter.Fill(dataTable);
            dataGridView.DataSource = dataTable;
        }
    }
}
