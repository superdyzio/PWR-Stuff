using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace Example.Model
{
    public class Address
    {
        [Key, ForeignKey("Student")]
        public int Id { get; set; }

        public string State { get; set; }
        // itd....
    }
}
