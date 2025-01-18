#include "common.h"
#include <stdio.h>
#include "intprompts.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define MAX_STRING_LENGTH 256
#define SEPARATOR "++++++++++++++++++++++++++++++++++++++++\n"

#define CURRENT_PROGRAMS 13 // change if you wanna add more


typedef struct {
  void (*func)();
  int choice;
} dispatchHints;



char **menuGen(int menuLen) {

  char **menu = (char **)malloc(menuLen * sizeof(char *));

  for (int i = 0; i < menuLen; i++) {
    menu[i] = (char *)malloc(MAX_STRING_LENGTH * sizeof(char)); 
    if (menu[i] == NULL) {
      fprintf(stderr, "Memory allocation failed for menu item %d\n", i);
      exit(1);
    }
  }

  return menu;
}


void menuRaiseKill(char** menu, int menulen) {
  printf("Choose your option\n");
  printf(SEPARATOR);

  for (int i = 0; i < menulen; i++) {
    printf(menu[i]);
    printf("\n");
  }

  printf(SEPARATOR);
  printf("Your input >>> ");
  
  for (int i = 0; i < menulen; i++) {
      free(menu[i]);
  }
  free(menu);
}


void mainMenu() {
  int menuLen = 3;
  char **menu = menuGen(menuLen);

  strcpy(menu[0], "1. Start Programs");
  strcpy(menu[1], "2. About");
  strcpy(menu[2], "3. Quit");
  
  menuRaiseKill(menu, menuLen);
}


void programsMenu() {
  int menulen = CURRENT_PROGRAMS + 2;
  char **menu = menuGen(menulen);
  
  strcpy(menu[0], "1. Variant 12 | Part 1 | Task 1");
  strcpy(menu[1], "2. Variant 12 | Part 1 | Task 2");
  strcpy(menu[2], "3. Variant 12 | Part 1 | Task 3");
  strcpy(menu[3], "4. Variant 12 | Part 2 | Task 1");
  strcpy(menu[4], "5. Variant 12 | Part 2 | Task 2");
  strcpy(menu[5], "6. Variant 12 | Part 2 | Task 3");
  strcpy(menu[6], "7. Variant 12 | Part 3 | Task 1");
  strcpy(menu[7], "8. Variant 12 | Part 3 | Task 2");
  strcpy(menu[8], "9. Variant 12 | Part 4 | Task 1");
  strcpy(menu[9], "10. Variant 12 | Part 4 | Task 2");
  strcpy(menu[10], "11. Variant 12 | Last Tasks | Task 1");
  strcpy(menu[11], "12. Variant 12 | Last Tasks | Task 2");
  strcpy(menu[12], "13. Variant 12 | Last Tasks | Task 3");
  strcpy(menu[13], "14. Back");
  strcpy(menu[14], "15. Quit app");


  menuRaiseKill(menu, menulen);
}


void programsAfterPartyMenu() {
  int menulen = 3;
  char **menu = menuGen(menulen);
  
  strcpy(menu[0], "1. Launch another program");
  strcpy(menu[1], "2. To main Menu");
  strcpy(menu[2], "3. Quit");

  menuRaiseKill(menu, menulen);
}


void aboutMenu() {
  int menulen = 1;
  char **menu = menuGen(menulen);
  printf("This is a program for running programs by Dmitriy Goryachev.\n");
  printf("Tasks description you can find in your materials\n");

  strcpy(menu[0], "1. Back");
  menuRaiseKill(menu, menulen);
}


dispatchHints render(void (*menu)()) {
  dispatchHints header;
  header.func = menu;
  header.choice = 0;
  int result;

  while (1) {
    clearScreen();
    header.func();
    result = scanf("%d", &header.choice);
    
    while (getchar() != '\n');

    if (result != 1) {
      continue;
    }
    break;
  }
  return header;
}


void dispatcher(dispatchHints *current) {
  clearScreen();
  if (current->func == mainMenu) {
    switch (current->choice) {
      case 1:
        current->func = programsMenu;
        break;
      case 2:
        current->func = aboutMenu;
        break;
      case 3:
        printf("Exiting...\n");
        current->func = NULL;
        break;
      default:
        printf("This option does not exist\n");
        break;
    }
  } else if (current->func == programsMenu) {
    switch (current->choice) {
      case 1:
        firstVarProgOne();
        current->func = programsAfterPartyMenu;
        break;
      case 2:
        firstVarProgTwo();
        current->func = programsAfterPartyMenu;
        break;
      case 3:
        firstVarProgThree();
        current->func = programsAfterPartyMenu;
        break;
      case 4:
        secondVarProgOne();
        current->func = programsAfterPartyMenu;
        break;
      case 5:
        secondVarProgTwo();
        current->func = programsAfterPartyMenu;
        break;
      case 6:
        secondVarProgThree();
        current->func = programsAfterPartyMenu;
        break;
      case 7:
        thirdVarProgOne();
        current->func = programsAfterPartyMenu;
        break;
      case 8:
        thirdVarProgTwo();
        current->func = programsAfterPartyMenu;
        break;
      case 9:
        fourthVarProgOne();
        current->func = programsAfterPartyMenu;
        break;
      case 10:
        fourthVarProgTwo();
        current->func = programsAfterPartyMenu;
        break;
      case 11:
        taskRecentOne();
        current->func = programsAfterPartyMenu;
        break;
      case 12:
        taskRecentTwo();
        current->func = programsAfterPartyMenu;
        break;
      case 13:
        taskRecentThree();
        current->func = programsAfterPartyMenu;
        break;
      case 14:
        current->func = mainMenu;
        break;
      case 15:
        current->func = NULL;
        break;
      default:
        printf("This option does not exist\n");
        break;
    }
    int escaped = 0;
    while (!escaped) {
      escaped = qEscapade("Press q or Q to quit this subprogram!\nYour input >>> ");
    }
  } else if (current->func == programsAfterPartyMenu) {
    switch (current->choice) {
      case 1:
        current->func = programsMenu;
        break;
      case 2:
        current->func = mainMenu;
        break;
      case 3:
        current->func = NULL;
        break;
      default:
        printf("This option does not exist\n");
        break;
    }
  } else if (current->func == aboutMenu) {
    switch (current->choice) {
      case 1:
        current->func = mainMenu;
        break;
      default:
        printf("This option does not exist\n");
        break;
    }
  }
}


int main() {
  dispatchHints current;
  current.func = mainMenu;
  current.choice = 0;
  
  while(current.func != NULL) {
    current = render(current.func);
    dispatcher(&current);
  }

  printf("Program terminated.\n");
  return 0;
}

