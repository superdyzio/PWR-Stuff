namespace Example.Model
{
    /// <summary>
    /// Przykład powiązania Wiele do Wielu *:*
    /// Robi się bardzo podnie jak relację 1 do 1, tylko w klasach Student i Announcement nie robimy atrybutu
    /// [Key, ForeignKey("Student")]
    /// </summary>
    public class StudentAnnouncement : Entity
    {
        public int StudentId { get; set; }
        public int AnnouncementId { get; set; }
        public Announcement Announcement { get; set; }
        public Student Student { get; set; }
    }
}