#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

volatile int counter = 0;
int loops;
pthread_mutex_t mlock = PTHREAD_MUTEX_INITIALIZER;

void *worker(void *arg) {  //함수의 주소값을 넘겨줌 void pointer를 인자로받음
                           //(1개만 받을 수 있음, 여러인자를 받으려면 구조체를 넘겨줘야함)
  int i;
  pthread_mutex_lock(&mlock);
  
  for(i = 0; i < loops; i++) { //loops=입력값 만큼 실행
    counter++;
  }
  pthread_mutex_unlock(&mlock);

  return NULL;
}

int main(int argc, char *argv[]) {
  if(argc != 2) {
    fprintf(stderr, "usage : threads <value>\n");
    exit(1);
  }
  loops = atoi(argv[1]);
  pthread_t p1, p2;
  printf("Initial value : %d\n", counter);
  pthread_create(&p1 , NULL , worker , NULL);  // (3번째 처리할 함수, 4번째 전달할 인자:void agrv[])
  pthread_create(&p2 , NULL , worker , NULL);
  pthread_join(p1 , NULL);                     // process의 wait과 같음 자식 스레드가 끝날때까지 부모스레드는 끝나면 안됨
  pthread_join(p2 , NULL);
  printf("Final value : %d\n", counter);
  return 0;
}
