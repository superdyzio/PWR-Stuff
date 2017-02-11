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
    public class Employee
    {
        public static void GetAllEmployees(SqlConnection sqlConnection, SqlDataAdapter sqlDataAdapter, DataGridView dataGridView)
        {
            dataGridView.DataSource = null;
            // sqlDAtaAdapter tutaj niepotrzebne, ale trzeba dawać bo ogólnie czasami może być wykorzystane
            sqlDataAdapter = new SqlDataAdapter("Select ID, Name as Imię, Surname as Nazwisko, Age as Wiek from Employees",sqlConnection);
            DataTable dataTable = new DataTable();
            sqlDataAdapter.Fill(dataTable);
            dataGridView.DataSource = dataTable;
        }
    }
}
