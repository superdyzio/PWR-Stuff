using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DawidPerdekLab4.Model
{
    public class Address : Entity
    {
        public string PostCode { get; set; }
        public string City { get; set; }
    }
}
