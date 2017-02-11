using System;
using System.Collections.Generic;
using System.Windows.Forms;
using DawidPerdekZad4.Repository.Command.Interfaces;
using DawidPerdekZad4.Model;
using Ninject;

namespace DawidPerdekZad4.View
{
    /// <summary>
    /// Widok tworzenia nowej rozgrywki.
    /// </summary>
    public partial class FormStartNewGame : Form
    {
        private readonly BattleshipsContext _context;
        private readonly IKernel _kernel;
        private readonly IWriteRepository<User> _userWriteRepository;

        [Inject]
        public FormStartNewGame(BattleshipsContext context, IKernel kernel, IWriteRepository<User> userWriteRepository)
        {
            _context = context;
            _kernel = kernel;
            _userWriteRepository = userWriteRepository;
            InitializeComponent();
        }

        /// <summary>
        /// Reakcja na kliknięcie przycisku rozpoczynającego rozgrywkę.
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void buttonStartPlaying_Click(object sender, EventArgs e)
        {
            // kontrola wprowadzenia swojej nazwy / imienia
            if (textBoxPlayerName.Text.Length == 0)
            {
                MessageBox.Show("Wprowadź imię.", "Błąd!");
                return;
            }

            // usunięcie starej bazy, inicjalizacja nowej
            _context.Database.Delete();
            _context.Database.Initialize(true);

            // tworzenie gracza
            User gracz = new User()
            {
                Id = 1,
                Name = textBoxPlayerName.Text.ToString(),
                Board = new Board()
                {
                    Id = 1,
                    Initialized = false
                },
                Ships = new List<Ship>()
                {
                    new Ship()
                    {
                        Id = 1,
                        Length = 1,
                        StartField = 0,
                        Orientation = false,
                        Sunk = false
                    },
                    new Ship()
                    {
                        Id = 2,
                        Length = 1,
                        StartField = 0,
                        Orientation = false,
                        Sunk = false
                    },
                    new Ship()
                    {
                        Id = 3,
                        Length = 2,
                        StartField = 0,
                        Orientation = false,
                        Sunk = false
                    },
                    new Ship()
                    {
                        Id = 4,
                        Length = 2,
                        StartField = 0,
                        Orientation = false,
                        Sunk = false
                    },
                    new Ship()
                    {
                        Id = 5,
                        Length = 2,
                        StartField = 0,
                        Orientation = false,
                        Sunk = false
                    },
                    new Ship()
                    {
                        Id = 6,
                        Length = 3,
                        StartField = 0,
                        Orientation = false,
                        Sunk = false
                    },
                    new Ship()
                    {
                        Id = 7,
                        Length = 3,
                        StartField = 0,
                        Orientation = false,
                        Sunk = false
                    },
                    new Ship()
                    {
                        Id = 8,
                        Length = 4,
                        StartField = 0,
                        Orientation = false,
                        Sunk = false
                    },
                    new Ship()
                    {
                        Id = 9,
                        Length = 4,
                        StartField = 0,
                        Orientation = false,
                        Sunk = false
                    },
                    new Ship()
                    {
                        Id = 10,
                        Length = 5,
                        StartField = 0,
                        Orientation = false,
                        Sunk = false
                    }
                }
            };

            _userWriteRepository.Save(gracz);   // zapis gracza do bazy

            // tworzenie CPU
            User CPU = new User()
            {
                Id = 2,
                Name = "CPU",
                Board = new Board()
                {
                    Id = 2,
                    Initialized = false
                },
                Ships = new List<Ship>()
                {
                    new Ship()
                    {
                        Id = 11,
                        Length = 1,
                        StartField = 0,
                        Orientation = false,
                        Sunk = false
                    },
                    new Ship()
                    {
                        Id = 12,
                        Length = 1,
                        StartField = 0,
                        Orientation = false,
                        Sunk = false
                    },
                    new Ship()
                    {
                        Id = 13,
                        Length = 2,
                        StartField = 0,
                        Orientation = false,
                        Sunk = false
                    },
                    new Ship()
                    {
                        Id = 14,
                        Length = 2,
                        StartField = 0,
                        Orientation = false,
                        Sunk = false
                    },
                    new Ship()
                    {
                        Id = 15,
                        Length = 2,
                        StartField = 0,
                        Orientation = false,
                        Sunk = false
                    },
                    new Ship()
                    {
                        Id = 16,
                        Length = 3,
                        StartField = 0,
                        Orientation = false,
                        Sunk = false
                    },
                    new Ship()
                    {
                        Id = 17,
                        Length = 3,
                        StartField = 0,
                        Orientation = false,
                        Sunk = false
                    },
                    new Ship()
                    {
                        Id = 18,
                        Length = 4,
                        StartField = 0,
                        Orientation = false,
                        Sunk = false
                    },
                    new Ship()
                    {
                        Id = 19,
                        Length = 4,
                        StartField = 0,
                        Orientation = false,
                        Sunk = false
                    },
                    new Ship()
                    {
                        Id = 20,
                        Length = 5,
                        StartField = 0,
                        Orientation = false,
                        Sunk = false
                    }
                }
            };

            _userWriteRepository.Save(CPU); // zapis CPU

            this.Close(); 

            Form form = _kernel.Get<FormGame>();
            form.Show();
        }
    }
}
