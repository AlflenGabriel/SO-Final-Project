#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

struct p {
  int money;
  };
typedef struct p account;
account from, to;
int value;
int i;
sem_t semaphore;
void* transfer( void *arg){
  sem_wait(&semaphore);
  if (from.money >= value){
      from.money -= value;
      to.money += value;
    }
    printf("Transfer was sucessful.\n");
    printf("money from p1: %d\n", from.money);
    printf("money from p2: %d\n", to.money);
    sem_post(&semaphore);
}
  int main(){
    sem_init(&semaphore, 0, 1);
    pthread_t th[30];
    from.money = 100;
    to.money = 100;
    printf( "Transferring 30 to account p2\n" );
    value = 30;
    for(i=0; i < 30; i++){
    pthread_create(&(th[i]),NULL,transfer,NULL);
   }
    for (i=0;i<10;i++){
    pthread_join(th[i],NULL);
    }
    sem_destroy(&semaphore);
    printf("Transfer was sucessful.\n");
    return 0;
}
