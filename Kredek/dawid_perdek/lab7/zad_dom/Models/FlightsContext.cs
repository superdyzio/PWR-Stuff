using System.Data.Entity;

namespace DawidPerdekZad7.Models
{
    public class FlightsContext : DbContext
    {
        // mapper - komunikuje się z bazą danych na SQLServer
        public FlightsContext() : base("name=FlightsContext")
        {
            // tworzenie bazy danych od nowa w momencie zmiany modelu
            Database.SetInitializer<FlightsContext>(new DropCreateDatabaseIfModelChanges<FlightsContext>());
        }

        // tabela lotów
        public virtual DbSet<Flight> Flights { get; set; }
    }
}