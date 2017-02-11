using System;
using System.Collections.Generic;
using System.Data.Entity;
using System.Linq;
using System.Web;

namespace DawidPerdekLab5.Models
{
    public class EFDbContext : DbContext
    {
        public DbSet<Pizza> Pizzas { get; set; }
    }
}