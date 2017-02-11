using DawidPerdekLab4.Repository.Query.Interfaces;
using DawidPerdekLab4.Model;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DawidPerdekLab4.Repository.Query
{
    public class ReadRepository<T> : IReadRepository<T> where T : Entity
    {
        protected readonly DawidPerdekContext _context;

        public ReadRepository(DawidPerdekContext context)
        {
            _context = context;
        }

        public IList<T> GetAll()
        {
            return _context.Set<T>().ToList();
        }

        public T GetById(int id)
        {
            return _context.Set<T>().Where(x => x.Id == id).FirstOrDefault();
        }
    }
}
