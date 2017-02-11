namespace DawidPerdekZad4.Model
{
    /// <summary>
    /// Klasa modelująca pojedynczy statek.
    /// </summary>
    public class Ship : Entity
    {
        public int Length { get; set; }
        public int StartField { get; set; }
        public bool Orientation { get; set; }      // false - pionowo, true - poziomo
        public bool Sunk { get; set; }
    }
}
