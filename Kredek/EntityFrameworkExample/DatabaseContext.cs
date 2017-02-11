namespace Example.Model
{
    using System.Data.Entity;
    /// <summary>
    /// Klasa jest DbContext jest mapperem pomiêdzy baz¹ relacyjn¹, a obiektow¹
    /// Czyli t³umaczy tabelki na obiekty i odwrotnie
    /// </summary>
    public class DatabaseContext : DbContext
    {
        // podajemy nazwê bazy danych podan¹ w app.config
        public DatabaseContext()
            : base("name=DatabaseContext")
        {
            //Database.SetInitializer(new DropCreateDatabaseAlways<DatabaseContext>());
            // poni¿sza linijka usuwa ca³¹ bazê danych i tworzy j¹ od nowa, gdy Model zostanie zmieniony
            Database.SetInitializer(new DropCreateDatabaseIfModelChanges<DatabaseContext>());
        }

        // ka¿dy DbSet oznacza tabelê na bazie danych
        public virtual DbSet<Student> Students { get; set; }
        public virtual DbSet<Stuff> Stuffs { get; set; }
        public virtual DbSet<Announcement> Announcements { get; set; }
        public virtual DbSet<StudentAnnouncement> StudentAnnouncements { get; set; }
    }
}