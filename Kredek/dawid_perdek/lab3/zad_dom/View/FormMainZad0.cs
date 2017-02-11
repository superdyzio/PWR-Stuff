using System;
using System.Data.SqlClient;
using System.Windows.Forms;
using DawidPerdekZad3.Model.Zad0;

namespace DawidPerdekZad3.View
{
    /// <summary>
    /// Główny widok zadania 0.
    /// </summary>
    public partial class FormMainZad0 : Form
    {
        SqlConnection sqlConnection;    // zmienna reprezentująca połączenie z bazą danych
        SqlDataAdapter sqlDataAdapter;  // zmienna służąca do komunikacji z bazą danych

        public FormMainZad0()
        {
            InitializeComponent();
            sqlConnection = new SqlConnection("Data Source = localhost; database = DawidPerdekComputerService; Trusted_Connection = yes");
        }

        /// <summary>
        /// Wyświetlenie w DataGridView danych z odpowiedniej tabeli w reakcji na wciśnięcie konkretnego przycisku.
        /// </summary>
        /// <param name="sender">kontrolka wywołująca zdarzenie</param>
        /// <param name="e">argumenty zdarzenia</param>
        private void buttonShowClients_Click(object sender, EventArgs e)
        {
            Client.GetAllClients(sqlConnection, sqlDataAdapter, dataGridViewDataFromDatabase);
        }

        /// <summary>
        /// Wyświetlenie w DataGridView danych z odpowiedniej tabeli w reakcji na wciśnięcie konkretnego przycisku.
        /// </summary>
        /// <param name="sender">kontrolka wywołująca zdarzenie</param>
        /// <param name="e">argumenty zdarzenia</param>
        private void buttonShowComputers_Click(object sender, EventArgs e)
        {
            Computer.GetAllComputers(sqlConnection, sqlDataAdapter, dataGridViewDataFromDatabase);
        }

        /// <summary>
        /// Wyświetlenie w DataGridView danych z odpowiedniej tabeli w reakcji na wciśnięcie konkretnego przycisku.
        /// </summary>
        /// <param name="sender">kontrolka wywołująca zdarzenie</param>
        /// <param name="e">argumenty zdarzenia</param>
        private void buttonShowEmployees_Click(object sender, EventArgs e)
        {
            Employee.GetAllEmployees(sqlConnection, sqlDataAdapter, dataGridViewDataFromDatabase);
        }

        /// <summary>
        /// Wyświetlenie w DataGridView danych z odpowiedniej tabeli w reakcji na wciśnięcie konkretnego przycisku.
        /// </summary>
        /// <param name="sender">kontrolka wywołująca zdarzenie</param>
        /// <param name="e">argumenty zdarzenia</param>
        private void buttonShowServices_Click(object sender, EventArgs e)
        {
            Service.GetAllServices(sqlConnection, sqlDataAdapter, dataGridViewDataFromDatabase);
        }

        /// <summary>
        /// Wyświetlenie w DataGridView wybranych danych z odpowiedniej tabeli w reakcji na wciśnięcie konkretnego przycisku.
        /// </summary>
        /// <param name="sender">kontrolka wywołująca zdarzenie</param>
        /// <param name="e">argumenty zdarzenia</param>
        private void buttonShowServicesWithMinimalCost_Click(object sender, EventArgs e)
        {
            int cost;
            try
            {
                cost = int.Parse(textBoxMinimalServiceCost.Text);
                if (cost < 0)
                {
                    textBoxMinimalServiceCost.Text = "0";
                    cost = 0;
                }
            }
            catch
            {
                cost = 0;
                textBoxMinimalServiceCost.Text = "0";
            }
            Service.GetServicesWithMinimalCost(sqlConnection, sqlDataAdapter, dataGridViewDataFromDatabase, cost);
        }
    }
}
