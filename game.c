// #include <stdio.h>
#include "board.c"
#include <stdlib.h>
void move(int n, Player *player, int grid);
void setPosition(int n, Player *player);
int rollDice();
void checkLadderSnake(Player *player, Ladder L[], Snake S[], int ladderCount, int snakeCount);

int rollDice() {
  int min = 1;
  int max = 6;
  return (rand() % (max - min + 1) + min);
}

void move(int n, Player *player, int grid) {
  int max = grid * grid;
  (*player).position += n;
  if ((*player).position > max) {
    (*player).position = max - (*player).position + max;
  }
  printf("Player %s have moved %d steps\n", (*player).name, n);
}

void setPosition(int n, Player *player) { (*player).position = n; }

void checkLadderSnake(Player *player, Ladder L[], Snake S[], int ladderCount, int snakeCount) {
  for (int i = 0; i < ladderCount; i++) {
    if ((*player).position == L[i][0]) {
      setPosition(L[i][1], player);
    }
  }
}