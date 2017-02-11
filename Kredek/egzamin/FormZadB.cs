using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DawidPerdek
{
    public partial class FormZadB : Form
    {
        public FormZadB()
        {
            InitializeComponent();
        }

        private void buttonCount_Click(object sender, EventArgs e)
        {
            if (textBoxInput.Text.IndexOf("#") == -1)
            {
                MessageBox.Show("Brak znaku '#' we wprowadzonym tekście.");
            }
            else
            {
                MessageBox.Show("Znak '#' pojawia się " + textBoxInput.Text.Count(x => x == '#') + " raz(y).");
            }
        }

        private void buttonSmallerForm_Click(object sender, EventArgs e)
        {
            if (this.Width == 255)
                MessageBox.Show("Nie można już zwężyć okienka.", "Błąd!");
            else
            this.Width = Convert.ToInt32(Math.Round(this.Width * 0.9));
        }

        private void buttonBiggerForm_Click(object sender, EventArgs e)
        {
            if (this.Width == 800)
                MessageBox.Show("Nie można już poszerzyć okienka.", "Błąd!");
            else
                this.Width = Convert.ToInt32(Math.Round(this.Width * 1.1));
        }

        private void buttonProgressBar_Click(object sender, EventArgs e)
        {
            progressBarTimer.Value = 200;
            progressBarTimer.Show();
            timerProgressBar.Start();
        }

        private void timerProgressBar_Tick(object sender, EventArgs e)
        {
            if (progressBarTimer.Value > 0)
                progressBarTimer.Value -= 1;
            else
            {
                progressBarTimer.Value = 0;
                timerProgressBar.Stop();
            }
        }

        private void buttonFormZadA_Click(object sender, EventArgs e)
        {
            FormZadA formZadA = new FormZadA();
            formZadA.Show();
        }
    }
}
