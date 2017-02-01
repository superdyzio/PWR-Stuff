#include "Gra.h"
;
void Gra::getPlansza() {
    for (int i = 0; i < rozmiar; i++) {
        for (int j = 0; j < rozmiar; j++) {
            cout << " " << plansza[i][j] << " ";
            if (j != rozmiar-1)
                cout << "|";
        }
        cout << "               ";
// fragment kodu odpowiadajacy za wypisywanie po boku planszy z numerami wolnych pol
        for (int k = 0; k < rozmiar; k++) {
            if (plansza[i][k] == ' ')
                cout << " " << setw(2) << i*rozmiar+k+1 << " ";
            else
                cout << "    ";
            if (k != rozmiar-1)
                cout << "|";
        }
        if (i != rozmiar-1) {
            cout << endl << "---";
            for (int j = 0; j < rozmiar-1; j++)
                cout << "+---";
            cout << "               " << "----";
            for (int j = 0; j < rozmiar-1; j++)
                cout << "+----";
            cout << endl;
        }
    }
}

int Gra::ksiega_otwarc() {
    int pozycja;
    srand(time(NULL));
    do {
        pozycja = rand() % rozmiar*rozmiar;
    } while (plansza[pozycja/rozmiar][pozycja%rozmiar] != ' ');
    Sleep(1000);
    return pozycja;
}

int Gra::miejsca_wolne() {
    int wynik = 0;
    for (int i = 0; i < rozmiar; i++)
        for (int j = 0; j < rozmiar; j++)
            if (plansza[i][j] == ' ')
                wynik++;
    return wynik;
}

bool Gra::remis(bool cisza) {
    int mw = miejsca_wolne();
    if (mw == 0) {
        if (!cisza) {
            getPlansza();
            cout << endl << "REMIS" << endl;
        }
        return true;
    }
    return false;
}

/*	Metoda po zidentyfikowaniu rozmiaru planszy i wymaganej ilosci znakow w rzedzie zaczyna sprawdzanie od wierszow i kolumn. Jesli tam nie pojawila sie
    okreslona ilosc znakow w rzedzie szuka na przekatnych, a nastepnie kolejno przeszukuje wszystkie coraz krotsze "cieciwy". */
