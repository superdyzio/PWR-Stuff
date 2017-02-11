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
    public partial class FormHomework1Main : Form
    {
        public List<Meal> listOfMeals;              // lista wszystkich posiłków
        public List<Pizza> listOfPizzas;            // lista pizz
        public List<Pasta> listOfPastas;            // lista makaronów
        public List<Burger> listOfBurgers;          // lista burgerów
        public List<Ingredient> listOfIngredients;  // lista składników
        public bool changes;

        public FormHomework1Main()
        {
            InitializeComponent();
            listOfMeals = new List<Meal>();
            listOfPizzas = new List<Pizza>();
            listOfPastas = new List<Pasta>();
            listOfBurgers = new List<Burger>();
            listOfIngredients = new List<Ingredient>();
            labelMealsChangesIndicator.Hide();
            changes = false;
        }

        /// <summary>
        /// Metoda przygotowująca nazwy składników do wstawienia w ListBoxa.
        /// </summary>
        /// <returns>Zwraca listę samych nazw składników.</returns>
        public List<String> getListOfIngredientsNames()
        {
            List<String> names = new List<String>();
            for (int i = 0; i < listOfIngredients.Count; i++)
                names.Add(listOfIngredients.ElementAt(i).name);
            return names;
        }

        /// <summary>
        /// Metoda przygotowująca nazwy posiłków do wstawienia w ListBoxa.
        /// </summary>
        /// <returns>Zwraca listę samych nazw posiłków.</returns>
        public List<String> getListOfMealsNames()
        {
            List<String> names = new List<String>();
            for (int i = 0; i < listOfMeals.Count; i++)
                names.Add(listOfMeals.ElementAt(i).Name);
            return names;
        }

        /// <summary>
        /// Metoda reagująca na zmianę wybranej komórki w DataGridView. Sprawia ona, że wyświetlane
        /// w okienku dane są aktualne i zmieniają się zależnie od wybranego wiersza.
        /// </summary>
        /// <param name="sender">obiekt wywołujący metodę</param>
        /// <param name="e">argumenty zdarzenia</param>
        private void dataGridViewListOfMeals_CurrentCellChanged(object sender, EventArgs e)
        {
            try
            {
                Meal currentMeal = listOfMeals[dataGridViewListOfMeals.CurrentCell.RowIndex];
                textBoxIngredients.Text = currentMeal.getIngredients();
                pictureBoxMealPhoto.Image = (Image)Properties.Resources.ResourceManager.GetObject(currentMeal.mealPhotoName);
                textBoxMealDescription.Text = currentMeal.description;
                if (currentMeal.typeOfMeal.Equals("Burger"))
                {
                    try
                    {
                        textBoxMealDescription.Text += "\r\nStopień wysmażenia: " + findBurger(currentMeal.mealIndex).level;
                    }
                    catch
                    {
                        Console.WriteLine("Brak burgera o podanym indeksie.");
                    }
                }
                if (currentMeal.typeOfMeal.Equals("Makaron"))
                {
                    try
                    {
                        textBoxMealDescription.Text += "\r\nRodzaj makaronu: " + findPasta(currentMeal.mealIndex).pastaType;
                    }
                    catch
                    {
                        Console.WriteLine("Brak makaronu o podanym indeksie.");
                    }
                }
                if (currentMeal.typeOfMeal.Equals("Pizza"))
                {
                    try
                    {
                        textBoxMealDescription.Text += "\r\nGrube ciasto: " + (findPizza(currentMeal.mealIndex).thickCrust ? "tak" : "nie");
                    }
                    catch
                    {
                        Console.WriteLine("Brak pizzy o podanym indeksie.");
                    }
                }
            }
            catch
            {
                Console.WriteLine("Przechwycony wyjątek przy zmianie wybranej komórki.");
            }
        }

        /// <summary>
        /// Metoda sprawdzajaca czy istnieją niezapisane zmiany w listach posiłków i składników.
        /// </summary>
        /// <param name="sender">obiekt wywołujący metodę</param>
        /// <param name="e">argumenty zdarzenia</param>
        private void FormHomework1Main_Activated(object sender, EventArgs e)
        {
            if (changes)
                labelMealsChangesIndicator.Show();
            else
                labelMealsChangesIndicator.Hide();
        }

        /// <summary>
        /// Metoda znajdująca burgera o zadanym indeksie.
        /// </summary>
        /// <param name="mealIndex">indeks szukanego posiłku</param>
        /// <returns>Zwraca szukanego burgera lub wartość null.</returns>
        private Burger findBurger(int mealIndex)
        {
            for (int i = 0; i < listOfBurgers.Count; i++)
                if (listOfBurgers.ElementAt(i).mealIndex == mealIndex)
                    return listOfBurgers.ElementAt(i);
            return null;
        }

        /// <summary>
        /// Metoda znajdująca makaron o zadanym indeksie.
        /// </summary>
        /// <param name="mealIndex">indeks szukanego posiłku</param>
        /// <returns>Zwraca szukany makaron lub wartość null.</returns>
        private Pasta findPasta(int mealIndex)
        {
            for (int i = 0; i < listOfPastas.Count; i++)
                if (listOfPastas.ElementAt(i).mealIndex == mealIndex)
                    return listOfPastas.ElementAt(i);
            return null;
        }

        /// <summary>
        /// Metoda znajdująca pizzę o zadanym indeksie.
        /// </summary>
        /// <param name="mealIndex">indeks szukanego posiłku</param>
        /// <returns>Zwraca szukaną pizzę lub wartość null.</returns>
        private Pizza findPizza(int mealIndex)
        {
            for (int i = 0; i < listOfPizzas.Count; i++)
                if (listOfPizzas.ElementAt(i).mealIndex == mealIndex)
                    return listOfPizzas.ElementAt(i);
            return null;
        }

        /// <summary>
        /// Metoda znajdująca zadany składnik.
        /// </summary>
        /// <param name="name">nazwa szukanego składnika</param>
        /// <returns>Zwraca szukany składnik lub wartość null.</returns>
        private Ingredient findIngredient(String name)
        {
            for (int i = 0; i < listOfIngredients.Count; i++)
                if (listOfIngredients.ElementAt(i).name.Equals(name))
                    return listOfIngredients.ElementAt(i);
            return null;
        }

        /// <summary>
        /// Metoda ustawiająca dane wyświetlane przez DataGridView. Publiczna, by mogły
        /// z niej korzystać potomne okienka.
        /// </summary>
        public void setListOfMealsDataSource()
        {
            dataGridViewListOfMeals.DataSource = listOfMeals;
        }

        /// <summary>
        /// Metoda wczytująca domyślne składniki w przypadku niepowodzenia czytania z pliku.
        /// </summary>
        private void loadDefaultIngredients()
        {
            listOfIngredients.Add(new Ingredient("kurczak", true));
            listOfIngredients.Add(new Ingredient("wołowina", true));
            listOfIngredients.Add(new Ingredient("makaron", false));
            listOfIngredients.Add(new Ingredient("ser", false));
            listOfIngredients.Add(new Ingredient("pieczarki", false));
            listOfIngredients.Add(new Ingredient("rukola", false));
            listOfIngredients.Add(new Ingredient("cebula", false));
            listOfIngredients.Add(new Ingredient("wieprzowina", true));
            listOfIngredients.Add(new Ingredient("pomidory", false));
            listOfIngredients.Add(new Ingredient("sałata", false));
        }

        /// <summary>
        /// Metoda wczytująca składniki z wybranego pliku.
        /// </summary>
        private void loadIngredients()
        {
            Stream fileStream;
            OpenFileDialog openFileDialog = new OpenFileDialog();
            openFileDialog.Filter = "Text Files |*.txt|All Files |*.*";
            openFileDialog.Title = "Wybierz plik z listą składników";
            openFileDialog.ShowDialog();
            try
            {
                fileStream = openFileDialog.OpenFile();
            }
            catch
            {
                Console.WriteLine("Nie udało się wczytać listy składników z pliku.\r\nWczytywanie domyślnej listy.");
                loadDefaultIngredients();
                return;
            }
            StreamReader reader = new StreamReader(fileStream);
            listOfIngredients.Clear();
            while (!reader.EndOfStream)
            {
                String line = reader.ReadLine();
                String[] elements = line.Split(' ');
                if (elements.Length == 2)
                {
                    try
                    {
                        listOfIngredients.Add(new Ingredient(elements[0], Boolean.Parse(elements[1])));
                    }
                    catch
                    {
                        MessageBox.Show("W pliku zawarty był błędny zapis.", "Błędne dane!"); ;
                        loadDefaultIngredients();
                        return;
                    }
                }
                else
                {
                    MessageBox.Show("W pliku zawarte są błędne wpisy.", "Błędne dane!");
                    reader.Close();
                    loadDefaultIngredients();
                    return;
                }
            }
            reader.Close();
            fileStream.Close();
        }

        /// <summary>
        /// Metoda wczytująca posiłki z wybranego pliku.
        /// </summary>
        private void loadMeals()
        {
            Stream fileStream;
            OpenFileDialog openFileDialog = new OpenFileDialog();
            openFileDialog.Filter = "Text Files |*.txt|All Files |*.*";
            openFileDialog.Title = "Wybierz plik z listą posiłków";
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
            listOfMeals.Clear();
            while (!reader.EndOfStream)
            {
                String line = reader.ReadLine();
                String[] elements = line.Split('-');
                elements[0] = elements[0].Substring(0, elements[0].Length - 1);
                for (int i = 1; i < elements.Length - 1; i++)
                    elements[i] = elements[i].Substring(1, elements[i].Length - 2);
                elements[elements.Length - 1] = elements[elements.Length - 1].Substring(1, elements[elements.Length - 1].Length - 1);
                if (elements.Length >= 9)
                {
                    try
                    {
                        String mealName = elements[0];
                        double mealPrice = double.Parse(elements[1]);
                        String mealDescription = elements[2];
                        int mealWeight = int.Parse(elements[3]);
                        String mealPhotoName = elements[4];
                        int mealIndex = int.Parse(elements[5]);
                        String mealType = elements[6];
                        String burgerLevel, pastaType;
                        bool pizzaThickCrust;
                        List<Ingredient> mealIngredients = new List<Ingredient>();
                        for (int i = 8; i < elements.Length; i++)
                            mealIngredients.Add(findIngredient(elements[i]));
                        if (mealType.Equals("Burger"))
                        {
                            burgerLevel = elements[7];
                            listOfBurgers.Add(new Burger(mealName, mealPrice, mealIngredients, mealDescription, mealWeight, mealPhotoName, mealIndex, mealType, burgerLevel));
                            listOfMeals.Add(listOfBurgers.Last());
                        }
                        if (mealType.Equals("Makaron"))
                        {
                            pastaType = elements[7];
                            listOfPastas.Add(new Pasta(mealName, mealPrice, mealIngredients, mealDescription, mealWeight, mealPhotoName, mealIndex, mealType, pastaType));
                            listOfMeals.Add(listOfPastas.Last());
                        }
                        if (mealType.Equals("Pizza"))
                        {
                            pizzaThickCrust = Boolean.Parse(elements[7]);
                            listOfPizzas.Add(new Pizza(mealName, mealPrice, mealIngredients, mealDescription, mealWeight, mealPhotoName, mealIndex, mealType, pizzaThickCrust));
                            listOfMeals.Add(listOfPizzas.Last());
                        }
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
        }

        /// <summary>
        /// Metoda zapisująca posiłki do wybranego pliku.
        /// </summary>
        private void saveMeals()
        {
            Stream fileStream;
            SaveFileDialog saveFileDialog = new SaveFileDialog();
            saveFileDialog.Filter = "Text Files |*.txt|All Files |*.*";
            saveFileDialog.Title = "Wybierz plik z listą posiłków";
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
            for (int i = 0; i < listOfMeals.Count; i++)
            {
                Meal meal = listOfMeals.ElementAt(i);
                String line = meal.Name + " - " + meal.Price + " - " + meal.description + " - " + meal.Weight + " - " + meal.mealPhotoName + " - " + meal.mealIndex + " - " + meal.typeOfMeal;
                if (meal.typeOfMeal.Equals("Burger"))
                {
                    line += " - " + findBurger(meal.mealIndex).level;
                }
                if (meal.typeOfMeal.Equals("Makaron"))
                {
                    line += " - " + findPasta(meal.mealIndex).pastaType;
                }
                if (meal.typeOfMeal.Equals("Pizza"))
                {
                    line += " - " + findPizza(meal.mealIndex).thickCrust;
                }
                for (int j = 0; j < meal.listOfIngredients.Count; j++)
                    line += " - " + findIngredient(meal.listOfIngredients.ElementAt(j).name).name;
                writer.WriteLine(line);
            }
            writer.Close();
            fileStream.Close();
        }

        /// <summary>
        /// Metoda zapisująca składniki do wybranego pliku.
        /// </summary>
        private void saveIngredients()
        {
            Stream fileStream;
            SaveFileDialog saveFileDialog = new SaveFileDialog();
            saveFileDialog.Filter = "Text Files |*.txt|All Files |*.*";
            saveFileDialog.Title = "Wybierz plik z listą składników";
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
            for (int i = 0; i < listOfIngredients.Count; i++)
            {
                Ingredient ingredient = listOfIngredients.ElementAt(i);
                String line = ingredient.name + " " + ingredient.getIsMeat();
                writer.WriteLine(line);
            }
            writer.Close();
            fileStream.Close();
        }

        private void buttonMealsOpenFile_Click(object sender, EventArgs e)
        {
            loadIngredients();
            loadMeals();
            dataGridViewListOfMeals.DataSource = null;
            dataGridViewListOfMeals.DataSource = listOfMeals;
            changes = false;
            labelMealsChangesIndicator.Hide();
        }

        private void buttonMealsSaveFile_Click(object sender, EventArgs e)
        {
            saveIngredients();
            saveMeals();
            changes = false;
            labelMealsChangesIndicator.Hide();
        }

        private void buttonAddMeal_Click(object sender, EventArgs e)
        {
            FormAddingMeal formAddingMeal = new FormAddingMeal(this);
            formAddingMeal.Show();
        }

        private void buttonAddIngredient_Click(object sender, EventArgs e)
        {
            FormAddIngredient formAddIngredient = new FormAddIngredient(this);
            formAddIngredient.Show();
        }

        private void buttonRemoveIngredient_Click(object sender, EventArgs e)
        {
            FormRemoveIngredient formRemoveIngredient = new FormRemoveIngredient(this);
            formRemoveIngredient.Show();
        }

        private void buttonRemoveMeal_Click(object sender, EventArgs e)
        {
            FormRemoveMeal formRemoveMeal = new FormRemoveMeal(this);
            formRemoveMeal.Show();
            dataGridViewListOfMeals.DataSource = null;
        }
    }
}
