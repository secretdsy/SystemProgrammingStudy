#include <signal.h> 
#include <unistd.h> 

void sig_handler(int signo); // 비프음 발생 함수

int main()
{
    int i = 0;
    signal(SIGINT, (void *)sig_handler); // sigint를 했을 때 (void*)sig_handler를 실행해라

    while(1)
    {
        printf("%d\n", i);
        i++;
        sleep(1);
    }
    return 1;
}


void sig_handler(int signo)
{
    printf("\a");
}
