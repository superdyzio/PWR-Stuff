using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using DawidPerdek.Model;

namespace DawidPerdek
{
    public partial class FormZadA : Form
    {
        private NorthwindContext _context;

        public FormZadA()
        {
            _context = new NorthwindContext();
            InitializeComponent();
        }

        private void buttonSuppliers_Click(object sender, EventArgs e)
        {
            dataGridViewNorthwind.DataSource = null;
        }

        private void buttonProducts_Click(object sender, EventArgs e)
        {
            dataGridViewNorthwind.DataSource = null;
        }

        private void buttonJoin_Click(object sender, EventArgs e)
        {
            dataGridViewProductsAndSuppliers.DataSource = null;
        }

        private void buttonPrices_Click(object sender, EventArgs e)
        {
            dataGridViewNorthwind.DataSource = null;
            double minimalPrice = Double.Parse(textBoxPrice.Text);
        }

        private void buttonPriceChange_Click(object sender, EventArgs e)
        {
            double newPrice = Double.Parse(textBoxChange.Text);
            DataGridView
        }
    }
}
