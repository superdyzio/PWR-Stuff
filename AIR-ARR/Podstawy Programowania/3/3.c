#include <stdio.h>
#define MIN -5
#define MAX +5

int main() 
{ int a,b,c,d,e;
  printf("Podaj 1. parametr:");
  scanf("%d",&a);
  if ( (a>=MIN) && (a<=MAX) ) printf("Parametr 1. ustawiony na:%d\n",a);
   else printf("Bledny parametr!\n");
  printf("Podaj 2. parametr:");
  scanf("%d",&b);
  if ( (b>=MIN) && (b<=MAX) ) printf("Parametr 2. ustawiony na:%d\n",b);
   else printf("Bledny parametr!\n");  
  printf("Podaj 3. parametr:");
  scanf("%d",&c);
  if ( (c>=MIN) && (c<=MAX) ) printf("Parametr 3. ustawiony na:%d\n",c);
   else printf("Bledny parametr!\n");
  printf("Podaj 4. parametr:");
  scanf("%d",&d);
  if ( (d>=MIN) && (d<=MAX) ) printf("Parametr 4. ustawiony na:%d\n",d);
   else printf("Bdny parametr!\n");
  printf("Podaj 5. parametr:");
  scanf("%d",&e);
  if ( (e>=MIN) && (e<=MAX) ) printf("Parametr 5. ustawiony na:%d\n",e);
   else printf("Bledny parametr!\n");
  return 0;
}

	
