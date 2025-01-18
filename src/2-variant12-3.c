#include <stdio.h>

void secondVarProgThree() {
  int found = 0;
  for (int i = 0; i < 4; i++) {
    int num;
    printf("Enter number %d >>> ", i + 1);
    scanf("%d", &num);

    while (num < 100 || num > 999) {
      printf("Invalid number!\n");
      printf("Enter number %d >>> ", i + 1);
      scanf("%d", &num);
    }

    if ((num / 10) % 10 == 0) {
      found++;
    }
  }


  if (found == 4) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }

}


// int main() {
//  secondVarProgThree();
//  return 0;
// }
