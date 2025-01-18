#include <math.h>
#include <stdio.h>
#include <stdlib.h>


int isAllNumsPositive(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    if (arr[i] < 0) {
      return 0;
    }
  }
  return 1;
}


void firstVarProgTwo() {
  int syst, mon, kbd, mouse, n;
  int *arr = (int *)malloc(5 * sizeof(int));
  do {
    printf("Enter block price >>> ");
    scanf("%d", &syst);
    printf("Enter monitor price >>> ");
    scanf("%d", &mon);
    printf("Enter keyboard price >>> ");
    scanf("%d", &kbd);
    printf("Enter mouse price >>> ");
    scanf("%d", &mouse);

    printf("Enter the number of computers >>> ");
    scanf("%d", &n);

    arr[0] = syst;
    arr[1] = mon;
    arr[2] = kbd;
    arr[3] = mouse;
    arr[4] = n;
  } while (!(isAllNumsPositive(arr, 5)));

  printf("Result: %d rubles\n", (syst + mon + kbd + mouse) * n);
  free(arr);
}


// int main() {
//  firstVarProgTwo();
//  return 0;
// }
