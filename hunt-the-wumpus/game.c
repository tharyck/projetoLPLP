#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 100
#define SAIR     0

// to map around the player's position
const int dx[4] = {1,-1, 0, 0};
const int dy[4] = {0, 0, 1,-1};

// to check already used caves
short used[MAP_SIZE][MAP_SIZE];

enum world {ME, GOLD, PIT, STENCH, BREEZE, WUMPUS};

short is_playing = 1;
int Map[MAP_SIZE][MAP_SIZE];

void usage() {
  FILE *instrucions;
  instrucions = fopen("instructions.txt", "r");
  if (instrucions) {
    int c;
    while ((c = getc(instrucions)) != EOF) putchar(c);
    fclose(instrucions);
  } else {
    FILE *games_logs = fopen("wumpus.log", "ab+");
    char no_instrunctions[] = " The instruction file was deleted by the user\n";
    char buff[20];
    time_t now = time(0);
    struct tm *mt;
    mt = localtime(&now);
    strftime(buff, sizeof(buff), "%Y-%m-%d %H:%M:%S", mt);
    fwrite(buff, 1, sizeof(buff), games_logs);
    fwrite(no_instrunctions, 1, sizeof(no_instrunctions), games_logs);
    fclose(games_logs);
  }
}

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

// return a random number between [1, ..., MAP_SIZE]
int get_rand_pos() {
  return 1 + (rand() % MAP_SIZE);
}

// generate random positions
void generate_map() {
  // to do
}

int main(int argc, char *argv[])
{
  usage();
  while (is_playing)
  {
    int action = cmd();
    if (action == SAIR) is_playing = 0;
  }

  return 0;
}
