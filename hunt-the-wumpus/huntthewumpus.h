
#define MAP_SIZE 100
#define SAIR     0

// to map around the player's position
const int dx[4] = {1,-1, 0, 0};
const int dy[4] = {0, 0, 1,-1};

// to check already used caves
short used[MAP_SIZE][MAP_SIZE];

enum world {ME, GOLD, PIT, STENCH, BREEZE, WUMPUS};

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

// return a random number between [1, ..., MAP_SIZE]
int get_rand_pos() {
  return 1 + (rand() % MAP_SIZE);
}

// generate random positions
void generate_map() {
  // to do
}
