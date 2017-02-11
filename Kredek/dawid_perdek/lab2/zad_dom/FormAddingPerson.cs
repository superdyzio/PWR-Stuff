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
    public partial class FormAddingPerson : Form
    {
        FormHomework0Main parentForm;   // okno wywołujące te okno

        public FormAddingPerson(FormHomework0Main parentForm)
        {
            InitializeComponent();
            this.parentForm = parentForm;
        }

        private void buttonCancelPerson_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void buttonConfirmPerson_Click(object sender, EventArgs e)
        {
            int age = -1;
            String name = textBoxNewPersonName.Text;
            String surname = textBoxNewPersonSurname.Text;
            if (name.Equals("") || surname.Equals(""))
            {
                MessageBox.Show("Nie wprowadzono imienia lub nazwiska.","Błędne dane!");
                return;
            }
            try
            {
                age = int.Parse(textBoxNewPersonAge.Text);
                if (age <= 0)
                {
                    MessageBox.Show("Wiek musi być większy od zera.", "Błędne dane!");
                    return;
                }
            }
            catch
            {
                MessageBox.Show("Wprowadź poprawny wiek.", "Błędne dane!");
                return;
            }
            parentForm.addPerson(new Person(name, surname, age));
            this.Close();
        }
    }
}
