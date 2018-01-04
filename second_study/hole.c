#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main() {
  int fd;
  // 1.file.hole 파일 생성

  fd = creat("./file.hole", 0644);
  

  if(write (fd, buf1, 10) != 10) {
    printf("buf1 write error");
    close(fd);
    exit(-1);
  }
  // offset now = 10

  // 2.파일의 오프셋을 16384로 변경
  lseek(fd, 16374, SEEK_END);
  
  // offset now = 16384

  if(write(fd, buf2, 10) != 10) {
    printf("buf1 write error");
    close(fd);
    exit(-1);
  }

  // offset now 16394

  exit(0);
}

