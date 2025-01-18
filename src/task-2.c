#include <stdio.h>
#include <stdlib.h>
#include "numopers.h"


char *bin(int number) {
    int iterNum = number;
    int size = 0;
    char *str = (char *)malloc(sizeof(char) * 33);  
    if (str == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    while (iterNum > 0) {
        str[size++] = (char)((iterNum % 2) + '0');
        iterNum /= 2;
    }

    str[size] = '\0';

    return str;
}

void taskRecentTwo() {
    int number;
    do {
        printf("Enter a positive number >>> ");
    } while (scanf("%d", &number) != 1 || number < 0);  // ensure the number is positive

    char *binary = bin(number);
    printf("Binary: %s\n", binary);
    free(binary);  // free the memory allocated for the binary string
}


// int main() {
//  taskRecentTwo();
//  return 0;
// }
