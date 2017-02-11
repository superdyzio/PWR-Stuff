using System.Collections.Generic;

namespace DawidPerdekZad4.Repository.Query.Interfaces
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