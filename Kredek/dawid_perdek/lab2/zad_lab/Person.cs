using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DawidPerdekLab2
{
    class Person
    {
        public String Name { get; set; }
        public String Surname { get; set; }
        public int Age { get; set; }
        public List<Grade> listOfGrades;

        public Person(String name, String surname, int age)
        {
            this.Name = name;
            this.Surname = surname;
            this.Age = age;
            listOfGrades = new List<Grade>();
            listOfGrades.Add(new Grade(5.0, "bardzo dobry "+name));
            listOfGrades.Add(new Grade(4.5, "dobry+ "+surname));
        }
    }
}
