using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DawidPerdekLab2
{
    public partial class FormMain : Form
    {
        Person person;
        HiperPerson hiperPerson;
        List<Person> listOfPeople;

        public FormMain()
        {
            InitializeComponent();
            person = new Person("Dawid","Perdek",22);
            hiperPerson = new HiperPerson("Dawid", "Perdek", 22, 6);
            listOfPeople = new List<Person>(10);
            listOfPeople.Add(person);
            listOfPeople.Add(new Person("Andrzej", "Kowalski", 30));
            listOfPeople.Add(new Person("Krystian", "Jakubiszyn", 22));
            listOfPeople.Add(new Person("Rafał", "Ilmak", 24));
            listOfPeople.Add(new Person("Bogdan", "Nowak", 26));
            listOfPeople.Add(new Person("Mieszko", "Rado", 17));
            listOfPeople.Add(new Person("Ziemowit", "Koprowski", 33));
            listOfPeople.Add(new Person("Bogusz", "Kott", 40));
            listOfPeople.Add(new Person("Mateusz", "Kruk", 45));
            listOfPeople.Add(new Person("Mateusz", "Kubanek", 25));
        }

        private void buttonShowPerson_Click(object sender, EventArgs e)
        {
            MessageBox.Show(person.Name + " " + person.Surname + " - " + person.Age.ToString());
        }

        private void buttonShowHiperPerson_Click(object sender, EventArgs e)
        {
            MessageBox.Show(hiperPerson.Name + " " + hiperPerson.Surname + " - " + hiperPerson.Age.ToString() + " - " + hiperPerson.GetAmountOfHands().ToString());
        }

        private void buttonShow_Click(object sender, EventArgs e)
        {
            dataGridViewListOfPeople.DataSource = null;
            dataGridViewListOfPeople.DataSource = listOfPeople;
            dataGridViewGrades.DataSource = null;
            if (dataGridViewListOfPeople.CurrentCell != null)
                dataGridViewGrades.DataSource = listOfPeople[dataGridViewListOfPeople.CurrentCell.RowIndex].listOfGrades;
            else
            {
                MessageBox.Show("Wybierz osobę z tabeli!"); // nigdy się nie wykonuje, bo po wyświetleniu danych automatycznie zaznaczana jest komórka (0,0)
            }
            bool happy = true;
            for (int i = 0; i < listOfPeople[dataGridViewListOfPeople.CurrentCell.RowIndex].listOfGrades.Count && happy; i++)
            {
                if (listOfPeople[dataGridViewListOfPeople.CurrentCell.RowIndex].listOfGrades[i].Value < 3.0)
                    happy = false;
            }
            if (happy)
                pictureBoxGrades.Image = Properties.Resources.happy;
            else
                pictureBoxGrades.Image = Properties.Resources.sad;
        }

        private void buttonAddPerson_Click(object sender, EventArgs e)
        {
            listOfPeople.Add(new Person(textBoxNewPersonName.Text, textBoxNewPersonSurname.Text, int.Parse(textBoxNewPersonAge.Text)));
        }

        private void buttonAddGrade_Click(object sender, EventArgs e)
        {
            listOfPeople[dataGridViewListOfPeople.CurrentCell.RowIndex].listOfGrades.Add(new Grade(double.Parse(textBoxGrade.Text),"nowa ocena"));
        }
    }
}
