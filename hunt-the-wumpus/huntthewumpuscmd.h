
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
       if (used[x][y] == PIT) return -1;
       used[cur_posx][cur_posy] = UNDEFINED;
       cur_posx = x; cur_posy = y;
       used[cur_posx][cur_posy] = ME;
       return 1;
    }
  }
  return 0;
}

void sensorResult() {
  short i, pits = 0, brezze = 0, stench = 0;
  for (i = 0; i < COORDS; ++i) {
    int x = cur_posx + dx[i];
    int y = cur_posy + dy[i];
    if (x < 0 || x >= MAP_SIZE || y < 0 || y >= MAP_SIZE) continue;
    if (used[x][y] == PIT) {
      pits += 1;
    } else if (used[x][y] == BREEZE) {
      brezze += 1;
    } else if (used[x][y] == STENCH) {
      stench += 1;
    }
  }

  if (pits | brezze | stench) {
    printf("Seu sensor mostra que ao seu sedor há: ");
    if (pits > 0) printf("penhasco ");
    if (brezze > 0) printf("brisa ");
    if (stench > 0) printf("mau cheiro");
  } else {
    printf("Seu sensor não encontrou nada.");
  }

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
        generate_map();
      }
    }
    printf("\n\n");
  }
}
