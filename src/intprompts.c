#include <stdio.h>
#include <stdlib.h>
#include "arrayutils.h"
#include <unistd.h>


int yesOrNoPrompt(const char* question) {
  char answer;
  const char variants[] = {
    'y',
    'Y',
    'n',
    'N'
  };

  do {
    printf("%s (y/n): ", question);
    while (getchar() != '\n');
    scanf(" %c", &answer);


  } while (!charInArray(variants, sizeof(variants) / sizeof(variants[0]), answer));

  if (answer == 'n' || answer == 'N') {
    return 0;
  } else {
    return 1;
  }
  
}


void clearScreen() {
    system("clear");
}


int qEscapade(const char* question) {
  char answer;
  const char variants[] = {
    'Q',
    'q'
  };

  do {
    printf("note: program you launched has finished. %s\n", question);
    while (getchar() != '\n');
    scanf(" %c", &answer);


  } while (!charInArray(variants, sizeof(variants) / sizeof(variants[0]), answer));

  if (answer == 'q' || answer == 'Q') {
    return 1;
  } else {
    return 0;
  }
  
}
