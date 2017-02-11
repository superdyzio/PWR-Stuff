using System.Data.Entity;

namespace DawidPerdekZad4.Model
{
    public class BattleshipsContext : DbContext
    {
        // mapper - komunikuje się z bazą danych na SQLServer
        public BattleshipsContext() : base("name=BattleshipsContext")
        {
            // tworzenie bazy danych od nowa w momencie zmiany modelu
            Database.SetInitializer<BattleshipsContext>(new DropCreateDatabaseIfModelChanges<BattleshipsContext>());
        }

        // tabela użytkowników
        public virtual DbSet<User> Users { get; set; }
        // tabela statków
        public virtual DbSet<Ship> Ships { get; set; }
        // tabela plansz
        public virtual DbSet<Board> Boards { get; set; }
    }
}
