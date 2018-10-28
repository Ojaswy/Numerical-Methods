/* Solution of System of linear equations by GAUSS ELIMINATION */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
  int i = 1, j = 1, k = 1, r;            /* variable declaration */

  printf("Enter no of algebric equations(Rows of matrix) : \n");
  scanf("%d", &r);                      /* Number of linear equations */

  float a[r][r] , b[r][1], out[r][r];   /* a[r][r] = coefficient matrix*/    
  float x[r], value = 0;                /* out[r][r] = temporary matrix */ 

  for (i = 1; i < r+1; i++) {           /* loop for taking inputs of linear eq*/
    for(j = 1; j < r+1; j++) {
      printf("Enter a[%d][%d] = ", i, j);
      scanf("%f", &a[i][j]);           /* input coefficients */
      out[i][j] = a[i][j];
    }
  }
  

  for (i = 1 ; i < r+1 ; i++) {        /* input of linear eq */
    printf("Enter b[%d][1] = ", i );   
    scanf("%f", &b[i][1]);
  }

  for (i = 1; i < r+1 ; i++) {         /* loop for redusing matrix  */
    for ( j = i+1 ; j < r+1 ; j++) {
      for ( k = 1 ; k < r+1 ; k++) {
        out[j][k] = out[j][k] - ((a[i][k])*(a[j][i]/a[i][i]));
      }
      b[j][1] = b[j][1] - ((b[i][1])*(a[j][i]/a[i][i]));
      for ( k = 1; k < r+1 ; k++ ) {
        a[j][k] = out[j][k];
      }
    }
  }          
 
  for (i = 1; i < r+1; i++) {       /* final coefficients matrix */ 
    for(j = 1; j < r+1; j++) {
      printf(" a[%d][%d] =  %f\n", i, j, a[i][j]);
    }
    printf(" b[%d][1] =  %f\n", i, b[i][1]);
    
  }

  for ( i = r; i > 0 ; i--) {             /* Final values of x[i] */
    for (k = 1; k < r+1 ; k++) {
      value = value + ((a[i][k])*(x[k]));
//      printf("value = %f\n", value);
    }
    x[i] = (b[i][1]-value)/a[i][i];
    printf("x[%d] = %f \n", i, x[i]);  
    value = 0; 
  }

  exit(0);
}
