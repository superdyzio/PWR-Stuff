using System.Collections.Generic;

namespace DawidPerdekZad4.Model
{
    /// <summary>
    /// Klasa modelująca użytkownika gry - gracza lub komputer.
    /// </summary>
    public class User : Entity
    {
        public string Name { get; set; }
        public IList<Ship> Ships { get; set; }      // relacja jeden do wielu
        public virtual Board Board { get; set; }    // relacja jeden do jeden

        public User ()
        {
            Ships = new List<Ship>();
        }
    }
}
