namespace DawidPerdekZad4.Model
{
    /// <summary>
    /// Abstrakcyjna klasa reprezentująca Encję, dziedziczona przez pozostałe modele.
    /// </summary>
    public abstract class Entity
    {
        /// <summary>
        /// Jedyny powtarzający się w każdej encji parametr - numer Id.
        /// </summary>
        public virtual int Id { get; set; }
    }
}
