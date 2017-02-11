using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DawidPerdekLab1
{
    public partial class FormNewWindow : Form
    {
        public int lastNumber;

        public FormNewWindow()
        {
            InitializeComponent();
        }

        private void buttonClose_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void buttonShow_Click(object sender, EventArgs e)
        {
            textBoxShow.Text = lastNumber.ToString();
        }

        private void buttonDraw_Click(object sender, EventArgs e)
        {
            int number = 1;
            for (int i = 1; i < 2*lastNumber; i+=2)
            {
                for (int j = 1; j < lastNumber + 1 - number; j++)
                    textBoxDraw.Text += " ";
                for (int j = 0; j < i; j++)
                    //textBoxDraw.Text += number.ToString();
                    textBoxDraw.Text += "x";
                for (int j = 1; j < lastNumber + 1 - number; j++)
                    textBoxDraw.Text += " ";
                textBoxDraw.Text += Environment.NewLine;
                number++;
            }
        }
    }
}
