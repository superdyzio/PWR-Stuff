#include <stdio.h>
#include <math.h>

int main()
{ float a, b, c, delta, x1, x2;
  printf("Podaj wartosci a,b,c:\n");
  scanf("%f",&a);
  scanf("%f",&b);
  scanf("%f",&c);
  delta = b * b - 4 * a * c;
  printf("Funkcja kwadratowa przyjmuje wartosci ponizej zera w przedziale\n");
  if ( delta > 0)
    { x1 = ( - b - sqrt( delta ) ) / 2 * a;
      x2 = ( - b + sqrt( delta ) ) / 2 * a;
      printf("%f\n",x1);
      printf("%f\n",x2);
    }
  else if (delta = 0) x1 = x2 = -b / (2*a);
       else if (a>=0) printf("jednak nie przyjmuje he he he\n");
            else printf("dla kazdego iks\n");
  return 0;
}
