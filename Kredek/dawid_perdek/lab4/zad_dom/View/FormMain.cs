using System;
using System.Windows.Forms;
using Ninject;

namespace DawidPerdekZad4.View
{
    /// <summary>
    /// Widok startowy aplikacji - główne okno.
    /// </summary>
    public partial class FormMain : Form
    {
        private readonly IKernel _kernel;

        public FormMain(IKernel kernel)
        {
            _kernel = kernel;
            InitializeComponent();
        }

        private void buttonNewGame_Click(object sender, EventArgs e)
        {   // wybór nowej gry
            Form form = _kernel.Get<FormStartNewGame>();
            form.Show();
        }

        private void buttonLoadGame_Click(object sender, EventArgs e)
        {   // wybór wczytania gry
            try
            {
                Form form = _kernel.Get<FormGame>();
                form.Show();
            }
            catch
            {   // zabezpieczenie możliwości, że baza danych jest pusta
                MessageBox.Show("Nie masz zapisanej gry.", "Błąd!");
            }
        }
    }
}
