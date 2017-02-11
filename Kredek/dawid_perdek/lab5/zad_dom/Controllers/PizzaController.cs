using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using DawidPerdekZad5.Models;

namespace DawidPerdekZad5.Controllers
{
    public class PizzaController : Controller
    {
        static List<Pizza> cart = new List<Pizza>();

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
                pizza = ctx.Pizzas.FirstOrDefault(m => m.PizzaId == id);
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
                pizza = ctx.Pizzas.FirstOrDefault(m => m.PizzaId == id);
                pizza.Name = model.Name;
                pizza.Ingredients = model.Ingredients;
                ctx.SaveChanges();
            }
            return RedirectToAction("List");
        }

        /// <summary>
        /// Metoda obsługująca akcje dla konkretnej pizzy wywołane z poziomu widoku listy.
        /// </summary>
        /// <param name="id">numer id pizzy</param>
        /// <param name="action">typ akcji: 0 - usuwanie, 1 - dodanie do koszyka</param>
        /// <returns></returns>
        [HttpPost]
        public ActionResult List(int id, int action)
        {
            if (!ModelState.IsValid)
            {
                return RedirectToAction("List");
            }
            Pizza pizza;
            using (var ctx = new EFDbContext())
            {
                pizza = ctx.Pizzas.FirstOrDefault(m => m.PizzaId == id);
                if (action == 0)
                {
                    ctx.Pizzas.Remove(pizza);
                    ctx.SaveChanges();
                }
                else if (action == 1)
                {
                    cart.Add(pizza);
                }
            }
            return RedirectToAction("List");
        }

        public ActionResult Cart()
        {
            return View(cart);
        }

        /// <summary>
        /// Metoda obsługująca akcje dla widoku koszyka.
        /// </summary>
        /// <param name="id">id konkretnej pizzy lub -1 dla potwierdzenia zamówienia</param>
        /// <returns></returns>
        [HttpPost]
        public ActionResult Cart(int id)
        {
            if (id == -1)
            {
                cart.Clear();
                return RedirectToAction("List");
            }
            cart.Remove(cart.Find(m => m.PizzaId == id));
            return RedirectToAction("Cart");
        }
    }
}