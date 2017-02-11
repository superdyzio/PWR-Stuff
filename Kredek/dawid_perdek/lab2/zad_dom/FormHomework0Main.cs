using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace DawidPerdekZad2
{
    public partial class FormHomework0Main : Form
    {
        List<Person> listOfPeople;  // lista osób
        bool happyFace;             // true - brak ocen poniżej 3.0 -> buźka uśmiechnięta; false - są oceny poniżej 3.0 -> buźka smutna

        public FormHomework0Main()
        {
            InitializeComponent();
            listOfPeople = new List<Person>();
            labelPersonChangesIndicator.Hide();
        }

        public void addPerson(Person person)
        {
            listOfPeople.Add(person);
            labelPersonChangesIndicator.Show();
        }

        private void buttonAddPerson_Click(object sender, EventArgs e)
        {
            FormAddingPerson formAddingPerson = new FormAddingPerson(this);
            formAddingPerson.ShowDialog();
        }

        private void buttonPersonOpenFile_Click(object sender, EventArgs e)
        {
            Stream fileStream;
            OpenFileDialog openFileDialog = new OpenFileDialog();
            openFileDialog.Filter = "Text Files |*.txt|All Files |*.*";
            openFileDialog.ShowDialog();
            try
            {
                fileStream = openFileDialog.OpenFile();
            }
            catch
            {
                MessageBox.Show("Nie udało się otworzyć pliku.", "Błędny plik!");
                return;
            }
            StreamReader reader = new StreamReader(fileStream);
            listOfPeople.Clear();
            while (!reader.EndOfStream)
            {
                String line = reader.ReadLine();
                String[] elements = line.Split(' ');
                if (elements.Length >= 3)
                {
                    try
                    {
                        listOfPeople.Add(new Person(elements[0], elements[1], int.Parse(elements[2])));
                        for (int i = 3; i < elements.Length; i += 2)
                            listOfPeople.Last().listOfGrades.Add(new Grade(double.Parse(elements[i]), elements[i+1]));
                    }
                    catch
                    {
                        MessageBox.Show("W pliku zawarta była błędna wartość wieku.", "Błędne dane!");
                    }
                }
                else
                    MessageBox.Show("W pliku zawarte są błędne wpisy.", "Błędne dane!");
            }
            reader.Close();
            fileStream.Close();
            dataGridViewListOfPeople.DataSource = null;
            dataGridViewListOfPeople.DataSource = listOfPeople;
            dataGridViewListOfPeople.CurrentCell = dataGridViewListOfPeople[0, 0];
            dataGridViewListOfGrades.DataSource = null;
            dataGridViewListOfGrades.DataSource = listOfPeople[dataGridViewListOfPeople.CurrentCell.RowIndex].listOfGrades;
            happyFace = true;
            for (int i = 0; i < listOfPeople[dataGridViewListOfPeople.CurrentCell.RowIndex].listOfGrades.Count && happyFace; i++)
            {
                if (listOfPeople[dataGridViewListOfPeople.CurrentCell.RowIndex].listOfGrades[i].Value < 3.0)
                    happyFace = false;
            }
            if (happyFace)
                pictureBoxFace.Image = Properties.Resources.happy;
            else
                pictureBoxFace.Image = Properties.Resources.sad;
            happyFace = false;
        }

        private void buttonPersonSaveFile_Click(object sender, EventArgs e)
        {
            Stream fileStream;
            SaveFileDialog saveFileDialog = new SaveFileDialog();
            saveFileDialog.Filter = "Text Files |*.txt| All Files |*.*";
            saveFileDialog.ShowDialog();
            try
            {
                fileStream = saveFileDialog.OpenFile();
            }
            catch
            {
                MessageBox.Show("Nie udało się otworzyć pliku.", "Błędny plik!");
                return;
            }
            StreamWriter writer = new StreamWriter(fileStream);
            for (int i = 0; i < listOfPeople.Count; i++)
            {
                Person person = listOfPeople.ElementAt(i);
                writer.Write(person.Name + " " + person.Surname + " " + person.Age.ToString());
                for (int j = 0; j < person.listOfGrades.Count; j++)
                    writer.Write(" " + person.listOfGrades.ElementAt(j).Value + " " + person.listOfGrades.ElementAt(j).Name);
                writer.WriteLine();
            }
            writer.Close();
            fileStream.Close();
            labelPersonChangesIndicator.Hide();
        }

        private void buttonAddGrade_Click(object sender, EventArgs e)
        {
            FormAddingPersonGrade formAddingPersonGrade;
            try
            {
                formAddingPersonGrade = new FormAddingPersonGrade(listOfPeople[dataGridViewListOfPeople.CurrentCell.RowIndex]);
                formAddingPersonGrade.ShowDialog();
            }
            catch
            {
                MessageBox.Show("Wczytaj dane osób.", "Brak danych!");
            }
            labelPersonChangesIndicator.Show();
        }

        /// <summary>
        /// Metoda reagująca na zmianę wybranej komórki w DataGridView. Sprawia ona, że po kliknięciu na wiersz danej osoby
        /// jej oceny zostają natychmiast pokazane.
        /// </summary>
        /// <param name="sender">obiekt wywołujacy metodę</param>
        /// <param name="e">argumenty zdarzenia</param>
        private void dataGridViewListOfPeople_CurrentCellChanged(object sender, EventArgs e)
        {
            dataGridViewListOfGrades.DataSource = null;
            try
            {
                dataGridViewListOfGrades.DataSource = listOfPeople[dataGridViewListOfPeople.CurrentCell.RowIndex].listOfGrades;
                happyFace = true;
                for (int i = 0; i < listOfPeople[dataGridViewListOfPeople.CurrentCell.RowIndex].listOfGrades.Count && happyFace; i++)
                {
                    if (listOfPeople[dataGridViewListOfPeople.CurrentCell.RowIndex].listOfGrades[i].Value < 3.0)
                        happyFace = false;
                }
                if (happyFace)
                    pictureBoxFace.Image = Properties.Resources.happy;
                else
                    pictureBoxFace.Image = Properties.Resources.sad;
                happyFace = false;
            }
            catch
            {

            }
        }
    }
}
