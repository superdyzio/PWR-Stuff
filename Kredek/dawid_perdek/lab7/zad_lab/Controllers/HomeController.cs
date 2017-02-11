using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using DawidPerdekLab7.Models;

namespace DawidPerdekLab7.Controllers
{
    public class HomeController : Controller
    {
        public ActionResult Index()
        {
            return View();
        }

        public ActionResult About()
        {
            ViewBag.Message = "Your application description page.";

            return View();
        }

        public ActionResult Contact()
        {
            ViewBag.Message = "Your contact page.";

            return View();
        }

        public JsonResult GetListOfPizzas()
        {
            String baseIngredients = "ser, sos, oregano";
            List<Pizza> list = new List<Pizza>();
            Pizza newPizza = new Pizza() { Name = "Margarita", Price = 9.30f, Ingredients = baseIngredients };
            list.Add(newPizza);
            newPizza = new Pizza() { Name = "Funghi", Price = 9.90f, Ingredients = baseIngredients + ", pieczarki" };
            list.Add(newPizza);
            newPizza = new Pizza() { Name = "Mafioso", Price = 12.60f, Ingredients = baseIngredients + ", jalapeno" };
            list.Add(newPizza);
            newPizza = new Pizza() { Name = "Capriciosa", Price = 17.30f, Ingredients = baseIngredients + ", szynka, papryka" };
            list.Add(newPizza);
            newPizza = new Pizza() { Name = "Farmerska", Price = 21.30f, Ingredients = baseIngredients + ", kukurydza, słonecznik" };
            list.Add(newPizza);
            return Json(list, JsonRequestBehavior.AllowGet);
        }
    }
}