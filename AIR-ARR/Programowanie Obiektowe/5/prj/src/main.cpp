#include "iloczyn.hh"
#include "zespolone.hh"
#include "symbole.hh"
#include "typ.hh"

int main() {
	Macierz m1, m2, wynm;
	Wektor w1, w2, wynw;
	TYP wynx;
	int x = 0, y = 0, z = 0;
	char znak;
	cout.setf(ios::fixed);
	cout.precision(2);
	while( (!cin.eof()) || (x < 5) ) {
		cin >> znak;
		if ( (cin.fail()) && (x != 10) ) {
				cin.clear();
				cin.ignore(1000,'\n');
				cout << endl << "Koniec danych." << endl;
				x = 10;
		}
		else {
			if (znak == '|') {
				cin.unget();
				cin >> m1;
				if ( (cin.fail()) && (x != 10) ) {
					cin.clear();
					cin.ignore(1000,'\n');
					cout << znak;
					cout << endl << "Niepoprawny argument. Koniec działania programu." << endl;
					x = 10;
				}
				else x = 1;
	      		}
 		   	else {
				cin.unget();
	      			cin >> w1;
	      			if ( (cin.fail()) && (x != 10) ) {
					cin.clear();
					cin.ignore(1000,'\n');
					cout << endl << "Niepoprawny argument. Koniec działania programu." << endl;
					x = 10;
				}
				else x = 2;
	      		}
			cin >> znak;
			if (znak == '|') {
				cin.unget();
				cin >> m2;
				if ( (cin.fail()) && (x != 10) ) {
					cin.clear();
					cin.ignore(1000,'\n');
					cout << endl << "Niepoprawny argument. Koniec działania programu." << endl;
					x = 10;
				} else y = 1;
	      		}
	    		else {
				cin.unget();
	      			cin >> w2;
	      			if ( (cin.fail()) && (x != 10) ) {
					cin.clear();
					cin.ignore(1000,'\n');
	      				cout << endl << "Niepoprawny argument. Koniec działania programu." << endl;
					x = 10;
				}
				else y = 2;
	      		}
			if (x == 2) { 
				if (y == 1) cout <<endl << "Wektor x Macierz to operacja niedozwolona." << endl;
				else {
					wynx=(w1*w2);
					z=1;
				}
			}
			else {
				if (x == 1) {
					if (y == 1) {
						wynm = (m1*m2);
						z = 2;
					}
					else {
						wynw = (m1*w2);
						z = 3;
					}
				}
			}
			if( (x != 10) && (z != 0) ) {
				cout << endl << "Argument 1:" << endl;
				if (x == 1) cout << m1;
				else cout << w1;
				cout << endl << "Argument 2:" << endl;
				if (y==1) cout << m2;
				else cout << w2;
				cout << endl << "Wynik:" << endl;
				switch (z) {
					case 1:	cout << wynx << endl;
						break;
					case 2:	cout << wynm << endl;
						break;
					case 3:	cout << wynw << endl;
						break;
				}	
				x = 0; y = 0; z = 0;
			}
		}	
	}
	cout << endl << "Program zostal skompliwany dla typu: " << NAZWA_TYPU << endl << endl;
}
