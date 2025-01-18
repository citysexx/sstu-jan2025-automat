#include <stdio.h>
#include <math.h>

float function(float x, float y) {
  if (x == pow(y, 2) || y == pow(x, 2)) {
    return 0;    
  } else {
    int val = (x <= y) ? 1 : 2;
    return val;
  }
}


void secondVarProgOne() {
  float x;
  printf("Enter X >>> ");
  scanf("%f", &x);
  float y;
  printf("Enter Y >>> ");
  scanf("%f", &y);

  printf("Result is %g\n", function(x, y));
}


// int main() {
//  secondVarProgOne();
//  return 0;
// }
