#include <stdio.h>
#include <unistd.h>

#define BUFFSIZE 4096

int main() {
  int n;
  char buf[BUFFSIZE];

  while((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0) {
    // 화면에 읽은 내용 출력
    write(STDOUT_FILENO, buf, n);
    
  }

  if(n < 0) {
    printf("read error");
    exit(-1);
  }
  exit(0);
}
