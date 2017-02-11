using System;
using System.Drawing;
using System.Windows.Forms;
using DawidPerdekZad4.Repository.Query.Interfaces;
using DawidPerdekZad4.Repository.Command.Interfaces;
using DawidPerdekZad4.Model;
using Ninject;

namespace DawidPerdekZad4.View
{
    /// <summary>
    /// Widok rozgrywki.
    /// </summary>
    public partial class FormGame : Form
    {
        private readonly IReadRepository<Board> _boardReadRepository;
        private readonly IReadRepository<Ship> _shipReadRepository;
        private readonly IReadRepository<User> _userReadRepository;
        private readonly IWriteRepository<Board> _boardWriteRepository;
        private readonly IWriteRepository<Ship> _shipWriteRepository;
        private readonly IWriteRepository<User> _userWriteRepository;
        private bool initializationProcess, gameFinished;   // zmienne do kontroli przebiegu gry
        private int initializationShipId;                   // Id obecnie umieszczanego statku w czasie inicjalizacji
        int[] playerBoard, cpuBoard;        // tablice reprezentujące plansze obu graczy

        [Inject]
        public FormGame(BattleshipsContext context, IReadRepository<Board> boardReadRepository, IReadRepository<Ship> shipReadRepository, IReadRepository<User> userReadRepository,
            IWriteRepository<Board> boardWriteRepository, IWriteRepository<Ship> shipWriteRepository, IWriteRepository<User> userWriteRepository)
        {
            _boardReadRepository = boardReadRepository;
            _shipReadRepository = shipReadRepository;
            _userReadRepository = userReadRepository;
            _boardWriteRepository = boardWriteRepository;
            _shipWriteRepository = shipWriteRepository;
            _userWriteRepository = userWriteRepository;
            InitializeComponent();
            initializationShipId = 0;
            gameFinished = false;
            groupBoxPlayerBoard.Text = _userReadRepository.GetById(1).Name;
            playerBoard = _boardReadRepository.GetById(1).Fields;
            cpuBoard = _boardReadRepository.GetById(2).Fields;
            checkBoxLongShipsOrientation.Hide();
            if (!_boardReadRepository.GetById(1).Initialized)
            {   // plansza wymaga inicjalizacji
                labelPlayerBoardInitializing.Show();
                groupBoxCPUBoard.Hide();
                initializationProcess = true;
                labelPlayerBoardInitializing.Text = "Ustaw statek długości 1";
                buttonSaveGame.Hide();
                labelCpuHitsCount.Hide();
                labelPlayerHitsCount.Hide();
            }
            else
            {   // plansza była już zainicjalizowana
                groupBoxCPUBoard.Show();
                labelPlayerBoardInitializing.Hide();
                initializationProcess = false;
                buttonSaveGame.Show();
                fillBoards();
                labelCpuHitsCount.Show();
                labelPlayerHitsCount.Show();
            }
        }

        /// <summary>
        /// Metoda wypełniająca kolorami odpowiednie pola na obu planszach.
        /// </summary>
        private void fillBoards()
        {
            for (int i = 0; i < 100; i++)
            {
                string buttonName = "buttonPlayer";
                switch (i % 10)
                {
                    case 0:
                        buttonName += "A";
                        break;
                    case 1:
                        buttonName += "B";
                        break;
                    case 2:
                        buttonName += "C";
                        break;
                    case 3:
                        buttonName += "D";
                        break;
                    case 4:
                        buttonName += "E";
                        break;
                    case 5:
                        buttonName += "F";
                        break;
                    case 6:
                        buttonName += "G";
                        break;
                    case 7:
                        buttonName += "H";
                        break;
                    case 8:
                        buttonName += "I";
                        break;
                    case 9:
                        buttonName += "J";
                        break;
                }
                buttonName += ((i / 10)+1).ToString();
                Button button = (Button) this.Controls.Find(buttonName, true)[0];
                if (playerBoard[i] == 1)
                    button.BackColor = Color.Red;
                else if (playerBoard[i] == 2)
                    button.BackColor = Color.Green;
                else if (playerBoard[i] == 9)
                    button.BackColor = Color.Yellow;
            }
            for (int i = 0; i < 100; i++)
            {
                string buttonName = "buttonCpu";
                switch (i % 10)
                {
                    case 0:
                        buttonName += "A";
                        break;
                    case 1:
                        buttonName += "B";
                        break;
                    case 2:
                        buttonName += "C";
                        break;
                    case 3:
                        buttonName += "D";
                        break;
                    case 4:
                        buttonName += "E";
                        break;
                    case 5:
                        buttonName += "F";
                        break;
                    case 6:
                        buttonName += "G";
                        break;
                    case 7:
                        buttonName += "H";
                        break;
                    case 8:
                        buttonName += "I";
                        break;
                    case 9:
                        buttonName += "J";
                        break;
                }
                buttonName += ((i / 10) + 1).ToString();
                Button button = (Button)this.Controls.Find(buttonName, true)[0];
                if (cpuBoard[i] == 1)
                    button.BackColor = Color.Red;
                else if (cpuBoard[i] == 2)
                    button.BackColor = Color.Green;
            }
        }

