using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Windows.Forms;
using Example.Model;
using Example.Repository;
using Example.Repository.Query.Interfaces;
using Ninject;
using Ninject.Modules;

namespace Example
{
    public partial class Form1 : Form
    {
        private readonly IStuffQuery _query;
        private readonly IReadRepository<Student> _readRepository;
        private readonly IReadRepository<Announcement> _announcementReadRepository;
        private readonly IKernel _kernel;
        public Form1(
            IStuffQuery query,
            IReadRepository<Student> readRepository,
            IReadRepository<Announcement> announcementReadRepository,
            IKernel kernel)
        {

            _query = query;
            _readRepository = readRepository;
            _announcementReadRepository = announcementReadRepository;
            _kernel = kernel;

            InitializeComponent();
        }

        private void ShowNewForm()
        {
            // aby stworzyć nowy obiekt Form2 bez podawania argumentów interfejsów należy użyć interfejsu IKernel
            Form form2 = _kernel.Get<Form2>();
            form2.Show();
        }

        /// <summary>
        /// Metoda wyświetlająca studentów do datagridview
        /// </summary>
        /// <param name="dataGridView"></param>
        private void ShowInDataGridView(DataGridView dataGridView)
        {
            dataGridView.DataSource = null;

            // gdy chcemy wyświetlić część danych lub wyświetlić je pod innymi nazwami możemy użyć funkcji z Linq to Entities - Sekect
            // Gdy mamy doczynienia z 
            dataGridView.DataSource = _readRepository.GetAll().Select(x => new
            {
                Id = x.Id,
                Nazwisko = x.Surname,
                Imie = x.Name,
                Indeks = x.Index
            });
        }
    }
}
