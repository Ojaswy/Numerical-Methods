/* Simpson's Rule is a numerical method for approximating 
   the integral of a function between two limits, a and b. 
   It's based on knowing the area under a parabola, or a plane curve.
*/

//Header files
#include <stdio.h>
#include <stdlib.h>

//defining function prototype
float f(float x);

//function main begins here
int main()
{
  float h, a = 0, b = 1, ans = 0;
  //h here is the length of the interval
  //a,b are the lower and upper limits
  //n here means the number of intervals
  int   n, i;

  printf("Enter the value of h: ");
  scanf("%f", &h);
  
  n = (b-a)/(2*h);

  for (i = 1; i < 2*n; i++)
  {
    if (i % 2 == 0)
      ans += 2*f(a + i*h);   
    else 
      ans += 4*f(a + i*h); 
  }
 
  ans = (h/3)*(f(a) + f(b) + ans);  

  printf("Answer: %f\n", ans);

  exit(0);
}
//function main ends here

//defining function float 
float f(float x)
{
 return log(1 + x);
//retunrs the function 
}
