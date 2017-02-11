using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DawidPerdekZad2
{
    public class Pizza : Meal
    {
        public bool thickCrust;     // true - ciasto grube, false - ciasto cienkie

        public Pizza(string name, double price, List<Ingredient> listOfIngredients, string description, int weight, String mealPhotoName, int mealIndex, String typeOfMeal, bool thickCrust) : base(name, price, listOfIngredients, description, weight, mealPhotoName, mealIndex, typeOfMeal)
        {
            this.thickCrust = thickCrust;
        }
    }
}
