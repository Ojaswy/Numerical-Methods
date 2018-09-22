/*This pogram finds the solution of f(x) = 3x - cosx -1 by using chebyschev method.
This method finds the root by approximating an equation by approximating it to a quadratic equation.
Consider the approximation (a).
Differentiate the equation twice.
Substitute 'a' in the equations.
On solving we get the next iteration value as
   b = a - (fa/da) - (0.5*((fa*fa*dda)/(da*da*da))).
This program gives upto six digit accuracy.
*/

/*The program starts here*/

#include <stdio.h>
#include <stdlib.h>
#include <values.h>
#include <math.h>

/*Function declarations*/

double result(double val);
double diff(double val);
double ddiff(double val);

/*Main starts here*/

int main(void)
{

/*Declaring variables*/

  double fa, da, dda;
  double a, b, temp = MININT;
  int i=0;

/*Taking the inputs*/

  printf("Enter the approximation\n");
  scanf("%lf", &a);

  while (a != b) {
        fa = result(a);/*Finding the function value of a*/
        da = diff(a);/*Finding differentiation value of a*/
        dda = ddiff(a);/*Finding double differentiation value of a*/

        b = a - (fa/da) - (0.5*((fa*fa*dda)/(da*da*da)));

        if (floor(b) == floor(temp)) {/*Comparing the value of b and temp*/
           printf("The root is %lf\n", b);/*Printing the root*/
           exit(0);
        }

        printf("The value in iteration %d is %lf\n", i, b);

        if (floor(a) == floor(b)) {/*Comparing a and b*/
           printf("The root is %lf\n", b);/*Printing the roots*/
           exit(0);
        }
        else {
             a = b;/*Assigning b to a for next iteration*/
             b = temp;/*Assigning temp to b for next iteration*/
        }

        i++;/*Incrementing i*/
  }
  exit(0);
}

/*Function starts here*/
/*This function gives the value of equation*/

double result(double val)
{ 
  double f;

  f = 3*val - cosf(val) -1 ;/*Getting the function value*/
  return f;
}
 
/*Function starts here*/
/*This function gives the differentiation value*/

double diff(double val)
{
  double num;

  num = 3 + sinf(val);
  return num;
}

/*Function starts here*/
/*This function gives the differentiation value*/

double ddiff(double val)
{
  double cal;

  cal = cosf(val);
  return cal;
}
