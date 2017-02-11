using System;
using System.Linq;

namespace DawidPerdekZad4.Model
{
    /// <summary>
    /// Klasa modelująca planszę dla jednego gracza (wymiary 10x10 pól).
    /// </summary>
    public class Board : Entity
    {
        /// <summary>
        /// Tablica przechowująca stany poszczególnych pól planszy, gdzie:
        ///     0 - pole puste, nie oddano w nie strzału
        ///     1 - oddano strzał w pole, nie było tam statku, "pudło"
        ///     2 - oddano strzał w pole, był tam statek, "trafiony"
        ///     9 - na polu znajduje się statek, ale nie oddano jeszcze w nie strzału
        /// </summary>
        public int[] Fields
        {
            get
            {
                return Array.ConvertAll(Data.Split(';'), int.Parse);
            }
            set
            {
                Data = String.Join(";", value.Select(p => p.ToString()).ToArray());
            }
        }
        public string Data { get; set; }
        public bool Initialized { get; set; }

        public Board()
        {
            Fields = new int[100];
            for (int i = 0; i < 100; i++)
                    Fields[i] = 0;
        }
    }
}
