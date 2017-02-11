using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DawidPerdekZad2
{
    public class Burger : Meal
    {
        public String level;   // stopień wysmażenia mięsa - nie znalazłem lepszego słówka (nazewnictwo konsekwentne w całości kodu)

        public Burger(string name, double price, List<Ingredient> listOfIngredients, string description, int weight, String mealPhotoName, int mealIndex, String typeOfMeal, String level) : base(name, price, listOfIngredients, description, weight, mealPhotoName, mealIndex, typeOfMeal)
        {
            this.level = level;
        }
    }
}
