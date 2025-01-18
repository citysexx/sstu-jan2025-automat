#ifndef MATRIXUTILS_H
#define MATRIXUTILS_H

void viewMatrix(int height, int width, int **matrix, const char* name);
int **spawnMatrix(int height, int width, int ifPopulate);
void freeMatrix(int **matrix, int height);
int **cutMatrixRows(
  int *rows, 
  int cols, 
  int **matrix, 
  const int *rowsAddresses,
  const int rowsArrLen
);
void sortDescending(int *arr, int len);

#endif // MATRIXUTILS_H
