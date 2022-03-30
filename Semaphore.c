// Wesley Baker and Adam Ringwell Semaphore Scenario
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
  
sem_t sem; //Define our semaphore.
  
void* function(void* arg){
    int *ptr = (int *)arg; //Create a pointer, pointing to the integer variable we created in the main.

    sem_wait(&sem); //Set the semaphore to wait status.
    printf("\nThread Begins\n");
    printf("%d", *ptr);
    
    printf(" plus %d", *ptr);
    (*ptr) = (*ptr) + (*ptr); //Add the integer passed in together.
    printf(" = %d", *ptr);

    sleep(3); //Semaphore is set to lock for 3 seconds, after the 3 seconds the second thread will be made.
              //The second thread will be made 2 seconds after the first one because the second thread is set to sleep for a second. 

    printf("\nThread Finished\n");
    sem_post(&sem); //Set semaphore value to 0;
}
  
  
int main(){
    int x = 5;
    int y = 4;
    sem_init(&sem, 0, 1); // Initialize Semaphore
    pthread_t t1,t2; // Thread variables
    pthread_create(&t1,NULL,function, &x); // Thread created, passes in the integer x as the argument for the thread function.
    sleep(1);//Two seconds in between each thread exectution.
    pthread_create(&t2,NULL,function, &y);// Thread created, passes in the integer y as the argument for the thread function.
    pthread_join(t1,NULL); //Allows multiple threads to be ran by utilizing pthread_join
    pthread_join(t2,NULL);
    sem_destroy(&sem); //Destroy the semaphore after it is no longer in use to avoid memory issues.
    return 0;
}