#include <stdio.h>


int ifNumPositive(int number) {
    return (number >= 0);
}


int isItemUnique(int *arr, int size, int number) {
  int cnt = 0;

  for (int i = 0; i < size; i++) {
    if (arr[i] == number) {
      cnt++;
    }
  }

  int result = (cnt == 1) ? 1 : 0;
  return result;
}


long long int generateHashForRow(int *arr, int size) {
  long long int checksum = 0;
  for (int i = 0; i < size; i++) {
    checksum = checksum * 67 + arr[i];
  }
  return checksum;
}
