#include <signal.h>
#include <unistd.h>

static void
sig_alrm(int signo) {
  //nothing to do, just return to wake up the pause
}

unsigned int
sleep1(unsigned int seconds) {
  if(signal(SIGALRM, sig_alrm) == SIG_ERR)
    return(seconds);
  alarm(seconds); //seconds 뒤에 나에게 alarm이란 시그널을  보냄
  pause(); //신호가 발생할 때까지 대기
  return(alarm(0));
}

int main() {
  unsigned int ret = sleep1(5);
  printf("%u", ret);
}

