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
    public partial class FormAddingPersonGrade : Form
    {
        Person person;  // osoba, której dodawana będzie ocena

        public FormAddingPersonGrade(Person person)
        {
            InitializeComponent();
            this.person = person;
            labelPersonName.Text = this.person.Name + " " + this.person.Surname;
        }

        private void buttonCancelGrade_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void buttonConfirmGrade_Click(object sender, EventArgs e)
        {
            if (textBoxNewGradeName.Text.Length < 1)
            {
                MessageBox.Show("Podaj nazwę oceny", "Błędne dane!");
                return;
            }
            try
            {
                person.listOfGrades.Add(new Grade(double.Parse(textBoxNewGradeValue.Text), textBoxNewGradeName.Text));
            }
            catch
            {
                MessageBox.Show("Podaj prawidłową wartość oceny", "Błędna ocena!");
            }
            this.Close();
        }
    }
}