        /// <summary>
        /// Metoda umieszczająca jeden statek na planszy w czasie inicjalizacji.
        /// </summary>
        /// <param name="shipId">Id obecnie umieszczanego statku, pozwala ustalić długość statku</param>
        /// <param name="column">kolumna w której ma się znaleźć początek statku (zakres 0-9)</param>
        /// <param name="row">rząd w którym ma się znaleźć początek statku (zakres 0-9)</param>
        private void InitializeBoard(int shipId, int column, int row)
        {
            if (shipId == 1 || shipId == 2)
            {
                playerBoard[column + row * 10] = 9;
                if (shipId == 2)
                {
                    checkBoxLongShipsOrientation.Show();
                    labelPlayerBoardInitializing.Text = "Ustaw statek długości 2";
                }
                fillBoards();
            }
            else if (shipId == 3 || shipId == 4 || shipId == 5)
            {
                playerBoard[column + row * 10] = 9;
                if (checkBoxLongShipsOrientation.Checked)
                    playerBoard[column + row * 10 + 1] = 9;
                else
                    playerBoard[column + row * 10 + 10] = 9;
                fillBoards();
                if (shipId == 5)
                    labelPlayerBoardInitializing.Text = "Ustaw statek długości 3";
            }
            else if (shipId == 6 || shipId == 7)
            {
                playerBoard[column + row * 10] = 9;
                if (checkBoxLongShipsOrientation.Checked)
                {
                    playerBoard[column + row * 10 + 1] = 9;
                    playerBoard[column + row * 10 + 2] = 9;
                }
                else
                {
                    playerBoard[column + row * 10 + 10] = 9;
                    playerBoard[column + row * 10 + 20] = 9;
                }
                fillBoards();
                if (shipId == 7)
                    labelPlayerBoardInitializing.Text = "Ustaw statek długości 4";
            }
            else if (shipId == 8 || shipId == 9)
            {
                playerBoard[column + row * 10] = 9;
                if (checkBoxLongShipsOrientation.Checked)
                {
                    playerBoard[column + row * 10 + 1] = 9;
                    playerBoard[column + row * 10 + 2] = 9;
                    playerBoard[column + row * 10 + 3] = 9;
                }
                else
                {
                    playerBoard[column + row * 10 + 10] = 9;
                    playerBoard[column + row * 10 + 20] = 9;
                    playerBoard[column + row * 10 + 30] = 9;
                }
                fillBoards();
                if (shipId == 9)
                    labelPlayerBoardInitializing.Text = "Ustaw statek długości 5";
            }
            else if (shipId == 10)
            {
                playerBoard[column + row * 10] = 9;
                if (checkBoxLongShipsOrientation.Checked)
                {
                    playerBoard[column + row * 10 + 1] = 9;
                    playerBoard[column + row * 10 + 2] = 9;
                    playerBoard[column + row * 10 + 3] = 9;
                    playerBoard[column + row * 10 + 4] = 9;
                }
                else
                {
                    playerBoard[column + row * 10 + 10] = 9;
                    playerBoard[column + row * 10 + 20] = 9;
                    playerBoard[column + row * 10 + 30] = 9;
                    playerBoard[column + row * 10 + 40] = 9;
                }
                fillBoards();
                initializationProcess = false;
                groupBoxCPUBoard.Show();
                buttonSaveGame.Show();
                labelPlayerBoardInitializing.Hide();
                checkBoxLongShipsOrientation.Hide();
                labelCpuHitsCount.Show();
                labelPlayerHitsCount.Show();
                InitializeCpuBoard();
            }
        }

        /// <summary>
        /// Metoda rozmieszczająca statki na planszy komputera.
        /// </summary>
        private void InitializeCpuBoard()
        {
            cpuBoard[90] = 9;
            cpuBoard[99] = 9;
            cpuBoard[88] = 9; cpuBoard[98] = 9;
            cpuBoard[1] = 9; cpuBoard[2] = 9;
            cpuBoard[0] = 9; cpuBoard[10] = 9;
            cpuBoard[9] = 9; cpuBoard[19] = 9; cpuBoard[29] = 9;
            cpuBoard[43] = 9; cpuBoard[44] = 9; cpuBoard[45] = 9;
            cpuBoard[53] = 9; cpuBoard[54] = 9; cpuBoard[55] = 9; cpuBoard[56] = 9;
            cpuBoard[6] = 9; cpuBoard[16] = 9; cpuBoard[26] = 9; cpuBoard[36] = 9;
            cpuBoard[18] = 9; cpuBoard[28] = 9; cpuBoard[38] = 9; cpuBoard[48] = 9; cpuBoard[58] = 9;
            fillBoards();
        }

