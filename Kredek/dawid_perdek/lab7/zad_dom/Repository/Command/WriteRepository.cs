using DawidPerdekZad7.Repository.Command.Interfaces;
using DawidPerdekZad7.Models;

namespace DawidPerdekZad7.Repository.Command
{
    /// <summary>
    /// Implementacja interfejsu modelującego możliwość zapisu do bazy danych.
    /// </summary>
    /// <typeparam name="T">typ obsługiwanej encji</typeparam>
    public class WriteRepository<T> : IWriteRepository<T> where T : Entity
    {
        protected readonly FlightsContext _context;

        public WriteRepository(FlightsContext context)
        {
            _context = context;
        }

        public void Delete(T entity)
        {
            _context.Set<T>().Remove(entity);
            _context.SaveChanges();
        }

        public void Save(T entity)
        {
            _context.Set<T>().Add(entity);
            _context.SaveChanges();
        }

        public void Update(T entity)
        {
            _context.Entry(entity);
            _context.SaveChanges();
        }
    }
}