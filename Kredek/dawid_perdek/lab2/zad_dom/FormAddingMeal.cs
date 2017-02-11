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
    public partial class FormAddingMeal : Form
    {
        FormHomework1Main parentForm;   // okno wywołujące te okno

        public FormAddingMeal(FormHomework1Main parentForm)
        {
            InitializeComponent();
            this.parentForm = parentForm;
            listBoxNewMealType.DataSource = new List<String> { "Burger", "Makaron", "Pizza" };  // lista dostępnych typów dania
            listBoxNewMealIngredients.DataSource = null;
            listBoxNewMealIngredients.DataSource = parentForm.getListOfIngredientsNames();      // lista składników
            listBoxNewBurgerLevel.DataSource = new List<String> { "Słabo", "Średnio", "Mocno" };    // lista dostępnych cech burgera
            listBoxNewPastaType.DataSource = new List<String> { "Kokardki", "Świderki", "Spaghetti" };  // lista dostępnych typów makaronu
        }

        private void buttonCancelMealAdding_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        /// <summary>
        /// Metoda w reakcji na opuszczenie pola przeznaczone do wpisywania nazwy obrazka dla dania ustawia podgląd obrazka o wprowadzonej nazwie.
        /// W przypadku braku obrazka o danej nazwie nic nie jest wyświetlane.
        /// </summary>
        /// <param name="sender">obiekt wywołujący metodę</param>
        /// <param name="e">argumenty zdarzenia</param>
        private void textBoxNewMealPhoto_Leave(object sender, EventArgs e)
        {
            pictureBoxNewMealPicture.Image = (Image) Properties.Resources.ResourceManager.GetObject(textBoxNewMealPhoto.Text.ToString());
        }

        /// <summary>
        /// Metoda reagująca na zmianę zaznaczonej pozycji w polu do wyboru typu dania.
        /// </summary>
        /// <param name="sender">obiekt wywołujący metodę</param>
        /// <param name="e">argumenty zdarzenia</param>
        private void listBoxNewMealType_SelectedIndexChanged(object sender, EventArgs e)
        {
            switch (listBoxNewMealType.SelectedIndex)
            {
                case 0:
                    switchToBurger();
                    break;
                case 1:
                    switchToPasta();
                    break;
                case 2:
                    switchToPizza();
                    break;
            }
        }

        /// <summary>
        /// Metoda przygotowująca okienko do zdefiniowania burgera.
        /// </summary>
        private void switchToBurger()
        {
            labelNewBurgerLevel.Show();
            listBoxNewBurgerLevel.Show();
            labelNewPastaType.Hide();
            listBoxNewPastaType.Hide();
            checkBoxNewPizzaThickCrust.Hide();
        }

        /// <summary>
        /// Metoda przygotowująca okienko do zdefiniowania dania makaronowego.
        /// </summary>
        private void switchToPasta()
        {
            labelNewBurgerLevel.Hide();
            listBoxNewBurgerLevel.Hide();
            labelNewPastaType.Show();
            listBoxNewPastaType.Show();
            checkBoxNewPizzaThickCrust.Hide();
        }

        /// <summary>
        /// Metoda przygotowująca okienko do zdefiniowania pizzy.
        /// </summary>
        private void switchToPizza()
        {
            labelNewBurgerLevel.Hide();
            listBoxNewBurgerLevel.Hide();
            labelNewPastaType.Hide();
            listBoxNewPastaType.Hide();
            checkBoxNewPizzaThickCrust.Show();
        }

        private void buttonConfirmMealAdding_Click(object sender, EventArgs e)
        {
            String mealName = textBoxNewMealName.Text.ToString();
            String mealType = listBoxNewMealType.SelectedItem.ToString();
            String mealDescription = textBoxNewMealDescription.Text.ToString();
            String mealPhotoName = textBoxNewMealPhoto.Text.ToString();
            int mealIndex = parentForm.listOfMeals.Count;
            List<Ingredient> mealIngredients = new List<Ingredient>();
            String burgerLevel = listBoxNewBurgerLevel.SelectedItem.ToString();
            String pastaType = listBoxNewPastaType.SelectedItem.ToString();
            bool pizzaThickCrust = checkBoxNewPizzaThickCrust.Checked;
            double mealPrice;
            int mealWeight;
            try
            {
                mealPrice = double.Parse(textBoxNewMealPrice.Text.ToString());
                mealWeight = int.Parse(textBoxNewMealWeight.Text.ToString());
            }
            catch
            {
                MessageBox.Show("Wprowadzono błędną cenę lub wagę.", "Błędne dane!");
                return;
            }
            for (int i = 0; i < parentForm.listOfIngredients.Count; i++)
                if (listBoxNewMealIngredients.GetSelected(i))
                    mealIngredients.Add(parentForm.listOfIngredients.ElementAt(i));
            switch(listBoxNewMealType.SelectedIndex)
            {
                case 0:
                    parentForm.listOfBurgers.Add(new Burger(mealName,mealPrice,mealIngredients,mealDescription,mealWeight,mealPhotoName,mealIndex,mealType,burgerLevel));
                    parentForm.listOfMeals.Add(parentForm.listOfBurgers.Last());
                    break;
                case 1:
                    parentForm.listOfPastas.Add(new Pasta(mealName, mealPrice, mealIngredients, mealDescription, mealWeight, mealPhotoName, mealIndex, mealType, pastaType));
                    parentForm.listOfMeals.Add(parentForm.listOfPastas.Last());
                    break;
                case 2:
                    parentForm.listOfPizzas.Add(new Pizza(mealName, mealPrice, mealIngredients, mealDescription, mealWeight, mealPhotoName, mealIndex, mealType, pizzaThickCrust));
                    parentForm.listOfMeals.Add(parentForm.listOfPizzas.Last());
                    break;
            }
            parentForm.changes = true;
            this.Close();
        }
    }
}
