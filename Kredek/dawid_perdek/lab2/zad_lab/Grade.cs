using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DawidPerdekLab2
{
    class Grade
    {
        public double Value { get; set; }
        public String Name { get; set; }

        public Grade(double grade, String name)
        {
            Value = grade;
            Name = name;
        }
    }
}
