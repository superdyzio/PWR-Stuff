#include <stdio.h>
#include <math.h>

int main()
{ int a;
  int b;
  int c;
  printf("Podaj trzy liczby całkowite:\n");
  scanf("%i\n",&a);
  scanf("%i\n",&b);
  scanf("%i",&c);
  printf("Najwieksze jest: ");
  if ( a > b)
    if ( a > c) printf("%i\n",a);
    else printf("%i\n",c);
   else if ( b > c) printf("%i\n",b);
        else printf("%i\n",c);
  return 0;
}
