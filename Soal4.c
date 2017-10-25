#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

int bil;
void* faktorial(void* arg){
   int faktor = (int*) arg;
   int fac = 1, i;
   for(i=1; i<=faktor; i++)
   {
	fac=i*fac;
   }
	printf("Hasil %d! = %d", faktor, fac);
}

int main(int argc, char* argv[]){
   pthread_t t[argc];
   printf("./faktorial ");
   scanf(" %d", &bil);
   int i, temp;
   for(i=1; i<=argc; i++)
   {
	temp = atoi(argv[i]);
	pthread_create(&(t[i]), NULL, &faktorial, (void*)temp);
   }
   for(i=1; i<=argc; i++){
	pthread_join(t[i], NULL);
   }
}