bool Gra::wygrana(char znak, bool cisza) {
    bool wynik = false;
    if (rozmiar == 3) {
        if (rzad == 3) {
            for (int i = 0; i < rozmiar && !wynik; i++)
                if ((plansza[i][0] == znak && plansza[i][1] == znak && plansza[i][2] == znak) || (plansza[0][i] == znak && plansza[1][i] == znak && plansza[2][i] == znak))
                    wynik = true;   // sprawdzenie wierszy i kolumn
            if (plansza[1][1] == znak && ((plansza[0][0] == znak && plansza[2][2] == znak) || (plansza[0][2] == znak && plansza[2][0] == znak)))
                wynik = true;		// sprawdzenie przekatnych
        }
    }
    if (rozmiar == 4) {
        if (rzad == 3) {
            for (int i = 0; i < rozmiar && !wynik; i++) {
                if (plansza[i][1] == znak && plansza[i][2] == znak && (plansza[i][0] == znak || plansza[i][3] == znak))
                    wynik = true;	// sprawdzenie wierszy
                if (plansza[1][i] == znak && plansza[2][i] == znak && (plansza[0][i] == znak || plansza[3][i] == znak))
                    wynik = true;	// sprawdzenie kolumn
            }
            if (plansza[1][1] == znak && plansza[2][2] == znak && (plansza[0][0] == znak || plansza[3][3] == znak))
                wynik = true;		// sprawdzenie przekatnej rosnacej
            if (plansza[1][2] == znak && plansza[2][1] == znak && (plansza[0][3] == znak || plansza[3][0] == znak))
                wynik = true;		// sprawdzenie przekatnej malejacej
            if ((plansza[1][0] == znak && plansza[2][1] == znak && plansza[3][2] == znak) || (plansza[0][1] == znak && plansza[1][2] == znak && plansza[2][3] == znak))
                wynik = true;		// sprawdzenie cieciw dlugosci 3 rosnacych
            if ((plansza[0][2] == znak && plansza[1][1] == znak && plansza[2][0] == znak) || (plansza[1][3] == znak && plansza[2][2] == znak && plansza[3][1] == znak))
                wynik = true;		// sprawdzenie cieciw dlugosci 3 malejacych
        }
        if (rzad == 4) {
            for (int i = 0; i < rozmiar && !wynik; i++)
                if ((plansza[i][0] == znak && plansza[i][1] == znak && plansza[i][2] == znak && plansza[i][3] == znak) || (plansza[0][i] == znak && plansza[1][i] == znak && plansza[2][i] == znak && plansza[3][i] == znak))
                    wynik = true;	// sprawdzenie wierszy i kolumn
            if ((plansza[0][0] == znak && plansza[1][1] == znak && plansza[2][2] == znak && plansza[3][3] == znak) || (plansza[0][3] == znak && plansza[1][2] == znak && plansza[2][1] == znak && plansza[3][0] == znak))
                wynik = true;		// sprawdzenie przekatnych
        }
    }
    if (rozmiar == 5) {
        if (rzad == 3) {
            for (int i = 0; i < rozmiar && !wynik; i++) {
                if (plansza[i][2] == znak && ((plansza[i][1] == znak && plansza[i][3] == znak) || (plansza[i][1] == znak && plansza[i][0] == znak) || (plansza[i][3] == znak && plansza[i][4] == znak)))
                    wynik = true;	// sprawdzenie kolumn
                if (plansza[2][i] == znak && ((plansza[1][i] == znak && plansza[3][i] == znak) || (plansza[1][i] == znak && plansza[0][i] == znak) || (plansza[3][i] == znak && plansza[4][i] == znak)))
                    wynik = true;	// sprawdzenie wierszy
            }
            if (plansza[2][2] == znak && ((plansza[0][0] == znak && plansza[1][1] == znak) || (plansza[1][1] == znak && plansza[3][3] == znak) || (plansza[3][3] == znak && plansza[4][4] == znak) || (plansza[0][4] == znak && plansza[1][3] == znak) || (plansza[1][3] == znak && plansza[3][1] == znak) || (plansza[3][1] == znak && plansza[4][0] == znak)))
                wynik = true;		// sprawdzenie cieciw dlugosci 3
            if ((plansza[1][2] == znak && plansza[2][1] == znak && (plansza[0][3] == znak || plansza[3][0] == znak)) || (plansza[2][3] == znak && plansza[3][2] == znak && (plansza[1][4] == znak || plansza[4][1] == znak)) || (plansza[1][2] == znak && plansza[2][3] == znak && (plansza[0][1] == znak || plansza[3][4] == znak)) || (plansza[2][1] == znak && plansza[3][2] == znak && (plansza[1][0] == znak || plansza[4][3] == znak)))
                wynik = true;		// sprawdzenie cieciw dlugosci 4
            if ((plansza[0][2] == znak &&  ((plansza[1][3] == znak && plansza[2][4] == znak) || (plansza[1][1] == znak && plansza[2][0] == znak))) || (plansza[4][2] == znak && ((plansza[3][1] == znak && plansza[2][0] == znak) || (plansza[3][3] == znak && plansza[2][4] == znak))))
                wynik = true;		// sprawdzenie przekatnych
        }
        if (rzad == 4) {
            for (int i = 0; i < rozmiar && !wynik; i++) {
                if (plansza[1][i] == znak && plansza[2][i] == znak && plansza[3][i] == znak && (plansza[0][i] == znak || plansza[4][i] == znak))
                    wynik = true;	// sprawdzenie wierszy
                if (plansza[i][1] == znak && plansza[i][2] == znak && plansza[i][3] == znak && (plansza[i][0] == znak || plansza[i][4] == znak))
                    wynik = true;	// sprawdzenie kolumn
            }
            if (plansza[1][1] == znak && plansza[2][2] == znak && plansza[3][3] == znak && (plansza[0][0] == znak || plansza[4][4] == znak))
                wynik = true;	// sprawdzenie przekatnej rosnacej
            if (plansza[1][3] == znak && plansza[2][2] == znak && plansza[3][1] == znak && (plansza[0][4] == znak || plansza[4][0] == znak))
                wynik = true;	// sprawdzenie przekatnej malejacej
            if ((plansza[1][0] == znak && plansza[2][1] == znak && plansza[3][2] == znak && plansza[4][3] == znak) || (plansza[0][1] == znak && plansza[1][2] == znak && plansza[2][3] == znak && plansza[3][4] == znak))
                wynik = true;	// sprawdzenie cieciw dlugosci 4 rosnacych
            if ((plansza[0][3] == znak && plansza[1][2] == znak && plansza[2][1] == znak && plansza[3][0] == znak) || (plansza[1][4] == znak && plansza[2][3] == znak && plansza[3][2] == znak && plansza[4][1] == znak))
                wynik = true;	// sprawdzenie cieciw dlugosci 4 malejacych
        }
        if (rzad == 5) {
            for (int i = 0; i < rozmiar && !wynik; i++)
                if ((plansza[0][i] == znak && plansza[1][i] == znak && plansza[2][i] == znak && plansza[3][i] == znak && plansza[4][i] == znak) || (plansza[i][0] == znak && plansza[i][1] == znak && plansza[i][2] == znak && plansza[i][3] == znak && plansza[i][4] == znak))
                    wynik = true;	// sprawdzenie wierszy i kolumn
            if ((plansza[0][0] == znak && plansza[1][1] == znak && plansza[2][2] == znak && plansza[3][3] == znak && plansza[4][4] == znak) || (plansza[0][4] == znak && plansza[1][3] == znak && plansza[2][2] == znak && plansza[3][1] == znak && plansza[4][0] == znak))
                wynik = true;		// sprawdzenie przekatnych
        }
    }
    if (rozmiar == 6) {
        if (rzad == 3) {
            for (int i = 0; i < rozmiar && !wynik; i++)
                for (int j = 0; j < rozmiar-2 && !wynik; j++) {
                    if ((plansza[i][j] == znak && plansza[i][j+1] == znak && plansza[i][j+2] == znak) || (plansza[j][i] == znak && plansza[j+1][i] == znak && plansza[j+2][i] == znak))
                        wynik = true;	// sprawdzenie wierszy i kolumn
                    if ((plansza[j][j] == znak && plansza[j+1][j+1] == znak && plansza[j+2][j+2] == znak) || (plansza[j][rozmiar-1-j] == znak && plansza[j+1][rozmiar-2-j] == znak && plansza[j+2][rozmiar-3-j]))
                        wynik = true;	// sprawdzenie przekatnych
                }
            if ((plansza[2][3] == znak && ((plansza[0][1] == znak && plansza[1][2] == znak) || (plansza[1][2] == znak && plansza[3][4] == znak) || (plansza[3][4] == znak && plansza[4][5] == znak))) || (plansza[3][3] == znak && ((plansza[1][5] == znak && plansza[2][4] == znak) || (plansza[2][4] == znak && plansza[4][2] == znak) || (plansza[4][2] == znak && plansza[5][1] == znak))) || (plansza[3][2] == znak && ((plansza[1][0] == znak && plansza[2][1] == znak) || (plansza[2][1] == znak && plansza[4][1] == znak) || (plansza[4][1] == znak && plansza[5][0] == znak))) || (plansza[2][2] == znak && ((plansza[4][0] == znak && plansza[3][1] == znak) || (plansza[3][1] == znak && plansza[1][3] == znak) || (plansza[1][3] == znak && plansza[0][4] == znak))))
                wynik = true;			// sprawdzenie cieciw dlugosci 5
            if ((plansza[1][3] == znak && plansza[2][4] == znak && (plansza[3][5] == znak || plansza[0][2] == znak)) || (plansza[3][4] == znak && plansza[4][3] == znak && (plansza[2][5] == znak || plansza[5][2] == znak)) || (plansza[4][2] == znak && plansza[3][1] == znak && (plansza[2][0] == znak || plansza[5][3] == znak)) || (plansza[2][1] == znak && plansza[1][2] == znak && (plansza[3][0] == znak || plansza[0][3] == znak)))
                wynik = true;			// sprawdzenie cieciw dlugosci 4
            if ((plansza[0][3] == znak && plansza[1][4] == znak && plansza[2][5] == znak) || (plansza[3][5] == znak && plansza[4][4] == znak && plansza[5][3] == znak) || (plansza[5][2] == znak && plansza[4][1] == znak && plansza[3][0] == znak) || (plansza[2][0] == znak && plansza[1][1] == znak && plansza[0][2] == znak))
                wynik = true;			// sprawdzenie cieciw dlugosci 3
        }
        if (rzad == 4) {
            for (int i = 0; i < rozmiar && !wynik; i++) {
                if (plansza[2][i] == znak && plansza[3][i] == znak && ((plansza[0][i] == znak && plansza[1][i] == znak) || (plansza[1][i] == znak && plansza[4][i] == znak) || (plansza[4][i] == znak && plansza[5][i] == znak)))
                    wynik = true;		// sprawdzenie wierszy
                if (plansza[i][2] == znak && plansza[i][3] == znak && ((plansza[i][0] == znak && plansza[i][1] == znak) || (plansza[i][1] == znak && plansza[i][4] == znak) || (plansza[i][4] == znak && plansza[i][5] == znak)))
                    wynik = true;		// sprawdzenie kolumn
            }
            if (plansza[2][2] == znak && plansza[3][3] == znak && ((plansza[0][0] == znak && plansza[1][1] == znak) || (plansza[1][1] == znak && plansza[4][4] == znak) || (plansza[4][4] == znak && plansza[5][5] == znak)))
                wynik = true;			// sprawdzenie przekatnej rosnacej
            if (plansza[2][3] == znak && plansza[3][2] == znak && ((plansza[0][5] == znak && plansza[1][4] == znak) || (plansza[1][4] == znak && plansza[4][1] == znak) || (plansza[4][1] == znak && plansza[5][0] == znak)))
                wynik = true;			// sprawdzenie przekatnej malejacej
            if ((plansza[2][1] == znak && plansza[3][2] == znak && plansza[4][3] == znak && (plansza[5][4] == znak || plansza[1][0] == znak)) || (plansza[1][2] == znak && plansza[2][3] == znak && plansza[3][4] == znak && (plansza[4][5] == znak || plansza[0][1] == znak)) || (plansza[1][3] == znak && plansza[2][2] == znak && plansza[3][1] == znak && (plansza[4][0] == znak || plansza[0][4] == znak)) || (plansza[4][2] == znak && plansza[3][3] == znak && plansza[2][4] == znak && (plansza[1][5] == znak || plansza[5][1] == znak)))
                wynik = true;			// sprawdzenie cieciw dlugosci 5
            if ((plansza[0][2] == znak && plansza[1][3] == znak && plansza[2][4] == znak && plansza[3][5] == znak) || (plansza[0][3] == znak && plansza[1][2] == znak && plansza[2][1] == znak && plansza[3][0] == znak) || (plansza[5][2] == znak && plansza[4][3] == znak && plansza[3][4] == znak && plansza[2][5] == znak) || (plansza[5][3] == znak && plansza[4][2] == znak && plansza[3][1] == znak && plansza[4][0] == znak))
                wynik = true;			// sprawdzenie cieciw dlugosci 4
        }
        if (rzad == 5) {
            for (int i = 0; i < rozmiar && !wynik; i++)
                if ((plansza[i][1] == znak && plansza[i][2] == znak && plansza[i][3] == znak && plansza[i][4] == znak && (plansza[i][5] == znak || plansza[i][0] == znak)) || (plansza[1][i] == znak && plansza[2][i] == znak && plansza[3][i] == znak && plansza[4][i] == znak && (plansza[5][i] == znak || plansza[0][i] == znak)))
                    wynik = true;		// sprawdzenie kolumn i wierszy
            if ((plansza[2][2] == znak && plansza[3][3] == znak && plansza[3][3] == znak && plansza[4][4] == znak && (plansza[5][5] == znak || plansza[0][0] == znak)) || (plansza[1][4] == znak && plansza[2][3] == znak && plansza[3][2] == znak && plansza[4][1] == znak && (plansza[0][5] == znak || plansza[5][0] == znak)))
                wynik = true;			// sprawdzenie przekatnych
            if ((plansza[0][1] == znak && plansza[1][2] == znak && plansza[2][3] == znak && plansza[3][4] == znak && plansza[4][5] == znak) || (plansza[1][0] == znak && plansza[2][1] == znak && plansza[3][2] == znak && plansza[4][3] == znak && plansza[5][4] == znak) || (plansza[0][4] == znak && plansza[1][3] == znak && plansza[2][2] == znak && plansza[3][1] == znak && plansza[4][0] == znak) || (plansza[1][5] == znak && plansza[2][4] == znak && plansza[3][3] == znak && plansza[4][2] == znak && plansza[5][1] == znak))
                wynik = true;			// sprawdzenie cieciw dlugosci 5
        }
        if (rzad == 6) {
            for (int i = 0; i < rozmiar && !wynik; i++)
                if ((plansza[0][i] == znak && plansza[1][i] == znak && plansza[2][i] == znak && plansza[3][i] == znak && plansza[4][i] == znak && plansza[5][i] == znak) || (plansza[i][0] == znak && plansza[i][1] == znak && plansza[i][2] == znak && plansza[i][3] == znak && plansza[i][4] == znak && plansza[i][5] == znak))
                    wynik = true;		// sprawdzenie wierszy i kolumn
            if ((plansza[0][0] == znak && plansza[1][1] == znak && plansza[2][2] == znak && plansza[3][3] == znak && plansza[4][4] == znak && plansza[5][5] == znak) || (plansza[0][5] == znak && plansza[1][4] == znak && plansza[2][3] == znak && plansza[3][2] == znak && plansza[4][1] == znak && plansza[5][0] == znak))
                wynik = true;			// sprawdzenie przekatnych
        }
    }
    if (rozmiar == 7) {
        if (rzad == 3) {
            for (int i = 0; i < rozmiar && !wynik; i++)
                for (int j = 0; j < rozmiar-2 && !wynik; j++) {
                    if ((plansza[i][j] == znak && plansza[i][j+1] == znak && plansza[i][j+2] == znak) || (plansza[j][i] == znak && plansza[j+1][i] == znak && plansza[j+2][i] == znak))
                        wynik = true;	// sprawdzenie wierszy i kolumn
                    if ((plansza[j][j] == znak && plansza[j+1][j+1] == znak && plansza[j+2][j+2] == znak) || (plansza[j][rozmiar-1-j] == znak && plansza[j+1][rozmiar-2-j] == znak && plansza[j+2][rozmiar-3-j] == znak))
                        wynik = true;	// sprawdzenie przekatnych
                }
            int przekatne[4][6] = { {7,15,23,31,39,47},{1,9,17,25,33,41},{5,11,17,23,29,35},{13,19,25,31,37,43} };
            for (int i = 0; i < 4 && !wynik; i++)
                for (int j = 0; j < 5 && !wynik; j++)
                    if (plansza[przekatne[i][j] / rozmiar][przekatne[i][j] % rozmiar] == znak && plansza[przekatne[i][j+1] / rozmiar][przekatne[i][j+1] % rozmiar] == znak && plansza[przekatne[i][j+2] / rozmiar][przekatne[i][j+2] % rozmiar] == znak)
                        wynik = true;	// sprawdzenie cieciw dlugosci 6
            if ((plansza[2][2] == znak && ((plansza[0][4] == znak && plansza[1][3] == znak) || (plansza[1][3] == znak && plansza[1][3] == znak) || (plansza[1][3] == znak && plansza[0][4] == znak))) || (plansza[4][4] == znak && ((plansza[2][6] == znak && plansza[3][5] == znak) || (plansza[3][5] == znak && plansza[5][3] == znak) || (plansza[5][3] == znak && plansza[6][2] == znak))) || (plansza[4][2] == znak && ((plansza[2][0] == znak && plansza[3][1] == znak) || (plansza[3][1] == znak && plansza[5][3] == znak) || (plansza[5][3] == znak && plansza[6][4] == znak))) || (plansza[2][4] == znak && ((plansza[0][2] == znak && plansza[1][3] == znak) || (plansza[1][3] == znak && plansza[3][5] == znak) || (plansza[3][5] == znak && plansza[4][6] == znak))))
                wynik = true;			// sprawdzenie cieciw dlugosci 5
            if ((plansza[4][1] == znak && plansza[5][2] == znak && (plansza[3][0] == znak || plansza[6][3] == znak)) || (plansza[2][1] == znak && plansza[1][2] == znak && (plansza[3][0] == znak || plansza[0][3] == znak)) || (plansza[1][4] == znak && plansza[2][5] == znak && (plansza[0][3] == znak || plansza[3][6] == znak)) || (plansza[5][4] == znak && plansza[4][5] == znak && (plansza[6][3] == znak || plansza[3][6] == znak)))
                wynik = true;			// sprawdzenie cieciw dlugosci 4
            if ((plansza[2][0] == znak && plansza[1][1] == znak && plansza[0][2] == znak) || (plansza[0][4] == znak && plansza[1][5] == znak && plansza[2][6] == znak) || (plansza[4][0] == znak && plansza[5][1] == znak && plansza[6][2] == znak) || (plansza[6][4] == znak && plansza[5][5] == znak && plansza[4][6] == znak))
                wynik = true;			// sprawdzenie cieciw dlugosci 3
        }
        if (rzad == 4) {
            for (int i = 0; i < rozmiar && !wynik; i++)
                for (int j = 0; j < rozmiar-3 && !wynik; j++) {
                    if ((plansza[i][j] == znak && plansza[i][j+1] == znak && plansza[i][j+2] == znak && plansza[i][j+3] == znak) || (plansza[j][i] == znak && plansza[j+1][i] == znak && plansza[j+2][i] == znak && plansza[j+3][i] == znak))
                        wynik = true;	// sprawdzenie wierszy i kolumn
                    if ((plansza[j][j] == znak && plansza[j+1][j+1] == znak && plansza[j+2][j+2] == znak && plansza[j+3][j+3] == znak) || (plansza[j][rozmiar-1-j] == znak && plansza[j+1][rozmiar-2-j] == znak && plansza[j+2][rozmiar-3-j] && plansza[j+3][rozmiar-4-j] == znak))
                        wynik = true;	// sprawdzenie przekatnych
                }
            if ((plansza[3][2] == znak && plansza[4][3] == znak && ((plansza[1][0] == znak && plansza[2][1] == znak) || (plansza[2][1] == znak && plansza[5][4] == znak) || (plansza[5][4] == znak && plansza[6][5] == znak))) || (plansza[2][3] == znak && plansza[3][4] == znak && ((plansza[0][1] == znak && plansza[1][2] == znak) || (plansza[1][2] == znak && plansza[4][5] == znak) || (plansza[4][5] == znak && plansza[5][6] == znak))) || (plansza[3][4] == znak && plansza[4][3] == znak && ((plansza[1][6] == znak && plansza[2][5] == znak) || (plansza[2][5] == znak && plansza[5][2] == znak) || (plansza[5][2] == znak && plansza[6][1] == znak))) || (plansza[3][2] == znak && plansza[2][3] == znak && ((plansza[5][0] == znak && plansza[4][1] == znak) || (plansza[4][1] == znak && plansza[1][4] == znak) || (plansza[1][4] == znak && plansza[0][5] == znak))))
                wynik = true;			// sprawdzenie cieciw dlugosci 6
            if ((plansza[3][0] == znak && ((plansza[2][1] == znak && plansza[1][2] == znak && plansza[0][3] == znak) || (plansza[4][1] == znak && plansza[5][2] == znak && plansza[6][3] == znak))) || (plansza[3][6] == znak && ((plansza[2][5] == znak && plansza[1][4] == znak && plansza[0][3] == znak) || (plansza[4][5] == znak && plansza[5][4] == znak && plansza[6][3] == znak))))
                wynik = true;			// sprawdzenie cieciw dlugosci 5
            if ((plansza[3][1] == znak && plansza[4][2] == znak && plansza[5][3] == znak && (plansza[2][0] == znak || plansza[6][4] == znak)) || (plansza[3][1] == znak && plansza[2][2] == znak && plansza[1][3] == znak && (plansza[4][0] == znak || plansza[0][4] == znak)) || (plansza[1][3] == znak && plansza[2][4] == znak && plansza[3][5] == znak && (plansza[0][2] == znak || plansza[4][6] == znak)) || (plansza[5][3] == znak && plansza[4][4] == znak && plansza[3][5] == znak && (plansza[6][2] == znak || plansza[2][6] == znak)))
                wynik = true;			// sprawdzenie cieciw dlugosci 4
        }
        if (rzad == 5) {
            for (int i = 0; i < rozmiar && !wynik; i++)
                if ((plansza[i][2] == znak && plansza[i][3] == znak && plansza[i][4] == znak && ((plansza[i][0] == znak &&  plansza[i][1] == znak) || (plansza[i][1] == znak && plansza[i][5] == znak) || (plansza[i][5] == znak && plansza[i][6] == znak))) || (plansza[2][i] == znak && plansza[3][i] == znak && plansza[4][i] == znak && ((plansza[0][i] == znak && plansza[1][i] == znak) || (plansza[1][i] == znak && plansza[5][i] == znak) || (plansza[5][i] == znak && plansza[6][i] == znak))))
                    wynik = true;		// sprawdzenie wierszy i kolumn
            if ((plansza[2][2] == znak && plansza[3][3] == znak && plansza[4][4] == znak && ((plansza[0][0] == znak && plansza[1][1] == znak) || (plansza[1][1] == znak && plansza[5][5] == znak) || (plansza[5][5] == znak && plansza[6][6] == znak))) || (plansza[4][2] == znak && plansza[3][3] == znak && plansza[2][4] == znak && ((plansza[0][6] == znak && plansza[1][5] == znak) || (plansza[1][5] == znak && plansza[5][1] == znak) || (plansza[5][1] == znak && plansza[6][0] == znak))))
                wynik = true;			// sprawdzenie przekatnych
            if ((plansza[2][1] == znak && plansza[3][2] == znak && plansza[4][3] == znak && plansza[5][4] == znak && (plansza[1][0] == znak || plansza[6][5] == znak)) || (plansza[4][1] == znak && plansza[3][2] == znak && plansza[2][3] == znak && plansza[1][4] == znak && (plansza[0][5] == znak || plansza[5][0] == znak)) || (plansza[5][2] == znak && plansza[4][3] == znak && plansza[3][4] == znak && plansza[2][5] == znak && (plansza[1][6] == znak || plansza[6][1] == znak)) || (plansza[1][2] == znak && plansza[2][3] == znak && plansza[3][4] == znak && plansza[4][5] == znak && (plansza[5][6] == znak || plansza[0][1] == znak)))
                wynik = true;			// sprawdzenie cieciw dlugosci 6
            if ((plansza[0][2] == znak && plansza[1][3] == znak && plansza[2][4] == znak && plansza[3][5] == znak && plansza[4][6] == znak) || (plansza[6][2] == znak && plansza[5][3] == znak && plansza[4][4] == znak && plansza[3][5] == znak && plansza[2][6] == znak) || (plansza[2][0] == znak && plansza[3][1] == znak && plansza[4][2] == znak && plansza[5][3] == znak && plansza[6][4] == znak) || (plansza[4][0] == znak && plansza[3][1] == znak && plansza[2][2] == znak && plansza[1][3] == znak && plansza[0][4] == znak))
                wynik = true;			// sprawdzenie cieciw dlugosci 5
        }
        if (rzad == 6) {
            for (int i = 0; i < rozmiar && !wynik; i++)
                if ((plansza[i][1] == znak && plansza[i][2] == znak && plansza[i][3] == znak && plansza[i][4] == znak && plansza[i][5] == znak && (plansza[i][0] == znak || plansza[i][6] == znak)) || (plansza[1][i] == znak && plansza[2][i] == znak && plansza[3][i] == znak && plansza[4][i] == znak && plansza[5][i] == znak && (plansza[0][i] == znak || plansza[6][i] == znak)))
                    wynik = true;		// sprawdzenie wierszy i kolumn
            if ((plansza[1][1] == znak && plansza[2][2] == znak && plansza[3][3] == znak && plansza[4][4] == znak && plansza[5][5] == znak && (plansza[0][0] == znak || plansza[6][6] == znak)) || (plansza[1][5] == znak && plansza[2][4] == znak && plansza[3][3] == znak && plansza[4][2] == znak && plansza[5][1] == znak && (plansza[0][6] == znak || plansza[6][0] == znak)))
                wynik = true;			// sprawdzenie przekatnych
            if ((plansza[1][0] == znak && plansza[2][1] == znak && plansza[3][2] == znak && plansza[4][3] == znak && plansza[5][4] == znak && plansza[6][5] == znak) || (plansza[0][1] == znak && plansza[1][2] == znak && plansza[2][3] == znak && plansza[3][4] == znak && plansza[4][5] == znak && plansza[5][6] == znak) || (plansza[5][0] == znak && plansza[4][1] == znak && plansza[3][2] == znak && plansza[2][3] == znak && plansza[1][4] == znak && plansza[0][5] == znak) || (plansza[6][1] == znak && plansza[5][2] == znak && plansza[4][3] == znak && plansza[3][4] == znak && plansza[2][5] == znak && plansza[1][6] == znak))
                wynik = true;			// sprawdzenie cieciw dlugosci 6
        }
    }
    if (wynik)
        if (!cisza) {
            getPlansza();
            cout << endl << "WYGRYWA GRACZ " << znak << endl;
        }
    return wynik;
}

