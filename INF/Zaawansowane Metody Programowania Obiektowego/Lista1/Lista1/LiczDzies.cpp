#include "LiczDzies.hh"

void CLiczDzies::v_zeruj(int tab[]) {
	for (int i = 0; i < d_dlugosc; i++)
		tab[i] = 0;
}

CLiczDzies vWczytajD() {
	int d_dl = 0;
	while (d_dl <= 0 || d_dl > MAX_SIZE) {
		cout << "Podaj dlugosc liczby: ";
		cin >> d_dl;
	}
	CLiczDzies c_ret(d_dl);
	int d_lic;
	cout << "Podaj liczbe: ";
	cin >> d_lic;
	for (int i = 0; i < d_dl; i++) {
		c_ret.pi_liczba[i] = d_lic % 10;
		d_lic /= 10;
	}
	return c_ret;
}

void CLiczDzies::vWypiszD() {
	int suma = 0;
	for (int i = 0; i < d_dlugosc; i++)
		suma += pi_liczba[i] * (int)pow(10,i);
	cout << suma << endl;
}

CLiczDzies CLiczDzies::cDodajD(CLiczDzies cLiczba) {
	CLiczDzies c_ret((d_dlugosc>=cLiczba.d_dlugosc ? d_dlugosc : cLiczba.d_dlugosc) + 1);
	int d_wynik = 0;
	int d_przeniesienie = 0;
	for (int i = 0; i < c_ret.d_dlugosc; i++) {
		d_wynik = pi_liczba[i] + cLiczba.pi_liczba[i] + d_przeniesienie;
		c_ret.pi_liczba[i] = d_wynik % 10;
		d_przeniesienie = d_wynik / 10;
	}
	return c_ret;
}

CLiczDzies CLiczDzies::cOdejmijD(CLiczDzies cLiczba) {
	CLiczDzies c_ret;
	return c_ret;
}

CLiczDzies CLiczDzies::cPomnozD(CLiczDzies cLiczba) {
	CLiczDzies c_ret;
	return c_ret;
}