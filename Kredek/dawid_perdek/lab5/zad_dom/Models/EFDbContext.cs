﻿using System;
using System.Collections.Generic;
using System.Data.Entity;
using System.Linq;
using System.Web;

namespace DawidPerdekZad5.Models
{
    public class EFDbContext : DbContext
    {
        public DbSet<Pizza> Pizzas { get; set; }
    }
}