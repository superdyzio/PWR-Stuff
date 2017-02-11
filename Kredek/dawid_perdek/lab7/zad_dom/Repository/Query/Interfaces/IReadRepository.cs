using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DawidPerdekZad7.Repository.Query.Interfaces
{
    /// <summary>
    /// Interfejs modelujący możliwość czytania z bazy danych.
    /// </summary>
    /// <typeparam name="T">typ obsługiwanej encji</typeparam>
    public interface IReadRepository<T> where T : class
    {
        IList<T> GetAll();
        T GetById(int id);
    }
}
