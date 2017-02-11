using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DawidPerdekZad1
{
    public partial class FormMain : Form
    {
        public FormMain()
        {
            InitializeComponent();
        }

        private void buttonClassicCalculator_Click(object sender, EventArgs e)
        {
            FormClassicCalculator classicCalculatorWindow = new FormClassicCalculator();
            classicCalculatorWindow.Show();
        }

        private void buttonAdvancedCalculator_Click(object sender, EventArgs e)
        {
            FormAdvancedCalculator advancedCalculatorWindow = new FormAdvancedCalculator();
            advancedCalculatorWindow.Show();
        }
    }
}
