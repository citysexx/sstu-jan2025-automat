#ifndef ARRAYUTILS_H
#define ARRAYUTILS_H

void *safelyCreateDynamicArray(int size, size_t dataTypeSize);
void *safelyResizeDynamicArray(void *oldArr, int newSize, size_t dataTypeSize);
void *safelyCreateEmptyDynamicArray(size_t dataTypeSize);
void viewArray(const void *arr, int size, const char *name, size_t dataTypeSize);
int charInArray(const char arr[], int size, char item);
int *removeItemFromSingleArray(int *arr, int size, int index);
int numberInArray(int *arr, int size, int number);

#endif // ARRAYUTILS_H
