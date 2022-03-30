//Wesley Baker and Adam Ringwell's Deadlock Avoidance Taken From Class Examples
#include<pthread.h>
#include<stdio.h>
#include<unistd.h>

pthread_mutex_t lock1;
pthread_mutex_t lock2;

void *resource1(){
  printf("Process Started in R1\n");
  sleep(2); //Sleep for 2 seconds

  printf("Attempting to get R2\n");
  pthread_mutex_lock(&lock2); //Place a lock on resource 2
  printf("Running R2\n");
  pthread_mutex_unlock(&lock2); //After allowing resource 1 to run, unlock resource 2.

  printf("R1 Finished\n");

  pthread_mutex_unlock(&lock1);

  pthread_exit(NULL);
}

void *resource2(){
  pthread_mutex_lock(&lock2); //Place a lock on resource 2

  printf("Process Started in R2\n");
  sleep(2); //Sleep for 2 seconds

  printf("Running R2\n");
  pthread_mutex_lock(&lock1); //Place a lock on resource 1
  pthread_mutex_unlock(&lock1); //Unlock resource 2 after allowing resource 1 to run.

  printf("R2 Finished\n");

  pthread_mutex_unlock(&lock2);

  pthread_exit(NULL);
}

int main() {
    
  pthread_mutex_init(&lock1,NULL); // Initialize locks
  pthread_mutex_init(&lock2,NULL);

  pthread_t t1,t2; // 2 Proccesses Created

  pthread_create(&t1,NULL,resource1,NULL); // Create resources
  pthread_create(&t2,NULL,resource2,NULL);

  pthread_join(t1,NULL);
  pthread_join(t2,NULL);

  return 0;
}