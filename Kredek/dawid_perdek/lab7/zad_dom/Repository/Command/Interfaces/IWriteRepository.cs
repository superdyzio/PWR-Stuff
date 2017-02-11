namespace DawidPerdekZad7.Repository.Command.Interfaces
{
    /// <summary>
    /// Interfejs modelujący możliwość zapisu do bazy danych.
    /// </summary>
    /// <typeparam name="T">typ obsługiwanej encji</typeparam>
    public interface IWriteRepository<in T> where T : class
    {
        void Delete(T entity);
        void Save(T entity);
        void Update(T entity);
    }
}
