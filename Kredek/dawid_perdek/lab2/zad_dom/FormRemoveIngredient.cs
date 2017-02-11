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
    public partial class FormRemoveIngredient : Form
    {
        FormHomework1Main parentForm;   // okno wywołujące te okno

        public FormRemoveIngredient(FormHomework1Main parentForm)
        {
            InitializeComponent();
            this.parentForm = parentForm;
            listBoxRemoveIngredient.DataSource = parentForm.getListOfIngredientsNames();
        }

        private void buttonCancelRemoveIngredient_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void buttonRemoveIngredient_Click(object sender, EventArgs e)
        {
            parentForm.listOfIngredients.Remove(parentForm.listOfIngredients.ElementAt(listBoxRemoveIngredient.SelectedIndex));
            parentForm.changes = true;
            this.Close();
        }
    }
}
