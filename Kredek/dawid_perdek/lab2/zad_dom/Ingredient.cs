using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DawidPerdekZad2
{
    public class Ingredient
    {
        public String name; // nazwa
        bool isMeat;        // true - składnik mięsny, false - składnik nie jest mięsem

        public Ingredient(String name, bool isMeat)
        {
            this.name = name;
            this.isMeat = isMeat;
        }

        /// <summary>
        /// Getter dla pola isMeat.
        /// </summary>
        /// <returns>Zwraca wartość pola isMeat.</returns>
        public bool getIsMeat()
        {
            return isMeat;
        }
    }
}
