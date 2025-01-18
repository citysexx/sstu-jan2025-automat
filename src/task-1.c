#include <stdio.h>
#include <math.h>


int isNumberNatural(int num) {
    return (num > 0) ? 1 : 0;
}


float powerCustom(float x, int base) {
  if (base == 0) {
    return 1;
  }

  float number = 1;
  for (int i = 0; i < base; i++) {
    number *= x;
  }

  return number;
}


long long function_1(int number) {

    long long S = 0;

    for (int i = 1; i <= number; i++) {
        int a_i;
        if (i % 2 == 0) {
            a_i = i * 3;
        } else {
            a_i = i * (i - 2);
        }

        S += powerCustom(a_i - i, 2);
    }
    return S;
}


void taskRecentOne() {
    int number;
    printf("Enter a natural number N: ");
    scanf("%d", &number);

    if (!isNumberNatural(number)) {
        printf("Number is not natural\n");
    }

    printf("The result S is: %lld\n", function_1(number));

}


//int main() {
//  taskRecentOne();
//  return 0;
// }
