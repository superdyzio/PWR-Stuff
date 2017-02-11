using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.SqlClient;
using System.Windows.Forms;
using System.Data;

namespace DawidPerdekLab3.Model
{
    public class Service
    {
        public static void GetServices(SqlConnection sqlConnection, SqlDataAdapter sqlDataAdapter, DataGridView dataGridView, int minimalCost)
        {
            dataGridView.DataSource = null;
            // sqlDAtaAdapter tutaj niepotrzebne, ale trzeba dawać bo ogólnie czasami może być wykorzystane
            sqlDataAdapter = new SqlDataAdapter("Select * FROM Services WHERE Cost >= "+minimalCost.ToString(), sqlConnection);
            DataTable dataTable = new DataTable();
            sqlDataAdapter.Fill(dataTable);
            dataGridView.DataSource = dataTable;
        }
    }
}
