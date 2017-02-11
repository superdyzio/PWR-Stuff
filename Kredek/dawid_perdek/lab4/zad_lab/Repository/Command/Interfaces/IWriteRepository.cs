using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using DawidPerdekLab4.Model;

namespace DawidPerdekLab4.Repository.Command.Interfaces
{
    public interface IWriteRepository<T> where T : Entity
    {
        void Create(T entity);
        void Delete(T entity);
        void Edit(T entity);
    }
}
