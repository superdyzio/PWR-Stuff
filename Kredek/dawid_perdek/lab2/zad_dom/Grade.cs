using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DawidPerdekZad2
{
    public class Grade
    {
        public double Value { get; set; }   // wartość
        public String Name { get; set; }    // opis oceny

        public Grade(double grade, String name)
        {
            Value = grade;
            Name = name;
        }
    }
}
