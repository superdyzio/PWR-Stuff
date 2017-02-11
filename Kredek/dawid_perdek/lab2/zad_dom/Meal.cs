using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace DawidPerdekZad2
{
    public class Meal
    {
        public String Name { get; set; }            // nazwa
        public double Price { get; set; }           // cena
        public List<Ingredient> listOfIngredients;  // lista składników
        public String description, mealPhotoName;   // opis dania oraz nazwa odpowiedniego zdjęcia
        public bool VegeMeal { get; set; }          // true - posiłek bezmięsny, false - z mięsem
        public int Weight { get; set; }             // waga porcji
        public int mealIndex;                       // indeks dania
        public String typeOfMeal;                   // typ dania - burger / pizza / makaron

        public Meal(String name, double price, List<Ingredient> listOfIngredients, String description, int weight, String mealPhotoName, int mealIndex, String typeOfMeal)
        {
            Name = name;
            Price = price;
            this.description = description;
            Weight = weight;
            this.listOfIngredients = listOfIngredients;
            this.mealPhotoName = mealPhotoName;
            this.mealIndex = mealIndex;
            this.typeOfMeal = typeOfMeal;
            VegeMeal = isVegetarian();
        }

        /// <summary>
        /// Funkcja wyznacza na podstawie listy składników czy dane danie jest wegetariańskie.
        /// </summary>
        /// <returns>True - danie wegetariańskie, False - z mięsem</returns>
        public bool isVegetarian()
        {
            for (int i = 0; i < listOfIngredients.Count; i++)
                if (listOfIngredients.ElementAt(i).getIsMeat())
                    return false;
            return true;
        }

        /// <summary>
        /// Funkcja służy do przygotowania nazw składników do wyświetlania w komponencie TextBox.
        /// </summary>
        /// <returns>Zwraca nazwy wszystkich składników dania sformatowane w jednego Stringa.</returns>
        public String getIngredients()
        {
            String ingredients = "";
            for (int i = 0; i < listOfIngredients.Count; i++)
            {
                if (i == 0)
                {
                    ingredients = listOfIngredients.ElementAt(0).name;
                    if (listOfIngredients.Count > 1)
                        ingredients += ", ";
                }
                else
                    ingredients += " " + listOfIngredients.ElementAt(i).name;
                if (i > 0 && i < listOfIngredients.Count - 1)
                    ingredients += ",";
            }
            return ingredients;
        }
    }
}
