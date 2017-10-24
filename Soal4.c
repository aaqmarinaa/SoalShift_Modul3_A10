#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_t faktor;

void* faktorial(void *arg){
   int faktor=1, i, bil;
   printf("./faktorial ");
   scanf(" %d", &bil);
   for(i=1; i<=bil; i++)
   {
	faktor=i*faktor;
   }
   printf("Hasil %d! = %d", bil, faktor);
}

int main(){
   pthread_create(&faktor, NULL, &faktorial, NULL);
   pthread_join(faktor, NULL);

   return 0;
}
