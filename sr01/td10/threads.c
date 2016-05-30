#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t semP, semC;
int stock_count = 0;
const int stock_max_limit=5;

void *producer(void *arg) {
    int i, sum=0;
    for (i = 0; i < 10; i++) {

        while(stock_max_limit == stock_count){
            printf("stock overflow, production on wait..\n");
            sem_wait(&semC);
            printf("production operation continues..\n");
        }

        sleep(1);   //production rate decided here
        stock_count++;
        printf("P::stock-count : %d\n",stock_count);
        sem_post(&semP);
        printf("P::post signal..\n");
    }
}

void *consumer(void *arg) {
    int i, sum=0;
    for (i = 0; i < 10; i++) {

        while(0 == stock_count){
            printf("stock empty, consumer on wait..\n");
            sem_wait(&semP);
            printf("consumer operation continues..\n");
        }

        sleep(2);   //consumer rate decided here
        stock_count--;
        printf("C::stock-count : %d\n", stock_count);
        sem_post(&semC);
        printf("C::post signal..\n");
    }
}

int main(void) {

    pthread_t tid0,tid1;
    sem_init(&semP, 0, 0);
    sem_init(&semC, 0, 0);

    pthread_create(&tid0, NULL, consumer, NULL);
    pthread_create(&tid1, NULL, producer, NULL);
    pthread_join(tid0, NULL);
    pthread_join(tid1, NULL);

    sem_destroy(&semC);
    sem_destroy(&semP);

    return 0;
}
