
void showCavesAround() {
  printf("Ao seu redor estão acessiveis as cavenas: ");
  int i;
  for (i = 0; i < COORDS; ++i) {
    int x = cur_posx + dx[i];
    int y = cur_posy + dy[i];
    if (x < 0 || x >= MAP_SIZE || y < 0 || y >= MAP_SIZE) continue;
    printf("%d ", Map[x][y]);
  }
  printf("\n");
}

int move(int cave) {
  int i;
  for (i = 0; i < COORDS; ++i) {
    int x = cur_posx + dx[i];
    int y = cur_posy + dy[i];
    if (x < 0 || x >= MAP_SIZE || y < 0 || y >= MAP_SIZE) continue;
    if (cave == Map[x][y]) {
       if (Map[x][y] == PIT) return -1;
       used[cur_posx][cur_posy] = UNDEFINED;
       cur_posx = x; cur_posy = y;
       used[cur_posx][cur_posy] = ME;
       return 1;
    }
  }
  return 0;
}

void sensorResult() {
  printf("Seu sensor mostra que proxíma a você há: ");
  int i, warnning = 0;
  for (i = 0; i < COORDS; ++i) {
    int x = cur_posx + dx[i];
    int y = cur_posy + dy[i];
    if (x < 0 || x >= MAP_SIZE || y < 0 || y >= MAP_SIZE) continue;
    if (Map[x][y] == PIT) {
      if (warnning) printf(", ");
      printf("penhasco");
      warnning |= 1;
    } else if (Map[x][y] == BREEZE) {
      if (warnning) printf(", ");
      printf("brisa");
      warnning |= 1;
    } else if (Map[x][y] == STENCH) {
      if (warnning) printf(", ");
      printf("mau cheiro");
      warnning |= 1;
    }
  }

  if (!warnning) printf("Cavernas apenas");
  printf("\n");
}

int cmd() {

  printf("Você está na caverna %d\n", Map[cur_posx][cur_posy]);
  showCavesAround();
  sensorResult();
  printf("O que deseja fazer?  ");

  char action[10];
  scanf("%s", action);
  printf("\n");
  int len = strlen(action);
  if (action[0] == 'S' || action[0] == 's') {
    if (len == 1) return QUIT;
  } else if (action[0] == 'M' || action[0] == 'm') {
    if (len == 1) return MOVE;
  }

  return 1;
}

void run() {
  while (IS_PLAYING) {
    int action = cmd();
    if (action == QUIT) IS_PLAYING = 0;
    else if (action == MOVE) {
      int op = Map[cur_posx][cur_posy];
      printf("\nIndique qual caverna: ");
      scanf("%d", &op);
      int ret = move(op);
      if (ret == -1) {
        printf("Você caiu no penhasco! :(\n\nFIM DE JOGO!!\n\n");
      }
    }
  }
}
