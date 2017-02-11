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
    public partial class FormRemoveMeal : Form
    {
        FormHomework1Main parentForm;   // okno wywołujące te okno

        public FormRemoveMeal(FormHomework1Main parentForm)
        {
            InitializeComponent();
            this.parentForm = parentForm;
            listBoxRemoveMeal.DataSource = parentForm.getListOfMealsNames();
        }

        private void buttonCancelRemoveMeal_Click(object sender, EventArgs e)
        {
            parentForm.setListOfMealsDataSource();
            this.Close();
        }

        private void buttonRemoveMeal_Click(object sender, EventArgs e)
        {
            parentForm.listOfMeals.Remove(parentForm.listOfMeals.ElementAt(listBoxRemoveMeal.SelectedIndex));
            parentForm.changes = true;
            parentForm.setListOfMealsDataSource();
            this.Close();
        }
    }
}
