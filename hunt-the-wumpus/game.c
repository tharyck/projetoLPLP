#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "huntthewumpus.h"
#include "huntthewumpuscmd.h"

int main(int argc, char *argv[]) {

  usage();
  generate_map();
  //debug_view_map();
  run();

  return 0;
}
