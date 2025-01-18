#include <stdio.h>
#include <math.h>
#include "numopers.h"


float func(float x, int n) {
    if (n <= 0) {
        return 1; 
    }

    
    float result = 2 * x * func(x, n - 1) - (3 * pow(x, 2) + 20 * x - 1) * func(x, n - 2);

    return result;
}

void taskRecentThree() {
    float x;
    int n;

    printf("Enter X: ");
    scanf("%f", &x);

    do {
        printf("Enter N: ");
        scanf("%d", &n);
    } while (!(ifNumPositive(n)));

    printf("Result: %g\n", func(x, n));

}


// int main() {
//  taskRecentThree();
//  return 0;
// }

