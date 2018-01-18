#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 8
#define MAX_LEN 4000

long long **mat_a;
long long **mat_b;
long long **mat_c;
long long frg = MAX_LEN / NUM_THREADS; //분할할 크기
void *matrix(void *arg);

int main()
{
  FILE *fp;
  FILE *fp2;
  if((fp =fopen("./sample1.txt", "r"))==NULL)
  {
    printf("error!");
    exit(1);
  }

  mat_a = (long long **)malloc(sizeof(long long*)*MAX_LEN);
  for(long long i=0;i<MAX_LEN;i++)
  {
    mat_a[i]=(long long*)malloc(sizeof(long long)*MAX_LEN);
  }
  
  for(long long j =0;j<MAX_LEN;j++)
  {
    for(long long k =0;k<MAX_LEN;k++)
    {
      fscanf(fp, "%lld", &mat_a[j][k]);
    }
  }

  fclose(fp);

  if((fp2 =fopen("./sample2.txt", "r"))==NULL)
  {
    printf("error!");
    exit(1);
  }

  mat_b = (long long **)malloc(sizeof(long long*)*MAX_LEN);
  for(long long i=0;i<MAX_LEN;i++)
  {
    mat_b[i]=(long long*)malloc(sizeof(long long)*MAX_LEN);
  }
  
  for(long long j =0;j<MAX_LEN;j++)
  {
    for(long long k =0;k<MAX_LEN;k++)
    {
      fscanf(fp2, "%lld", &mat_b[j][k]);
    }
  }

  fclose(fp2);

  mat_c = (long long **)malloc(sizeof(long long*)*MAX_LEN);
  for(long long i=0;i<MAX_LEN;i++)
  {
    mat_c[i]=(long long*)malloc(sizeof(long long)*MAX_LEN);
  }

   long long rc;
   pthread_t threads[NUM_THREADS];

       long long tmp = 0;

         for(long long i = 0; i < NUM_THREADS; i++) {
               pthread_create(&threads[i], NULL, &matrix, (void *)tmp); 
                     //(생성할 스레드 아이디, 스레드 특성 보통 NULL, 실행할 함수, 함수에 전달할 인자)
                   tmp += frg;
                     }

           for(long long i = 0; i < NUM_THREADS; i++) {
                 rc = pthread_join(threads[i], NULL);
                       //(생성한 스레드 아이디, 스레드가 종료되면 return받을 변수)

                     if(rc != 0) {
                             printf("Error in thread[%lld] : %lld\n", i, rc);
                                   exit(1);
                                       }
                       }
             unsigned long long tmp2=0;
                 for(long long i = 0; i < MAX_LEN; i++) {
                     for(long long j = 0; j <MAX_LEN; j++) {
                                       tmp2 += mat_c[i][j];
                                           }
                                             }
                                                 
  printf("%lld\n", tmp2);

  return 0;
}


void *matrix(void *arg) {
  long long i, j, k;
  long long t_sum;
  long seg = (long)arg;
  
  for(i = seg; i < seg+frg; i++) {
    for(j = 0; j < MAX_LEN; j++) {
      t_sum = 0;
      for(k = 0; k < MAX_LEN; k++) {
        t_sum += (mat_a[i][k] * mat_b[k][j]);
      }
      mat_c[i][j] = t_sum;
    }
  }
}
