namespace Example.Model
{
    using System.Data.Entity;
    /// <summary>
    /// Klasa jest DbContext jest mapperem pomi�dzy baz� relacyjn�, a obiektow�
    /// Czyli t�umaczy tabelki na obiekty i odwrotnie
    /// </summary>
    public class DatabaseContext : DbContext
    {
        // podajemy nazw� bazy danych podan� w app.config
        public DatabaseContext()
            : base("name=DatabaseContext")
        {
            //Database.SetInitializer(new DropCreateDatabaseAlways<DatabaseContext>());
            // poni�sza linijka usuwa ca�� baz� danych i tworzy j� od nowa, gdy Model zostanie zmieniony
            Database.SetInitializer(new DropCreateDatabaseIfModelChanges<DatabaseContext>());
        }

        // ka�dy DbSet oznacza tabel� na bazie danych
        public virtual DbSet<Student> Students { get; set; }
        public virtual DbSet<Stuff> Stuffs { get; set; }
        public virtual DbSet<Announcement> Announcements { get; set; }
        public virtual DbSet<StudentAnnouncement> StudentAnnouncements { get; set; }
    }
}