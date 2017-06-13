#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "huntthewumpus.h"
#include "huntthewumpuscmd.h"

int cmd() {

  printf("Você está na entrada da caverna %d\n", Map[cur_posx][cur_posy]);

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
  generate_map();
  while (is_playing)
  {
    int action = cmd();
    if (action == QUIT) is_playing = 0;
  }

  return 0;
}
