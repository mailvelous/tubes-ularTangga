#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// #include <string.h>
#include "types.h"
// #include <stdlib.h>

void getLadderSnakeCount(int *ladderCount, int *snakeCount, int difficulty);
void searchPlayer(Player playerArray[], int playerCount, int blockNum,
                  int playerHere[], int *playerHereCount);
int compareAscending(const void *a, const void *b);
int compareDescending(const void *a, const void *b);
void printPlayerIcons(int playerNum, char colors[][7], int colorCount);
void initiateBoard(int snakeCount, int ladderCount, Snake S[], Ladder L[]);
void initiateLadders(int numLadders, int grid, int occupied[],
                     int *occupiedCount, Ladder arr[]);
void initiateSnakes(int numSnakes, int grid, int occupied[], int *occupiedCount,
                    Snake arr[]);

int searchNumber(int arr[], int size, int num);
int searchNumber2D(int arr[][2], int col, int row, int num);

void printBoardVSPlayer(Snake S[], Ladder L[], Player playerArray[],
                        int snakeCount, int ladderCount, int playerCount,
                        int grid);

void printBoardVSComputer(Snake S[], Ladder L[], Player playerArray[],
                          int snakeCount, int ladderCount, int playerCount,
                          int grid);
////////////////////////////////////////////////////////////////////////////////////////////////////////////

void printBoardVSPlayer(Snake S[], Ladder L[], Player playerArray[],
                        int snakeCount, int ladderCount, int playerCount,
                        int grid) {
  int gridNum = grid * grid;
  for (int i = 0; i < grid; i++) {
    for (int j = 0; j < grid; j++) {
      printf("---------");
    }
    printf("\n");
    for (int j = 0; j < grid; j++) {
      int sum;
      if (i % 2 == 0) {
        sum = gridNum - j;
      } else {
        sum = gridNum - grid + 1 + j;
      }

      int ladderNum = searchNumber2D(L, 2, ladderCount, sum);
      int snakeNum = searchNumber2D(S, 2, snakeCount, sum);
      if (ladderNum != -1) {
        printf("L%d      |", ladderNum + 1);
      } else if (snakeNum != -1) {
        printf("S%d      |", snakeNum + 1);
      } else {
        printf("        |");
      }
    }
    printf("\n");
    for (int j = 0; j < grid; j++) {
      int sum;
      if (i % 2 == 0) {
        sum = gridNum - j;
      } else {
        sum = gridNum - grid + 1 + j;
      }
      char colors[4][7] = {"\033[31m", "\033[34m", "\033[32m", "\033[33m"};
      int playerHere[playerCount];
      int playerHereCount = 0;
      searchPlayer(playerArray, playerCount, sum, playerHere, &playerHereCount);
      if (playerHereCount == 4) {
        printf("  ");

        for (int k = 0; k < playerHereCount; k++) {
          printPlayerIcons(playerHere[k], colors, 4);
        }
        printf("  |");
      } else if (playerHereCount == 3) {
        printf("  ");

        for (int k = 0; k < playerHereCount; k++) {
          printPlayerIcons(playerHere[k], colors, 4);
        }
        printf("   |");
      } else if (playerHereCount == 2) {
        printf("   ");
        for (int k = 0; k < playerHereCount; k++) {
          printPlayerIcons(playerHere[k], colors, 4);
        }
        printf("   |");
      } else if (playerHereCount == 1) {
        printf("   ");
        for (int k = 0; k < playerHereCount; k++) {
          printPlayerIcons(playerHere[k], colors, 4);
        }
        printf("    |");
      } else {
        printf("        |");
      }
    }
    printf("\n");
    for (int j = 0; j < grid; j++) {
      int sum;
      if (i % 2 == 0) {
        sum = gridNum - j;
      } else {
        sum = gridNum - grid + 1 + j;
      }

      if (sum > 99) {
        printf("%d     |", sum);
      } else if (sum > 9) {
        printf("%d      |", sum);
      } else {
        printf("%d       |", sum);
      }
    }

    printf("\n");
    gridNum -= grid;
  }
  for (int j = 0; j < grid; j++) {
    printf("---------");
  }
  printf("\n");
}

