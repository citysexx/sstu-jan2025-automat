#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void viewMatrix(int height, int width, int **matrix, const char* name) {
  printf("%s matrix:\n", name);
  printf("+----------------------------+\n");
  for (int h = 0; h < height; h++){
    printf("| ");
    for (int w = 0; w < width; w++) {
      printf("%2d ", matrix[h][w]);
    }
    printf("|\n");
  }
  printf("+----------------------------+\n");
}


int **spawnMatrix(int height, int width, int ifPopulate) {
  srand(time(NULL));
  int **matrix = (int **)malloc(height * sizeof(int *));
  
  if (matrix == NULL) {
    printf("Memory allocation failed!\n");
    exit(1);
  }

  for (int i = 0; i < height; i++) {
    matrix[i] = (int *)malloc(width * sizeof(int *));
    if (matrix[i] == NULL) {
      printf("Memory allocation failed for row %d\n", i + 1);
      exit(1);
    }
  }
  
  if (ifPopulate) {
    printf("Randomizing numbers and populating matrix...\n");
    for (int h = 0; h < height; h++) {
      for (int w = 0; w < width; w++) {
        matrix[h][w] = rand() % (99 - 1 + 1) + 1;
      }
    }
  }

  return matrix;
}


void freeMatrix(int **matrix, int height) {
  for (int i = 0; i < height; i++) {
    free(matrix[i]);
  }
  free(matrix);
}


void sortDescending(int *arr, int len) {
  for (int i = 0; i < len - 1; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] < arr[j]) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
}


int **cutMatrixRows(
  int *rows, 
  int cols, 
  int **matrix, 
  const int *rowsAddresses,
  const int rowsArrLen
) {
  int *rowsToDelete = malloc(rowsArrLen * sizeof(int));
  if (rowsToDelete == NULL) {
    printf("Memory allocation failed!\n");
    exit(1);
  }
  for (int i = 0; i < rowsArrLen; i++) {
    rowsToDelete[i] = rowsAddresses[i];
  }

  sortDescending(rowsToDelete, rowsArrLen);

  int deleted = 0;
  for (int i = 0; i < rowsArrLen; i++) {
    int rowToDelete = rowsToDelete[i];

    if (rowToDelete >= 0 && rowToDelete < *rows) {
      free(matrix[rowToDelete]);

      for (int j = rowToDelete; j < *rows - 1; j++) {
        matrix[j] = matrix[j + 1];
      }
      matrix[*rows - 1] = NULL; // Set the last row to NULL
      (*rows)--;
      deleted++;
    }
  }
  if (*rows > 0) {
    matrix = realloc(matrix, (*rows) * sizeof(int *));
    if (matrix == NULL) {
      printf("Memory reallocation failed!\n");
      exit(1);
    }
  } else {
    
    for (int i = 0; i < *rows; i++) {
      free(matrix[i]);
    }
    free(matrix);
    matrix = NULL;
  }

  if (deleted == 0) {
    printf("No rows were deleted.\n");
  }

  free(rowsToDelete);
  return matrix;
}

