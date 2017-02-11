using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.ComponentModel.DataAnnotations;

namespace DawidPerdekZad5.Models
{
    public class Pizza
    {
        [Key]
        public int PizzaId { get; set; }

        [Display(Name = "Nazwa")]
        public string Name { get; set; }

        [Display(Name = "Składniki")]
        public string Ingredients { get; set; }
    }
}