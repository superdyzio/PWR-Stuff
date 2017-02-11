using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using DawidPerdekLab4.Model;

namespace DawidPerdekLab4.Repository.Query.Interfaces
{
    public interface IReadRepository<T> where T : Entity
    {
        IList<T> GetAll();
        T GetById(int id);
    }
}