void printBlock0(Player playerArray[], int playerCount) {
  char colors[4][7] = {"\033[31m", "\033[34m", "\033[32m", "\033[33m"};
  int playerHere[playerCount];
  int playerHereCount = 0;
  searchPlayer(playerArray, playerCount, 0, playerHere, &playerHereCount);
  if (playerHereCount > 0) {
    printf("Block 0 (Luar papan)\n");
    printf("---------\n");
    printf("        |\n");

    if (playerHereCount == 4) {
      printf("  ");

      for (int k = 0; k < playerHereCount; k++) {
        printPlayerIcons(playerHere[k], colors, 4);
      }
      printf("  |");
    } else if (playerHereCount == 3) {
      printf("  ");

      for (int k = 0; k < playerHereCount; k++) {
        printPlayerIcons(playerHere[k], colors, 4);
      }
      printf("   |");
    } else if (playerHereCount == 2) {
      printf("   ");
      for (int k = 0; k < playerHereCount; k++) {
        printPlayerIcons(playerHere[k], colors, 4);
      }
      printf("   |");
    } else if (playerHereCount == 1) {
      printf("   ");
      for (int k = 0; k < playerHereCount; k++) {
        printPlayerIcons(playerHere[k], colors, 4);
      }
      printf("    |");
    }
    printf("\n        |\n");
    printf("---------\n");
  }
}

void printBoardVSComputer(Snake S[], Ladder L[], Player playerArray[],
                          int snakeCount, int ladderCount, int playerCount,
                          int grid) {
  int gridNum = grid * grid;
  for (int i = 0; i < grid; i++) {
    for (int j = 0; j < grid; j++) {
      printf("---------");
    }
    printf("\n");
    for (int j = 0; j < grid; j++) {
      int sum;
      if (i % 2 == 0) {
        sum = gridNum - j;
      } else {
        sum = gridNum - grid + 1 + j;
      }

      int ladderNum = searchNumber2D(L, 2, ladderCount, sum);
      int snakeNum = searchNumber2D(S, 2, snakeCount, sum);
      if (ladderNum != -1) {
        printf("↑%d      |", ladderNum + 1);
      } else if (snakeNum != -1) {
        printf("↓%d      |", snakeNum + 1);
      } else {
        printf("        |");
      }
    }
    printf("\n");
    for (int j = 0; j < grid; j++) {
      int sum;
      if (i % 2 == 0) {
        sum = gridNum - j;
      } else {
        sum = gridNum - grid + 1 + j;
      }
      char colors[4][7] = {"\033[31m", "\033[34m", "\033[32m", "\033[33m"};
      int playerHere[playerCount];
      int playerHereCount = 0;
      searchPlayer(playerArray, playerCount, sum, playerHere, &playerHereCount);
      if (playerHereCount == 4) {
        printf("  ");

        for (int k = 0; k < playerHereCount; k++) {
          printPlayerIcons(playerHere[k], colors, 4);
        }
        printf("  |");
      } else if (playerHereCount == 3) {
        printf("  ");

        for (int k = 0; k < playerHereCount; k++) {
          printPlayerIcons(playerHere[k], colors, 4);
        }
        printf("   |");
      } else if (playerHereCount == 2) {
        printf("   ");
        for (int k = 0; k < playerHereCount; k++) {
          printPlayerIcons(playerHere[k], colors, 4);
        }
        printf("   |");
      } else if (playerHereCount == 1) {
        printf("   ");
        for (int k = 0; k < playerHereCount; k++) {
          printPlayerIcons(playerHere[k], colors, 4);
        }
        printf("    |");
      } else {
        printf("        |");
      }
    }
    printf("\n");
    for (int j = 0; j < grid; j++) {
      int sum;
      if (i % 2 == 0) {
        sum = gridNum - j;
      } else {
        sum = gridNum - grid + 1 + j;
      }

      if (sum > 99) {
        printf("%d     |", sum);
      } else if (sum > 9) {
        printf("%d      |", sum);
      } else {
        printf("%d       |", sum);
      }
    }

    printf("\n");
    gridNum -= grid;
  }
  for (int j = 0; j < grid; j++) {
    printf("---------");
  }
  printf("\n");
}

