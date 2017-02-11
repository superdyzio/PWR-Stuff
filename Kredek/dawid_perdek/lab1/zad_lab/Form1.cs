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
    public partial class Form1 : Form
    {
        int number = 0;

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            textBoxOpen.Text = number.ToString();
        }

        private void buttonOpen_Click(object sender, EventArgs e)
        {
            //textBoxOpen.Text = "Otwarte hehe";
            //MessageBox.Show(buttonOpen.Name);
            //MessageBox.Show("Wartość: " + textBoxOpen.Text);
            number += 3;
            if (number > 50)
                number = 0;
            textBoxOpen.Text = number.ToString();
            textBoxOpen.BackColor = Color.FromArgb(number*5, number * 4, number * 3);
            FormNewWindow formNewWindow = new FormNewWindow();
            formNewWindow.lastNumber = Int32.Parse(textBoxOpen.Text);
            formNewWindow.ShowDialog();
        }
    }
}
