using System.Collections.Generic;

namespace Example.Model
{
    // klasa POCO jest klasą, która reprezentuje konkretną tabelę na bazie danych

    /// <summary>
    /// Przykład powiązania 1 do wielu 1:*
    /// Jeden Student posiada listę Stuffu
    /// W Stuff należy dodać StudentId, gdy o tym zapomnimy na bazie zostanie utworzone pole Students_Id
    /// Jednak w zapytaniach nie będziemy mogli się do niego odnieść
    /// </summary>
    public class Student : Entity
    {
        public Student()
        {
            ListOfStuff = new List<Stuff>();
        }

        public string Name { get; set; }
        public string Surname { get; set; }
        public int Age { get; set; }
        public int Index { get; set; }
        public IList<Stuff> ListOfStuff { get; set; }

        // Gdy dodamy przed IList<> słówko virtual otrzymamy leniwe wczytywanie tzw. lazy loading
        // Lista ta zostanie załadowana gdy będzie nam potrzebna
        // public virtual IList<Stuff> ListOfStuff { get; set; } // Lazy Loading


        // przykład powiązania 1 do 1 1:1
        // należy pamiętać o powiązaniu ze sobą kluczy w klasie Address
        public Address Address { get; set; }
    }
}