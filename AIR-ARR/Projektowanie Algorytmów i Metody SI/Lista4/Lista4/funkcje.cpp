#include "funkcje.h"

Klasa::Klasa(double i) {
	ilosc = (int)(i * ROZMIAR / 100);
	srand(time(NULL));
	for (int j = 0; j < ROZMIAR; j++) 
		if (j < ilosc)
			tab[j] = j;
		else
			tab[j] = (rand() % ZAKRES) + ilosc;
	for (int j = 0; j < ROZMIAR; j++)
		sort[j] = tab[j];
}

void Klasa::nowaTab() {
	srand(time(NULL));
	for (int j = 0; j < ROZMIAR; j++) 
		if (j < ilosc)
			tab[j] = j;
		else
			tab[j] = (rand() % ZAKRES) + ilosc;
	for (int j = 0; j < ROZMIAR; j++)
		sort[j] = tab[j];
}

void Klasa::wyswietlTab() {
	for (int i = 0; i < ROZMIAR; i++)
		cout << tab[i] << " ";
	cout << endl;
}

void Klasa::wyswietlSort() {
	for (int i = 0; i < ROZMIAR; i++)
		cout << sort[i] << " ";
	cout << endl;
}

bool Klasa::dobrze() {
	bool wynik = true;
	for (int i = 0; i < ROZMIAR-1 && wynik; i++)
		if (sort[i] > sort[i+1])
			wynik = false;
	return wynik;
}

void Klasa::odwrocTab() {
	int pom;
	for (int i = 0; i < ROZMIAR/2; i++) {
		pom = tab[i];
		tab[i] = tab[ROZMIAR-i-1];
		tab[ROZMIAR-i-1] = pom;
	}
}

void Klasa::merge(int low, int mid, int high) {
	int h, i, j, pom[ROZMIAR], k;
	h = low;
	i = low;
	j = mid + 1;
	while ( (h <= mid) && (j <= high) ) {
		if (sort[h] <= sort[j]) {
			pom[i] = sort[h];
			h++;
		}
		else {
			pom[i] = sort[j];
			j++;
		}
		i++;
	}
	while (h <= mid) {
		pom[i] = sort[h];
		i++;
		h++;
	}
	while (j <= high) {
		pom[i] = sort[j];
		i++;
		j++;
	}
	for (k = low; k <= high; k++) 
		sort[k] = pom[k];
}

void Klasa::merge_sort(int low, int high) {
	int mid;
	if(low < high) {
		mid = (low+high) / 2;
		merge_sort(low,mid);
		merge_sort(mid+1,high);
		merge(low,mid,high);
	}
}

struct MergePosInfo {
    int left;
    int mid;
    int right;
};

void Klasa::Merge_Sort_Iterative(int left, int right) {
    int mid;
    if (right <= left)
        return;
    vector<pair<int, int>> list(ROZMIAR);
    vector<MergePosInfo> mlist(ROZMIAR);
    list.push_back(pair<int, int>(left, right));
    MergePosInfo info;
    while(list.size() != 0) {
        left = list.back().first;
        right = list.back().second;
        list.pop_back();
        mid = (right + left) / 2;
        if(left < right) {
            info.left = left;
            info.right = right;
            info.mid = mid;
            mlist.push_back(info);
            list.push_back(pair<int, int>(left, mid));
            list.push_back(pair<int, int>(mid+1, right));
        }
    }
    for(int i = mlist.size() - 1; i >= 0; i--)
      merge(mlist[i].left, mlist[i].mid, mlist[i].right);
}

void Klasa::quicksort(int lewy, int prawy) {
	if(lewy<prawy) {
      int m = lewy;
      for (int i = lewy+1; i <= prawy; i++)
         if (sort[i] < sort[lewy])
            swap(sort[++m],sort[i]);
      swap(sort[lewy],sort[m]);
      quicksort(lewy,m-1);
      quicksort(m+1,prawy);
   }
}

void Klasa::quicksort2(int lewy, int prawy) {
	 int i = lewy;
     int j = prawy;
     int x = sort[(lewy+prawy)>>1];
     do {
		while (sort[i] < x) i++;
        while (sort[j] > x) j--;
        if (i <= j) {                  
			int temp = sort[i];
            sort[i] = sort[j];
            sort[j] = temp;
            i++;
            j--;
		}
     } while (i <= j);
     if (lewy < j) quicksort2(lewy,j);
     if (prawy > i) quicksort2(i,prawy);   
}

void Klasa::sortIntro() {
	int pocz = 0;
	int kon = ROZMIAR-1;
	if (kon-pocz > 0)
		IntroQuick(pocz, kon,(int)floor(2*log(ROZMIAR)/0.693147180559945309417));
}

void Klasa::IntroQuick(int poc, int kon, int rec) {
	if (rec <= 0) {
		for (int i = ((kon-poc+1)/2-1); i >= 0 ; i--)
			Heapify(i,(kon-poc+1));
		int tmp;
		for (int i = (kon-poc+1); i > 0; i--) {
			Heapify(0, i);
			tmp = sort[0];
			sort[0] = sort[i-1];
			sort[i-1] = tmp;
		}
	}
	else 
		if (poc < kon) {
			int m = poc;
			int tmp;
			for (int i = poc+1; i <= kon; i++) {
				if (sort[i] < sort[poc]) {
					m++;
					tmp = sort[m];
					sort[m] = sort[i];
					sort[i] = tmp;
				}
			}
			tmp = sort[m];
			sort[m] = sort[poc];
			sort[poc] = tmp;
			IntroQuick(poc, m-1,rec-1);
			IntroQuick(m+1, kon,rec-1);
		}
}

void Klasa::Heapify(int i, int dl) {
	int pocz,kon,largest;
	int tmp;
	pocz = 2*i+1;
	kon = 2*i+2;
	if (pocz<dl) 
		if( (*this).sort[pocz] > (*this).sort[i])
			largest = pocz;
		else
			largest = i;
	else
		largest = i;
	if (kon < dl) 
		if (sort[kon] > sort[largest])
			largest = kon;
	if (largest != i) {
		tmp = sort[i];
		sort[i] = sort[largest];
		sort[largest] = tmp;
		Heapify(largest, dl);
	}
}