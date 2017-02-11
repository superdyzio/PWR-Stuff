using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DawidPerdekLab4.Model
{
    public class Grade : Entity
    {
        public float Value { get; set; }
        public int StudentId { get; set; }
    }
}
