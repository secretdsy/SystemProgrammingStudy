#include <stdio.h>

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

int main() {
  int x = 10;
  int y = 20;

  printf("%d, %d\n", x, y);
  swap(&x, &y);
  printf("%d, %d\n", x, y);

  return 0;
}
