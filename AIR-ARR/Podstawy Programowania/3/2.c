#include <stdio.h>
#define MIN -100
#define MAX +100

int main () 
{  int temperatura;	 
   printf("Podaj temperature we Wroclawiu: ");
   scanf("%d",&temperatura);
   if ( (temperatura < MIN) || (temperatura > MAX) ) printf("Bledne dane!\n");               
	 else if (temperatura >= 20) printf("Jest bardzo ladna pogoda!\n");
		else printf("Nie jest zbyt cieplo!\n");
 return 0;
}
	 
	
