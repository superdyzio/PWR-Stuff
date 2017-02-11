using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SqlClient;
using DawidPerdekLab3.Model;

// każdy folder ma swojego namespace - trzeba dołączać poprzez 'using'

namespace DawidPerdekLab3.View
{
    public partial class FormMain : Form
    {
        SqlConnection sqlConnection;
        SqlDataAdapter sqlDataAdapter;

        public FormMain()
        {
            InitializeComponent();
            // jakby nie działało z 'localhost' to trzeba wstawić nazwę swojego serwera
            sqlConnection = new SqlConnection("Data Source = localhost; database = DawidPerdekComputerService; Trusted_Connection = yes");
        }

        private void buttonGetEmployees_Click(object sender, EventArgs e)
        {
            // wywołanie funkcji statycznej
            Employee.GetAllEmployees(sqlConnection, sqlDataAdapter, dataGridViewEmployees);
        }

        private void buttonGetServices_Click(object sender, EventArgs e)
        {
            int cost;
            try
            {
                cost = int.Parse(textBoxServiceCost.Text);
            }
            catch
            {
                cost = 0;
            }
            Service.GetServices(sqlConnection, sqlDataAdapter, dataGridViewServices, cost);
        }
    }
}
