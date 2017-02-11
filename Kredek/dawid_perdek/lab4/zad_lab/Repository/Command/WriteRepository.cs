using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using DawidPerdekLab4.Repository.Command.Interfaces;
using DawidPerdekLab4.Model;

namespace DawidPerdekLab4.Repository.Command
{
    public class WriteRepository<T> : IWriteRepository<T> where T : Entity
    {
        private readonly DawidPerdekContext _context;

        public WriteRepository(DawidPerdekContext context)
        {
            _context = context;
        }

        public void Create(T entity)
        {
            _context.Set<T>().Add(entity);
            _context.SaveChanges();
        }

        public void Delete(T entity)
        {
            _context.Set<T>().Remove(entity);
        }

        public void Edit(T entity)
        {
            _context.Entry<T>(entity);
        }
    }
}
