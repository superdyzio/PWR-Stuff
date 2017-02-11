using System.Collections.Generic;
using System.Linq;
using DawidPerdekZad7.Repository.Query.Interfaces;
using DawidPerdekZad7.Models;

namespace DawidPerdekZad7.Repository.Query
{
    /// <summary>
    /// Implementacja interfejsu modelującego możliwość czytania z bazy danych.
    /// </summary>
    /// <typeparam name="T">typ obsługiwanej encji</typeparam>
    public class ReadRepository<T> : IReadRepository<T> where T : Entity
    {
        protected readonly FlightsContext Context;

        public ReadRepository(FlightsContext context)
        {
            Context = context;
        }

        public IList<T> GetAll()
        {
            return Context.Set<T>().ToList();
        }

        public T GetById(int id)
        {
            return Context.Set<T>().FirstOrDefault(x => x.Id == id);
        }
    }
}