using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DawidPerdekLab4.Model
{
    public class Student : Entity
    {
        public string Name { get; set; }
        public string Surname { get; set; }
        public string Index { get; set; }
        public IList<Grade> Grades { get; set; }        // relacja jeden do wielu
        public virtual Address Address { get; set; }            // relacja jeden do jednego

        public Student()
        {
            Grades = new List<Grade>();
        }
    }
}
