#include <stdio.h>
#include <math.h>
#include <stdlib.h>


void *safelyCreateDynamicArray(int size, size_t dataTypeSize) {
  void *arr = (void *)malloc(size * dataTypeSize);
  if (arr == NULL) {
    printf("Memory allocation failed!\n");
    exit(1);
  }
  return arr;
}


void *safelyResizeDynamicArray(void *oldArr, int newSize, size_t dataTypeSize) {
  void *arr = realloc(oldArr, newSize * dataTypeSize);
  if (arr == NULL) {
    printf("Memory allocation failed during resizing!\n");
    free(oldArr);
    exit(1);
  }
  return arr;
}


void *safelyCreateEmptyDynamicArray(size_t dataTypeSize) {
  void *arr = (void *)malloc(dataTypeSize);
  if (arr == NULL) {
    printf("Memory allocation failed!\n");
    exit(1);
  }
  return arr;
}


void viewArray(const void *arr, int size, const char *name, size_t dataTypeSize) {
  printf("Array %s:\n", name);

  if (dataTypeSize == sizeof(int)) {
    const int *intArr = (const int *)arr; // Cast to int array
    for (int k = 0; k < size; k++) {
      printf("%10d", intArr[k]); // Print as integers
    }
  } else if (dataTypeSize == sizeof(float)) {
    const float *floatArr = (const float *)arr; // Cast to float array
    for (int k = 0; k < size; k++) {
      printf("%10.2f", floatArr[k]); // Print as floats
    }
  }
  printf("\n");
}


int charInArray(const char arr[], int size, char item) {
  for (int i = 0; i < size; i++) {
    if (arr[i] == item) {
      return 1;
    }
  }
  return 0;
}


int *removeItemFromSingleArray(int *arr, int size, int index) {
  for (int i = 0; i < size; i++) {
    if (index == i) {
      for (int q = i; q < size - 1; q++) {
        arr[q] = arr[q + 1];
      }
    }
  }

  arr = safelyResizeDynamicArray(arr, size - 1, sizeof(int));
  return arr;
}


int numberInArray(int *arr, int size, int number) {
  for (int i = 0; i < size; i++) {
    if (arr[i] == number) {
      return 1;
    }
  }
  return 0;
}
