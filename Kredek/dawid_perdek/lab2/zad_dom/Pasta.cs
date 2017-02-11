using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DawidPerdekZad2
{
    public class Pasta : Meal
    {
        public String pastaType;    // rodzaj makaronu w daniu

        public Pasta(string name, double price, List<Ingredient> listOfIngredients, string description, int weight, String mealPhotoName, int mealIndex, String typeOfMeal, String pastaType) : base(name, price, listOfIngredients, description, weight, mealPhotoName, mealIndex, typeOfMeal)
        {
            this.pastaType = pastaType;
        }
    }
}