        /// <summary>
        /// Metoda obsługująca zdarzenie kliknięcia na przycisk do zapisu gry.
        /// </summary>
        /// <param name="sender">kontrolka wywołująca zdarzenie</param>
        /// <param name="e">argumenty zdarzenia</param>
        private void buttonSaveGame_Click(object sender, EventArgs e)
        {
            Board board = _boardReadRepository.GetById(1);
            board.Fields = playerBoard;
            board.Initialized = true;
            _boardWriteRepository.Update(board);
            board = _boardReadRepository.GetById(2);
            board.Fields = cpuBoard;
            board.Initialized = true;
            _boardWriteRepository.Update(board);
        }

        /// <summary>
        /// Metoda reagująca na kliknięcie dowolnego pola dowolnej planszy i obsługująca ruch użytkownika.
        /// </summary>
        /// <param name="sender">kontrolka wywołująca zdarzenie</param>
        /// <param name="e">argumenty zdarzenia</param>
        private void PlayerMove(object sender, EventArgs e)
        {
            if (gameFinished)
                return;     // jeśli gra już zakończona, nie obsługuj zdarzenia
            if (initializationProcess)
            {   // jeśli plansza nie zainicjalizowana -> inicjalizuj
                initializationShipId++;
                string field = ((Button)sender).Name.ToString().Substring(12);
                int row = int.Parse(field.Substring(1)) - 1;
                int column = -1;
                switch (field.Substring(0,1))
                {
                    case "A":
                        column = 0;
                        break;
                    case "B":
                        column = 1;
                        break;
                    case "C":
                        column = 2;
                        break;
                    case "D":
                        column = 3;
                        break;
                    case "E":
                        column = 4;
                        break;
                    case "F":
                        column = 5;
                        break;
                    case "G":
                        column = 6;
                        break;
                    case "H":
                        column = 7;
                        break;
                    case "I":
                        column = 8;
                        break;
                    case "J":
                        column = 9;
                        break;
                }
                InitializeBoard(initializationShipId,column,row);
            }
            else
            {   // plansza zainicjalizowana -> gracz oddaje strzał
                if (!((Button)sender).Name.ToString().Substring(0,9).Equals("buttonCpu"))
                {   // strzał we własną planszę -> poinformuj o błędzie i zignoruj
                    MessageBox.Show("Strzelaj w planszę przeciwnika!", "Sabotaż!");
                    return;
                }
                string field = ((Button)sender).Name.ToString().Substring(9);
                int row = int.Parse(field.Substring(1)) - 1;
                int column = -1;
                switch (field.Substring(0, 1))
                {
                    case "A":
                        column = 0;
                        break;
                    case "B":
                        column = 1;
                        break;
                    case "C":
                        column = 2;
                        break;
                    case "D":
                        column = 3;
                        break;
                    case "E":
                        column = 4;
                        break;
                    case "F":
                        column = 5;
                        break;
                    case "G":
                        column = 6;
                        break;
                    case "H":
                        column = 7;
                        break;
                    case "I":
                        column = 8;
                        break;
                    case "J":
                        column = 9;
                        break;
                }
                // strzał w planszę przeciwnika
                if (cpuBoard[column + row * 10] == 0)
                    cpuBoard[column + row * 10] = 1;        // pudło
                else if (cpuBoard[column + row * 10] == 9)
                    cpuBoard[column + row * 10] = 2;        // trafiony
                cpuMove();
            }
        }

        /// <summary>
        /// Metoda losująca kolejny strzał komputera. Nie pozwala na strzelanie w już ostrzelane pola.
        /// </summary>
        private void cpuMove()
        {
            Random rand = new Random();
            int shot = (int)(rand.NextDouble() * 100);
            while (playerBoard[shot] == 1 || playerBoard[shot] == 2)
                shot = (int)(rand.NextDouble() * 100);
            if (playerBoard[shot] == 0)
                playerBoard[shot] = 1;
            else if (playerBoard[shot] == 9)
                playerBoard[shot] = 2;
            fillBoards();
            checkWinners();
        }

        /// <summary>
        /// Metoda sprawdzająca czy któraś strona wygrała -> jest to rozpoznawane na podstawie liczbie trafień.
        /// 27 trafień oznacza zestrzelenie wszystkich statków rywala.
        /// </summary>
        private void checkWinners()
        {
            int playerHitCount = 0;
            int cpuHitCount = 0;
            for (int i = 0; i < 100; i++)
            {
                if (playerBoard[i] == 2)
                    cpuHitCount++;
                if (cpuBoard[i] == 2)
                    playerHitCount++;
                labelCpuHitsCount.Text = "Trafienia CPU: " + cpuHitCount.ToString() + " / 27";
                labelPlayerHitsCount.Text = "Trafienia gracza: " + playerHitCount.ToString() + " / 27";
                if (cpuHitCount == 27)
                {
                    MessageBox.Show("Komputer wygrał. :(", "Koniec gry.");
                    gameFinished = true;
                    return;
                }
                if (playerHitCount == 27)
                {
                    MessageBox.Show("Zwyciężył "+groupBoxPlayerBoard.Text+"! :)", "Koniec gry.");
                    gameFinished = true;
                    return;
                }
            }
        }
    }
}
