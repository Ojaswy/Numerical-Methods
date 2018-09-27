#include <stdio.h>
#include <stdlib.h>

//defining function prototype
float f(float x);

//function main begins here
int main()
{
 float h, a = 0, b = 2, ans = 0;
  //h here is the length of the interval
  //a,b are the lower and upper limits
  //n here means the number of intervals
  int   n, i;

  printf("Enter the value of h: ");
  scanf("%f", &h);
  
  n = (b-a)/(h);

  for (i = 1; i < n; i++)
  {
     ans += 2*f(a + i*h); 
  }
 
  ans = (h/2)*(f(a) + f(b) + ans);  

  printf("Answer: %f\n", ans);

  exit(0);
}
//function main ends here

//defining function float 
float f(float x)
{
  return 0.2 + 25*x + 3*x*x;
  //retunrs the function 
}