void initiateBoard(int snakeCount, int ladderCount, Snake S[], Ladder L[]) {
  srand(time(0));
  int n = 10;
  int occupied[(ladderCount + snakeCount) * 2];
  int occupiedCount = 0;
  initiateLadders(ladderCount, n, occupied, &occupiedCount, L);
  initiateSnakes(snakeCount, n, occupied, &occupiedCount, S);
}

void initiateLadders(int numLadders, int grid, int occupied[],
                     int *occupiedCount, Ladder arr[]) {
  for (int i = 0; i < numLadders; i++) {
    int j = 0;
    while (j < 2) {
      int max = grid * grid - 1;
      int min = 2;
      int block = rand() % (max - min + 1) + min;
      if (searchNumber(occupied, *occupiedCount, block) == -1) {
        arr[i][j] = block;
        occupied[*occupiedCount] = block;
        (*occupiedCount)++;
        j++;
      }
    }
    qsort(arr[i], 2, sizeof(arr[i][0]), compareAscending);
  }
}

int searchNumber(int arr[], int size, int num) {
  for (int i = 0; i < size; i++) {
    if (num == arr[i]) {
      return i;
    }
  }
  return -1;
}

int searchNumber2D(int arr[][2], int col, int row, int num) {
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (num == arr[i][j]) {
        return i;
      }
    }
  }
  return -1;
}

void initiateSnakes(int numSnakes, int grid, int occupied[], int *occupiedCount,
                    Snake arr[]) {
  for (int i = 0; i < numSnakes; i++) {
    int j = 0;
    while (j < 2) {
      int max = grid * grid - 1;
      int min = 2;
      int block = rand() % (max - min + 1) + min;
      if (searchNumber(occupied, *occupiedCount, block) == -1) {
        arr[i][j] = block;
        occupied[*occupiedCount] = block;
        (*occupiedCount)++;
        j++;
      }
    }
    qsort(arr[i], 2, sizeof(arr[i][0]), compareDescending);
  }
}

int compareAscending(const void *a, const void *b) {
  return (*(int *)a - *(int *)b);
}

int compareDescending(const void *a, const void *b) {
  return (*(int *)b - *(int *)a);
}

void initiatePlayers(Player playerArray[], int playerCount) {
  for (int i = 0; i < playerCount; i++) {
    printf("Nama player ke-%d: ", i + 1);
    getchar();
    scanf("%49[^\n]", playerArray[i].name);
    playerArray[i].position = 0;
  }
}
void resetColor() { printf("\033[0m"); }

void printPlayerIcons(int playerNum, char colors[][7], int colorCount) {
  for (int i = 0; i < colorCount; i++) {
    if (i == playerNum) {
      printf("%sP", colors[i]);
      resetColor();
    }
  }
}

void printPlayers(Player playerArray[], int playerCount, char colors[][7],
                  int colorCount) {
  for (int i = 0; i < playerCount; i++) {
    printPlayerIcons(i, colors, colorCount);
    printf(": %s\n", playerArray[i].name);
  }
  printf("\n");
}

void getLadderSnakeCount(int *ladderCount, int *snakeCount, int difficulty) {
  if (difficulty == 1) {
    *ladderCount = 7;
    *snakeCount = 3;
  } else if (difficulty == 2) {
    *ladderCount = 5;
    *snakeCount = 5;
  } else if (difficulty == 3) {
    *ladderCount = 3;
    *snakeCount = 7;
  }
}

void searchPlayer(Player playerArray[], int playerCount, int blockNum,
                  int playerHere[], int *playerHereCount) {
  *playerHereCount = 0;
  for (int i = 0; i < playerCount; i++) {
    if (blockNum == playerArray[i].position) {
      playerHere[*playerHereCount] = i;
      *playerHereCount += 1;
    }
  }
}