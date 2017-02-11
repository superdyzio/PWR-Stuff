using System;
using System.Windows.Forms;

namespace DawidPerdekZad3.View
{
    /// <summary>
    /// Główny widok aplikacji.
    /// </summary>
    public partial class FormMain : Form
    {
        public FormMain()
        {
            InitializeComponent();
        }

        /// <summary>
        /// Uruchomienie okna zadania 0 w reakcji na wciśnięcie odpowiedniego przycisku.
        /// </summary>
        /// <param name="sender">kontrolka wywołująca zdarzenie</param>
        /// <param name="e">argumenty zdarzenia</param>
        private void buttonStartZad0_Click(object sender, EventArgs e)
        {
            FormMainZad0 formMainZad0 = new FormMainZad0();
            formMainZad0.Show();
        }

        /// <summary>
        /// Uruchomienie okna zadania 1 w reakcji na wciśnięcie odpowiedniego przycisku.
        /// </summary>
        /// <param name="sender">kontrolka wywołująca zdarzenie</param>
        /// <param name="e">argumenty zdarzenia</param>
        private void buttonStartZad1_Click(object sender, EventArgs e)
        {
            FormMainZad1 formMainZad1 = new FormMainZad1();
            formMainZad1.Show();
        }
    }
}
