using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using DawidPerdekLab4.Model;
using DawidPerdekLab4.Repository.Query.Interfaces;

namespace DawidPerdekLab4.Repository.Query
{
    public class UserQuery : ReadRepository<Student>, IUserQuery
    {
        public UserQuery(DawidPerdekContext context) : base(context) {}

        public IList<Student> UserWithAddressByName(string name)
        {
            return _context.Set<Student>().Where(q => q.Name == name).ToList();
        }
    }
}
