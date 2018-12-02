/*
 * this program solves 3 linear eqs in 3 variables by using LU decomposition
 * the matrix A is divided into 2 matrices L{lower triangular} and U{upper traingular}
 * the diagonal elements of U are taken as 1
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/****main function starts here ****/

int main()
{
  int  n;    //n stands for the number of variables

  printf("Enter n (number of variables) : ");
  scanf("%d", &n);

  float a[n][n+1], l[n][n], u[n][n];     //A,L,U have their usual meaning 
  int   i,j,k;                           //i,j,k are indices
  float z[n], ans[n];                    //LUX = ans , 	UX = Z



/*** finding U and traspose of L here ***/



  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      printf("Enter a%d%d  ", i+1, j+1);
      scanf("%f", &a[i][j]);
    }

    printf("Enter b%d  ", i+1);
    scanf("%f", &a[i][n]);
    printf("\n");
  }

  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      if (i > j)
      {
        l[i][j] = 0, u[i][j] = 0;
///        printf("u%d%d = %f  \n", i+1, j+1, u[i][j]);
///        printf("l%d%d = %f  \n", i+1, j+1, l[i][j]);
      }
      else if (i == j)
      {
        l[i][i] = a[i][i];
        for (k = 0; k <= i-1; k++)
        {
          l[i][i] -= l[k][i]*u[k][i];
        }
///        printf("l%d%d = %f  \n", i+1, j+1, l[i][j]);

        u[i][i] = 1;
///        printf("u%d%d = %f  \n", i+1, i+1, u[i][i]);
      }
      else      
      {
        l[i][j] = a[j][i];
        for (k = 0; k <= i-1; k++)
        {
          l[i][j] -= l[k][j]*u[k][i];
        }
///        printf("l%d%d = %f  \n", i+1, j+1, l[i][j]);

        u[i][j] = a[i][j];
        for (k = 0; k <= i-1; k++) 
        {
          u[i][j] -= l[k][i]*u[k][j];
        }
        u[i][j] = u[i][j]/l[i][i];
///        printf("u%d%d = %f  \n", i+1, j+1, u[i][j]);
      }
    }
  }


/*** finding L here ***/

  for (i = 0, j = 0; i < n; i++)
  {
    for (j = 0; j < i; j++)
    {	    
      l[i][j] = l[j][i];
      l[j][i] = 0;
///      printf("l%d%d = %f  \n", i+1, j+1, l[i][j]);
///      printf("l%d%d = %f  \n", j+1, i+1, l[j][i]);
    }
  }


/*** calculating Z here ***/


  for (i = 0; i < n; i++)
  {
    z[i] = a[i][n];
    for (j = i-1 ; j >= 0; j--)
    {
      z[i] -= z[j]*l[i][j];
    }
    z[i] = z[i]/l[i][i];
///    printf("z%d = %f \n", i+1, z[i]);
  }

/*** calculating X (ans) here ***/

  for (i = n-1; i >= 0; i--) 
  {
    ans[i] = z[i];
    for (j = n-1; j > i; j--)
    {
      ans[i] -= ans[j]*u[i][j];
    }
///    printf("x%d = %f \n", i+1, ans[i]);
  }


/*** printing solutions here ***/


  for (i = 0; i < n; i++)
  {
    printf("x%d = %f \n", i+1, ans[i]);
  }  



  exit(0);
}

