#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>


pthread_t t[100];
int i;

void *baca(void *arg){
   char **input = (char**)arg;
   FILE *fp;
   fp=fopen("Novel.txt","r");
   char x;
   int a=0, hitung=0;
   while((x=fgetc(fp)) != EOF){
      if(x==input[i][a]) a++;
      else if(a==strlen(input[i])){
	   hitung++;
	   a=0;
      }
      else a=0;
   }
   printf("%s : %d\n", input[i], hitung);
}
int main(int argc, char *argv[]){
   for(i=1;i<=argc;i++)
   {
	pthread_create(&(t[i]), NULL, &baca, (void*)argv);
	pthread_join(t[i], NULL);
   }
   return 0;
}
