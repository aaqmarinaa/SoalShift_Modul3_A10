#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_t faktor;

void *faktorial(void *ptr){
}

int main(){

   pthread_create(&faktor, NULL, &faktorial, NULL);
   pthread_join(faktor, NULL);
}
