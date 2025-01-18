#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <stddef.h>
#include "matrixutils.h"
#include "arrayutils.h"
#include "numopers.h"
#include "intprompts.h"


#define REDCOLOR "\033[30;41m"
#define NORMCOLOR "\033[0m"


typedef struct {
  int *data;
  int size;
} DataSet;





DataSet markRowsToDelete(int **matrix, int height, int width) {
  DataSet result;
  result.data = safelyCreateEmptyDynamicArray(sizeof(int));
  result.size = 0;
  
  long long int *hashes = (long long int *)safelyCreateDynamicArray(
    height,
    sizeof(long long int)
  );

  for (int i = 0; i < height; i++) {
    hashes[i] = generateHashForRow(matrix[i], width);
  }

  for (int i = 0; i < height; i++) {
    int isDuplicate = 0;
    for (int j = 0; j < i; j++) {
      if (hashes[i] == hashes[j]) {
        isDuplicate = 1;
        break;
      }
    }

    if (isDuplicate) {
      result.size++;
      result.data = safelyResizeDynamicArray(result.data, result.size, sizeof(int));
      result.data[result.size - 1] = i;
    }
  }
  free(hashes);
  return result;
}


void viewMatrixHighlighted(
  int height,
  int width, 
  int **matrix,
  const char* name, // specify action to do (like "")
  int *rowsToDelete,
  int rowsToDeleteSize
) {
  int cnt = 0;
  printf("This is what will change in matrix after you %s:\n", name);
  printf("+----------------------------+\n");
  for (int h = 0; h < height; h++){
    if (numberInArray(rowsToDelete, rowsToDeleteSize, h)) {
      printf(REDCOLOR);
      cnt++;
    }
    printf("| ");

    for (int w = 0; w < width; w++) {
      printf("%2d ", matrix[h][w]);
    }

    printf("|\n");
    printf(NORMCOLOR);
  }
  printf("+----------------------------+\n");
  if (cnt == 0) {
    printf("===No rows will be affected===\n");
  }
}


void fourthVarProgTwo() {
  while (1) {

    int height;
    int width;
  
    printf("Enter matrix height >>> ");
    scanf("%d", &height);

    printf("Enter matrix width >>> ");
    scanf("%d", &width);
    clearScreen();

    int choice = yesOrNoPrompt(
      "Do you wanna fill the matrix manually?"
    );
    int **matrix;
    clearScreen();

    if (!choice) {
      printf("Matrix will be generated then\n");
      matrix = spawnMatrix(height, width, 1);
    } else {
      printf("Matrix will be filled manually then\n");
      matrix = spawnMatrix(height, width, 0);
    }

    viewMatrix(height, width, matrix, "Initial");
    printf("++++++++++++++++++++++++++++++++\n");
  
    DataSet markedRows = markRowsToDelete(matrix, height, width);
    viewMatrixHighlighted(
      height,
      width,
      matrix,
      "truncate matrix's non unique rows",
      markedRows.data,
      markedRows.size
    );
    matrix = cutMatrixRows(
      &height,
      width,
      matrix,
      markedRows.data,
      markedRows.size
    );

    viewMatrix(height, width, matrix, "New");
    free(markedRows.data);
    freeMatrix(matrix, height);
    choice = yesOrNoPrompt("Do you want to create a new array?");
    if (!choice) {
      break;
    }
    clearScreen();
  }
}

// int main() {
//  fourthVarProgTwo();
//  return 0;
// }
