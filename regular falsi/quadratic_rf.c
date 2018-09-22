#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Function prototypes
float f(float x);
float falsi(float a, float b);

int main()
{
  float a, b; //Interval boundaries
  float root; //Root of the funciton f

  //Getting interval from the user
  printf("Enter a: ");
  scanf("%f", &a);
  printf("Enter b: ");
  scanf("%f", &b);

  if(f(a)*f(b) >= 0)
  {
      printf("No solutions found in the given interval\n");
      exit (1);
  }
  root = falsi(a, b); //Calling falsi function 
  printf("Root of the given equation: %f\n", root);

  exit (0);
}

float falsi(float a, float b)
{
  float c, x, y;

  while (1)
  {
      c = (a*f(b) - b*f(a))/(f(b) - f(a));

      printf("checking %f\n", c);
      if(f(c) == 0)
      {
          return c;
      }
      if(f(a)*f(c) < 0)
      {
          b = c;
      }
      else
      {
          a = c;
      }

      x = round(a*100000)/100000;
      y = round(b*100000)/100000;

      if(x == y)
      {
          return a;
      }
  }
}

float f(float x)
{
  return x*x + 5*x + 2;
}
