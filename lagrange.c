#include <stdio.h>
#include <stdlib.h>

/**** MAIN FUNCTION STARTS HERE ****/

float lj(float y, int j, int n, float x[]);

int main()
{
  float p = 0; 
  float zzz;
  float x[100], f[100];  
  int   n, i; 

  printf("Enter no. of distinct x value : ");
  scanf("%d", &n);

//x and f(x) values are taken here

  for (i = 0; i < n; i++)
  {
    printf("Enter   x%d : ", i);
    scanf("%f", &x[i]);
    
    printf("Enter f(x%d): ", i);
    scanf("%f", &f[i]);   
  }

  printf("ENter the value where we have to interpoate :");
  scanf("%f", &zzz);

//the iterpolation is done here

  for (i = 0; i < n; i++)
  {
    p += lj(zzz, i, n, x)*f[i];       
  }

  printf("p(%f) = %f\n", zzz, p);

  exit(0);
}

//this function calculates the l_k for a given k

/**** lj FUNCION STARTS HERE ****/

float lj(float y, int j, int n, float x[])
{
  int i = 0;
  float l = 1;

  while (i != n)
  {
    if (i != j)
      l = l*( (y - x[i]) / (x[j] - x[i]) );

    i++;
  }

  return l;
}
