
#define QUIT       3
#define MOVE       4

#define MAP_SIZE   5
#define MAX_PITS   5
#define MAX_BREEZE 5
#define MAX_STENCH 3
#define COORDS     4

// to map around the player's position
const int dx[COORDS] = {1,-1, 0, 0};
const int dy[COORDS] = {0, 0, 1,-1};

// flag: running game
short IS_PLAYING = 1;

// world map of wumpus
int Map[MAP_SIZE][MAP_SIZE];

// to check already used caves
short used[MAP_SIZE][MAP_SIZE];

// player's current position
int cur_posx = 0, cur_posy = 0;

enum world {ME, GOLD, PIT, STENCH, BREEZE, WUMPUS, UNDEFINED=-1};

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
  return rand() % MAP_SIZE;
}

// reset map
void reset_game() {
  int i, j, id = 1;
  for (i = 0; i < MAP_SIZE; ++i) {
    for (j = 0; j < MAP_SIZE; ++j) {
      used[i][j] = UNDEFINED;
      Map[i][j] = id++;
    }
  }
}

void addPits() {
  int i;
  for (i = 0; i < MAX_PITS; ++i) {
    int pit_x = get_rand_pos();
    int pit_y = get_rand_pos();
    while (used[pit_x][pit_y] != UNDEFINED) {
      pit_x = get_rand_pos();
      pit_y = get_rand_pos();
    }
    used[pit_x][pit_y] = PIT;
  }
}

void addBreezes() {
  int i;
  for (i = 0; i < MAX_BREEZE; ++i) {
    int breeze_x = get_rand_pos();
    int breeze_y = get_rand_pos();
    while (used[breeze_x][breeze_y] != UNDEFINED) {
      breeze_x = get_rand_pos();
      breeze_y = get_rand_pos();
    }
    used[breeze_x][breeze_y] = BREEZE;
  }
}

void addStenchs() {
  int i;
  for (i = 0; i < MAX_STENCH; ++i) {
    int stench_x = get_rand_pos();
    int stench_y = get_rand_pos();
    while (used[stench_x][stench_y] != UNDEFINED) {
      stench_x = get_rand_pos();
      stench_y = get_rand_pos();
    }
    used[stench_x][stench_y] = STENCH;
  }
}

// generate random positions
void generate_map() {
  reset_game();
  cur_posx = get_rand_pos();
  cur_posy = get_rand_pos();
  used[cur_posx][cur_posy] = ME;

  addPits();
  addBreezes();
  addStenchs();

}

//  temp. method, Debug only
void debug_view_map() {
  int i, j;
  for (i = 0; i < MAP_SIZE; ++i) {
    for (j = 0; j < MAP_SIZE; ++j) {
      if (j) printf(" ");
      if (used[i][j] == ME) {
        printf("M");
      } else if (used[i][j] == PIT) {
        printf("P");
      } else if (used[i][j] == BREEZE) {
        printf("B");
      } else if (used[i][j] == STENCH) {
        printf("S");
      } else {
        printf("%d", Map[i][j]);
      }
    } printf("\n");
  }
  printf("-----------\n");
}
