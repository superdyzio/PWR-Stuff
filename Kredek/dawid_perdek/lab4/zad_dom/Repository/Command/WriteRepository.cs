using DawidPerdekZad4.Model;
using DawidPerdekZad4.Repository.Command.Interfaces;

namespace DawidPerdekZad4.Repository.Command
{
    /// <summary>
    /// Implementacja interfejsu modelującego możliwość zapisu do bazy danych.
    /// </summary>
    /// <typeparam name="T">typ obsługiwanej encji</typeparam>
    public class WriteRepository<T> : IWriteRepository<T> where T : Entity
    {
        protected readonly BattleshipsContext _context;

        public WriteRepository(BattleshipsContext context)
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
