using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DawidPerdekZad2
{
    public partial class FormMain : Form
    {
        public FormMain()
        {
            InitializeComponent();
        }

        private void buttonHomework0_Click(object sender, EventArgs e)
        {
            FormHomework0Main formHomework0Main = new FormHomework0Main();
            formHomework0Main.Show();
        }

        private void buttonHomework1_Click(object sender, EventArgs e)
        {
            FormHomework1Main formHomework1Main = new FormHomework1Main();
            formHomework1Main.Show();
        }
    }
}
