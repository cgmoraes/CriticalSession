#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int NUM_THREADS, request = 0, respond = 0, SUM = 0;

struct parameter {
  int tid;
};

void *client(void *params) {
  struct parameter *data = (struct parameter *)params;
  while (1){
    while(respond != data->tid) request = data->tid;
    int local = SUM;    
    sleep(1);     
    SUM = local + 1;
    printf("Thread %d Printou:%d\n", data->tid, SUM);
    fflush(0); 
    respond = 0;
  }
}

void *server() {
  while(1){
    while(!(request != 0));
    respond = request;
    while(!(respond == 0))
    request = 0;
  } 
}

int main(int argc, char *argv[]) {
  NUM_THREADS = atoi(argv[1]);
  int i;
  pthread_t tids[NUM_THREADS];
  struct parameter params[NUM_THREADS];
  params[0].tid = 0;
  pthread_create(&tids[0], NULL, server, &params[0]);
  for (i = 1; i < NUM_THREADS; i++) {
    params[i].tid = i;
    pthread_create(&tids[i], NULL, client, &params[i]);
  }
  for (i = 0; i < NUM_THREADS; i++) {
    pthread_join(tids[i], NULL);
  }
  return 0;
}