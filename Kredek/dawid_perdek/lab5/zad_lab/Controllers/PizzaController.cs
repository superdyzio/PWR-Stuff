using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using DawidPerdekLab5.Models;

namespace DawidPerdekLab5.Controllers
{
    public class PizzaController : Controller
    {
        // GET: Pizza
        public ActionResult Index()
        {
            // zwracamy przekierowanie na inną metodę, która zwróci widok
            return RedirectToAction("List");
        }

        public ActionResult List()
        {
            var pizzas = new List<Pizza>();
            using (var ctx = new EFDbContext())
            {
                pizzas = ctx.Pizzas.ToList();
            }
            return View(pizzas);
        }

        public ActionResult Add()
        {
            return View();
        }

        [HttpPost]
        public ActionResult Add(Pizza model)
        {
            if (!ModelState.IsValid)
            {
                return RedirectToAction("Add");
            }
            using (var ctx = new EFDbContext())
            {
                ctx.Pizzas.Add(model);
                ctx.SaveChanges();
            }
            return RedirectToAction("List");
        }

        public ActionResult Edit(int id)
        {
            Pizza pizza;
            using (var ctx = new EFDbContext())
            {
                pizza = ctx.Pizzas.FirstOrDefault(m => m.Id == id);
            }
            return View(pizza);
        }

        [HttpPost]
        public ActionResult Edit(Pizza model, int id)
        {
            if (!ModelState.IsValid)
            {
                return RedirectToAction("Edit");
            }
            Pizza pizza;
            using (var ctx = new EFDbContext())
            {
                pizza = ctx.Pizzas.FirstOrDefault(m => m.Id == id);
                pizza.Name = model.Name;
                pizza.Ingredients = model.Ingredients;
                ctx.SaveChanges();
            }
            return RedirectToAction("List");
        }
    }
}