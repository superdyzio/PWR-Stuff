using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DawidPerdekLab2
{
    class HiperPerson : Person
    {
        int amountOfHands;

        public HiperPerson(string name, string surname, int age, int amountOfHands):base(name,surname,age)
        {
            this.amountOfHands = amountOfHands;
        }

        public int GetAmountOfHands()
        {
            return amountOfHands;
        }
    }
}
