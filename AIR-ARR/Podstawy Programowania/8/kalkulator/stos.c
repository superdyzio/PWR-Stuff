#include "stos.h"

Stos* push(int liczba, Stos *stos){
	Stos *nowy;
	nowy = (Stos *) malloc(sizeof(Stos));
	nowy->ponizej = stos;
	nowy->liczba = liczba;
	return nowy;
}

Stos* pop(Stos **stos){
	Stos *s;
	s = *stos;
	if (s==NULL) return NULL;
	*stos = s->ponizej;
	s->ponizej = NULL;
	return s;
}

void print(Stos *s){
	Stos *i;
	i = s;
	while (i != NULL){
		printf("%i -> ",i->liczba);
		i = i->ponizej;
	}
	printf("NULL\n");
}

void czysc(Stos **s){
	Stos *i;
	i = *s;
	while (i != NULL){
		*s = i->ponizej;
		free(i);
		i = *s;
	}
	*s = i;
}

int ilosc(Stos *s){
	Stos *i;
	int x = 0;
	i = s;
	while (i != NULL){
		x++;
		i = i->ponizej;
	}
	return x;
}