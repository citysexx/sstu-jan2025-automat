#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void firstVarProgOne() {
  int x, y;
  printf("Enter your number X >>> ");
  scanf("%d", &x);
  printf("\n");

  printf("Enter your number Y >>> ");
  scanf("%d", &y);
  printf("\n");
  
  printf("Answer: %d", ((x + y) / (x + 1)) - ((x * y - 12) / (34 + x)));
  printf("\n");
}


// int main() {
//  firstVarProgOne();
//  return 0;
// }
