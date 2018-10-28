/* Solution of System of linear equations by GAUSS JORDAN METHOD */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
  int i = 1, j = 1, k = 1, r;             /* variable declaration */
  
  printf("Enter no of algebric equations(Rows of matrix) : \n");
  scanf("%d", &r);                         /* Number of linear equations */

  float a[r][r] , b[r][1], out[r][r];      /* a[r][r] = coefficient matrix*/
  float x[r];                              /* out[r][r] = temporary matrix */

  for (i = 1; i < r+1; i++) {           /* loop for taking inputs of linear eq*/
    for(j = 1; j < r+1; j++) {
      printf("Enter a[%d][%d] = ", i, j);  /* input coefficients */
      scanf("%f", &a[i][j]);
      out[i][j] = a[i][j] ;
    }
  }


  for (i = 1 ; i < r+1 ; i++) {
    printf("Enter b[%d][1] = ", i );
    scanf("%f", &b[i][1]);
  }

  i = 1, j = 1;

  for (i = 1 ; i < r+1 ; i++) {            /* loop for redusing matrix  */
    for ( j = 1 ; j < r+1 ; j++) {
      if ( j == i ) {
        continue;
      }
      for ( k = 1 ; k < r+1 ; k++) {
        out[j][k] = out[j][k] - ((a[i][k])*(a[j][i]/a[i][i]));
      }
      b[j][1] = b[j][1] - (b[i][1]*(a[j][i]/a[i][i]));
      for ( k = 1 ; k < r+1 ; k++ ) {
        a[j][k] = out[j][k] ;
      }
    }
  }
  
  for (i = 1; i < r+1; i++) {         /* final coefficients matrix */
    for(j = 1; j < r+1; j++) {
      printf(" a[%d][%d] =  %f\n", i, j, a[i][j]);
    }
    printf(" b[%d][1] =  %f\n", i, b[i][1]);

  }

  for ( i = 1 ; i < r+1 ; i++ ) {     /* Final values of x[i] */
    x[i] = b[i][1] / a[i][i] ;
    printf("x[%d] = %f \n", i, x[i] );    
  }
  exit(0);
}
