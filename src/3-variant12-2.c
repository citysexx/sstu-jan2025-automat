#include <stdio.h>
#include <stdlib.h>
#include "arrayutils.h"


int *formulateANewUniqueArray(int arr[], int size) {
  int newSize = 0;
  int *newArr = safelyCreateEmptyDynamicArray(sizeof(int));
  
  if (size == 1) {
    return arr; // single elem is always unique
  }

  // Array to track visited elements
  int *visited = (int *)calloc(size, sizeof(int));
  if (visited == NULL) {
    printf("Memory allocation failed!\n");
    exit(1);
  }

  for (int i = 0; i < size; i++) {
    if (visited[i]) {
      continue;
    }
    int isUnique = 1;
    
    for (int j = i + 1; j < size; j++) {
      if (arr[i] == arr[j]) {
        visited[j] = 1; 
        isUnique = 0;
      }
    }

    if (isUnique) {
      newSize++;
      newArr = safelyResizeDynamicArray(newArr, newSize, sizeof(int));
      newArr[newSize - 1] = arr[i];
    }
  }
  viewArray(newArr, newSize, "Unique", sizeof(int));
  free(visited);
  return newArr;
}


void thirdVarProgTwo() {
  int size;
  printf("Enter number of elements in array >>> ");
  scanf("%d", &size);

  int *arr = safelyCreateDynamicArray(size, sizeof(int));

  for (int i = 0; i < size; i++) {
    printf("Enter number %d >>> ", i + 1);
    scanf("%d", &arr[i]);
  }
  viewArray(arr, size, "Created", sizeof(int));
  
  int *newArray = formulateANewUniqueArray(arr, size);

  free(newArray);
  free(arr);
}


// int main() {
//  thirdVarProgTwo();
// }