int Gra::minimax(char gracz, int poziom) {
    int mmx, m;
    if (wygrana(gracz,true))
        return gracz == *SI ? 1000 : -1000;
    if (remis(true))
        return 0;
    gracz = ((gracz == *SI) ? *GRACZ : *SI);
    mmx = (1+poziom) * ((gracz == *GRACZ) ? 10 : -10);
    if (poziom > 3)
        return mmx;
    for (int i = 0; i < rozmiar*rozmiar; i++)
        if (plansza[i/rozmiar][i%rozmiar] == ' ') {
            plansza[i/rozmiar][i%rozmiar] = gracz;
            m = minimax(gracz,poziom++);
            plansza[i/rozmiar][i%rozmiar] = ' ';
            if (((gracz == *GRACZ) && (m < mmx)) || ((gracz == *SI) && (m > mmx)))
                mmx = m;
        }
    return mmx;
}

int Gra::komputer() {
    int ruch = -1;
    int m, mmx = -10000;
    for (int i = 0; i < rozmiar*rozmiar; i++)
        if (plansza[i/rozmiar][i%rozmiar] == ' ') {
            plansza[i/rozmiar][i%rozmiar] = *SI;
            cout << '.';
            m = minimax(*SI,0);
            plansza[i/rozmiar][i%rozmiar] = ' ';
            if (m > mmx) {
                mmx = m;
                ruch = i;
            }
        }
    return ruch;
}

