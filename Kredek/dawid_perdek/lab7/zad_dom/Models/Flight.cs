using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace DawidPerdekZad7.Models
{
    /// <summary>
    /// Klasa modelująca pojedynczy lot.
    /// </summary>
    public class Flight : Entity
    {
        public string CityFrom { get; set; }
        public string CityTo { get; set; }
        public int DepartureTime { get; set; }
        public int ArrivalTime { get; set; }
        public int FreeSeats { get; set; }
        public double Price { get; set; }
    }
}