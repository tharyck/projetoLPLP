#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "huntthewumpus.h"

short is_playing = 1;
int Map[MAP_SIZE][MAP_SIZE];

int cmd() {

  printf("Você está na entrada da caverna 1\n");
  printf("O que deseja fazer?  ");

  char action[10];
  scanf("%s", action);
  printf("\n");
  if (action[0] == 'S' || action[0] == 's') {
    return strlen(action) != 1;
  }
  return 1;
}

int main(int argc, char *argv[]) {

  usage();
  while (is_playing)
  {
    int action = cmd();
    if (action == SAIR) is_playing = 0;
  }

  return 0;
}