void Gra::ruch(char gracz, int licznik) {
    int ruch;
    getPlansza();
    do {
        if (gracz == *GRACZ) {
            do {
                cout << endl << "GRACZ - wybiera ruch:   ";
                cin >> ruch;
                if (!cin.good()) {
                    cin.ignore(10000,'\n');
                    cin.clear();
                    cin.sync();
                }
            } while (!cin.good());
        } else {
// warunki sterujace losowaniem ruchu komputera - przy duzej planszy i malej ilosci dotychczasowych ruchow losujemy
            if (((rozmiar == 5 || rozmiar == 6) && rzad <= 4 && licznik < 2) || (rozmiar >= 5 && rzad > 4 && licznik < 3)) {
                ruch = ksiega_otwarc();
                ruch++;
                cout << endl << "KOMPUTER - wybiera ruch:   " << ruch << endl;
            } else {
                cout << endl;
                ruch = komputer();
                ruch++;
                cout << endl << "KOMPUTER - wybiera ruch:   " << ruch << endl;
            }
        }
        cout << "------------------------------" << endl;
    } while (!(ruch >= 1 && ruch <= rozmiar*rozmiar && plansza[(ruch-1)/rozmiar][(ruch-1)%rozmiar] == ' '));
    plansza[(ruch-1)/rozmiar][(ruch-1)%rozmiar] = *SI;
    //gracz = ((gracz == *GRACZ) ? *SI : *GRACZ);
}

