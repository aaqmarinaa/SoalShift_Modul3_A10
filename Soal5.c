#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

void *baca(void *arg){
   FILE *fp;
   fp=fopen("Novel.txt", "r+");
   int hitung;
   char word[500];
   char Novel[999];
   while(fscanf(fp, "%s\n", Novel) != EOF){
      if(strstr(Novel, word) != NULL)
         hitung++;
   }
   printf("%d\n", hitung);
}
int main(int argc, char* argv[]){
   pthread_t novel[argc];
   printf("./cari ");
   scanf("%s", &word[]);
   int i, temp;
   for(i=1; i<=argc; i++){
	temp = atoi(argv[i]);
	pthread_create(&(novel[i]), NULL, &baca, (void*)temp);
   }
   for(i=1; i<=argc; i++){
	pthread_join(novel[i], NULL);
   }
}
