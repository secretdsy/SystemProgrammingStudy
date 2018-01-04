#include <stdio.h>
#include "swap1.h"

int main() {
  int x = 10;
  int y = 20;
  printf("%d, %d\n", x, y);
  swap(&x, &y);
  printf("%d, %d\n", x, y);

  return 0;
}
