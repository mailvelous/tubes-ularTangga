// #include <stdio.h>
#include "board.c"
#include <stdlib.h>
void move(int n, Player *player, int grid);
int rollDice();
int checkLadderSnake(Player playerArray[], int playerNum, Ladder L[],
                     Snake S[]);

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
  printf("Player %s, you have moved %d steps\n", (*player).name, n);
}