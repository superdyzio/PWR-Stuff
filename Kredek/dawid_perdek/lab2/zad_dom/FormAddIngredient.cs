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
    public partial class FormAddIngredient : Form
    {
        FormHomework1Main parentForm;   // okno wywołujące te okno

        public FormAddIngredient(FormHomework1Main parentForm)
        {
            InitializeComponent();
            this.parentForm = parentForm;
        }

        private void buttonCancelNewIngredient_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void buttonAddNewIngredient_Click(object sender, EventArgs e)
        {
            if (!textBoxNewIngredientName.Text.ToString().Equals(""))
                parentForm.listOfIngredients.Add(new Ingredient(textBoxNewIngredientName.Text.ToString(),checkBoxNewIngredientIsMeat.Checked));
            else
            {
                MessageBox.Show("Wprowadź nazwę składnika.", "Błędne dane!");
                return;
            }
            parentForm.changes = true;
            this.Close();
        }
    }
}
