#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrixutils.h"


int **swapMatrixRows(int height, int width, int **matrix) {
  int row1;
  int row2;

  if (height % 2 == 0) {
    row1 = height / 2 - 1;
    row2 = height / 2;
  } else {
    row1 = 0;
    row2 = height - 1;
  }

  int *buffer = matrix[row1];
  matrix[row1] = matrix[row2];
  matrix[row2] = buffer;

  return matrix;
}


void fourthVarProgOne() {
  int height;
  int width;
  
  // making sure the array is square
  do {
    printf("Enter matrix height >>> ");
    scanf("%d", &height);
    printf("Enter matrix width >>> ");
    scanf("%d", &width);
  } while (height != width);
  

  int **matrix = spawnMatrix(height, width, 1);
  viewMatrix(height, width, matrix, "Old");
  printf("++++++++++++++++++++++++++++++++\n");
  matrix = swapMatrixRows(height, width, matrix);
  viewMatrix(height, width, matrix, "New");
  
  free(matrix);
  
}


// int main() {
//  fourthVarProgOne();
//  return 0;
// }
