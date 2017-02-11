using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DawidPerdekZad2
{
    public class Person
    {
        public String Name { get; set; }        // imie
        public String Surname { get; set; }     // nazwisko
        public int Age { get; set; }            // wiek
        public List<Grade> listOfGrades;        // lista ocen

        public Person(String name, String surname, int age)
        {
            this.Name = name;
            this.Surname = surname;
            this.Age = age;
            listOfGrades = new List<Grade>();
        }
    }
}
