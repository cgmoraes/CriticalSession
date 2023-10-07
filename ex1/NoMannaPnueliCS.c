#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int NUM_THREADS, SUM = 0;

void *client() {
  while (1){
    int local = SUM;    
    sleep(rand()%2);     
    SUM = local + 1;    
    printf("%d\n", SUM);
  }
}

int main(int argc, char *argv[]) {
  NUM_THREADS = atoi(argv[1]);
  int i;
  pthread_t tids[NUM_THREADS];
  for (i = 0; i < NUM_THREADS; i++) {
    pthread_create(&tids[i], NULL, client, NULL);
  }
  for (i = 0; i < NUM_THREADS; i++) {
    pthread_join(tids[i], NULL);
  }
  return 0;
}