#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_t faktor;

void faktorial(){
   int i, bil;
   for(i=1; i<=bil; i++)
   {
	faktor=i*faktor;
   }
}

int main(){
   int faktor=1, bil;
   printf("./faktorial ");
   scanf("%d ", &bil);
   faktorial();
   printf("Hasil %d! = %d\n", bil, faktor);
   pthread_create(&faktor, NULL, &faktorial, NULL);
   pthread_join(faktor, NULL);
}
