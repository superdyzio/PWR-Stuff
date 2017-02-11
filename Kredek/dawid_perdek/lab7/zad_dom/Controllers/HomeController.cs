using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using DawidPerdekZad7.Models;
using DawidPerdekZad7.Repository.Command;
using DawidPerdekZad7.Repository.Command.Interfaces;
using DawidPerdekZad7.Repository.Query.Interfaces;
using DawidPerdekZad7.Repository.Query;

namespace DawidPerdekZad7.Controllers
{
    public class HomeController : Controller
    {
        private readonly FlightsContext _context;
        private readonly IWriteRepository<Flight> _flightWriteRepository;
        private readonly IReadRepository<Flight> _flightReadRepository;

        public HomeController()
        {
            _context = new FlightsContext();
            _flightWriteRepository = new WriteRepository<Flight>(_context);
            _flightReadRepository = new ReadRepository<Flight>(_context);

            //_flightWriteRepository.Save(new Flight()
            //{
            //    Id = 1,
            //    CityFrom = "Wrocław",
            //    CityTo = "Oława",
            //    DepartureTime = 1300,
            //    ArrivalTime = 1400,
            //    FreeSeats = 100,
            //    Price = 39.99
            //});
        }

        public ActionResult Index()
        {
            return View();
        }

        public JsonResult GetFlights()
        {
            IList<Flight> flights = _flightReadRepository.GetAll();
            return Json(flights, JsonRequestBehavior.AllowGet);
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
    }
}