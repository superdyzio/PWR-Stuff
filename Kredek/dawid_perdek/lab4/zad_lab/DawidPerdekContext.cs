namespace DawidPerdekLab4
{
    using System;
    using System.Data.Entity;
    using System.Linq;
    using DawidPerdekLab4.Model;

    public class DawidPerdekContext : DbContext
    {
        // mapper - komunikuje siê z baz¹ danych na SQLServer
        public DawidPerdekContext()
            : base("name=DawidPerdekContext")
        {
            // tworzenie bazy danych od nowa w momencie zmiany modelu
            Database.SetInitializer<DawidPerdekContext>(new DropCreateDatabaseIfModelChanges<DawidPerdekContext>());
        }

        public virtual DbSet<Grade> Grades { get; set; }
        public virtual DbSet<Student> Students { get; set; }
        public virtual DbSet<Address> Addresses { get; set; }
    }
}