#include <stdio.h>
#include <stdlib.h>
#include "arrayutils.h"


float *formulateANewArray(float arr[], int size, int lowBord, int highBord) {
  if (lowBord >= highBord) {
    printf("lower number should be lower than the higher one\n");
    exit(1);
  }
    
  int newSize = 0;
  float *newArr = safelyCreateEmptyDynamicArray(sizeof(float));
  
  for (int i = 0; i < size; i++) {
    if (arr[i] > 24 && arr[i] < 34) {
      newSize++;
      newArr = safelyResizeDynamicArray(newArr, newSize, sizeof(float));
      newArr[newSize - 1] = arr[i];
    } 
  }

  viewArray(newArr, newSize, "Filtered new", sizeof(float));
  return newArr;
}


void thirdVarProgOne() {
  int size;
  printf("Enter number of elements in array >>> ");
  scanf("%d", &size);

  float *arr = safelyCreateDynamicArray(size, sizeof(float));

  for (int i = 0; i < size; i++) {
    do{
      printf("Enter number %d >>> ", i + 1);
      scanf("%f", &arr[i]);
    } while (arr[i] > 50 || arr[i] < 0);
  }
  viewArray(arr, size, "Created", sizeof(float));
  
  float *newArray = formulateANewArray(arr, size, 24, 34);

  free(newArray);
  free(arr);
}


// int main() {
//  thirdVarProgOne();
//  return 0;
// }
