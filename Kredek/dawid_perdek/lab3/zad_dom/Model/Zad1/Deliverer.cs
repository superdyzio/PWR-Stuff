using System.Data;
using System.Data.SqlClient;
using System.Windows.Forms;

namespace DawidPerdekZad3.Model.Zad1
{
    /// <summary>
    /// Klasa modelująca dostawcę.
    /// </summary>
    public class Deliverer
    {
        /// <summary>
        /// Statyczna metoda pozwalająca na pobranie wszystkich dostawców z bazy danych.
        /// </summary>
        /// <param name="sqlConnection">połączenie z bazą SQL</param>
        /// <param name="sqlDataAdapter">zmienna do komunikacji z bazą danych</param>
        /// <param name="dataGridView">kontrolka do wypełnienia danymi</param>
        public static void GetAllDeliverers(SqlConnection sqlConnection, SqlDataAdapter sqlDataAdapter, DataGridView dataGridView)
        {
            dataGridView.DataSource = null;
            sqlDataAdapter = new SqlDataAdapter("Select ID, SupervisorID as Przełożony, CarID as Samochód, Name as Imię, Surname as Nazwisko, Age as Wiek, Sex as Płeć, Salary as Pensja from Deliverers", sqlConnection);
            DataTable dataTable = new DataTable();
            sqlDataAdapter.Fill(dataTable);
            dataGridView.DataSource = dataTable;
        }

        /// <summary>
        /// Statyczna metoda pozwalająca na pobranie wszystkich dostawców bez auta z bazy danych.
        /// </summary>
        /// <param name="sqlConnection">połączenie z bazą SQL</param>
        /// <param name="sqlDataAdapter">zmienna do komunikacji z bazą danych</param>
        /// <param name="dataGridView">kontrolka do wypełnienia danymi</param>
        public static void GetDeliverersWithoutCar(SqlConnection sqlConnection, SqlDataAdapter sqlDataAdapter, DataGridView dataGridView)
        {
            dataGridView.DataSource = null;
            sqlDataAdapter = new SqlDataAdapter("Select SupervisorID as Przełożony, Name as Imię, Surname as Nazwisko, Age as Wiek, Sex as Płeć, Salary as Pensja from Deliverers where CarID IS NULL", sqlConnection);
            DataTable dataTable = new DataTable();
            sqlDataAdapter.Fill(dataTable);
            dataGridView.DataSource = dataTable;
        }

        /// <summary>
        /// Statyczna metoda pozwalająca na pobranie wszystkich dostaw wybranego dostawcy z bazy danych.
        /// </summary>
        /// <param name="sqlConnection">połączenie z bazą SQL</param>
        /// <param name="sqlDataAdapter">zmienna do komunikacji z bazą danych</param>
        /// <param name="dataGridView">kontrolka do wypełnienia danymi</param>
        public static void GetDelivererDeliveries(SqlConnection sqlConnection, SqlDataAdapter sqlDataAdapter, DataGridView dataGridView, int delivererID)
        {
            dataGridView.DataSource = null;
            sqlDataAdapter = new SqlDataAdapter("SELECT d.TransactionID as Zamówienie, d.DeliveryDistance as Odległość, d.DeliveryCost as Koszt, dr.Name as Imię, dr.Surname as Nazwisko from Deliveries d, Deliverers dr where d.DelivererID = " + delivererID.ToString() + " and dr.ID = " + delivererID.ToString(), sqlConnection);
            DataTable dataTable = new DataTable();
            sqlDataAdapter.Fill(dataTable);
            dataGridView.DataSource = dataTable;
        }
    }
}
