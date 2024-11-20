// #include <stdio.h>
#include "board.c"
#include <stdlib.h>
void move(int n, Player *player, int grid);
void setPosition(int n, Player *player);
int rollDice();
void timer();


void checkLadderSnake(Player *player, Ladder L[], Snake S[], int ladderCount,
                      int snakeCount);

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

void setPosition(int n, Player *player) {
  (*player).position = n; 
  }

void timer(){
    int seconds = 3;

  printf("Seconds: ");

  while (seconds > 0)
  {

    int h = seconds / 3600;
    int m = (seconds % 3600) / 60;
    int s = seconds % 60;
    printf("\r%02d:%02d:%02d", h, m, s);
    fflush(stdout);
    clock_t stop = clock() + CLOCKS_PER_SEC;
    while (clock() < stop) { }
    seconds--;
  } 
  printf("\rTime's up!\n");
}

void checkLadderSnake(Player *player, Ladder L[], Snake S[], int ladderCount,
                      int snakeCount) {
  for (int i = 0; i < ladderCount; i++) {
    if ((*player).position == L[i][0]) {
      setPosition(L[i][1], player);
      printf("Player %s discovered a Ladder! (YAYY :D) %s now on block %d",
             (*player).name, (*player).name, L[i][1]);
    }
  }
  for (int i = 0; i < snakeCount; i++) {
    if ((*player).position == S[i][0]) {
      setPosition(S[i][1], player);
      printf("Player %s discovered a Snake! (AWW T-T) %s now on block %d",
             (*player).name, (*player).name, S[i][1]);
    }
  }
}