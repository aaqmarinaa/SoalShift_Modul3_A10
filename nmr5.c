#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid[10];
int status = 0;

void* wordss(void *arg)
{
        char *nama;
        nama = (char *) arg;
        char prnth[1000]; 
        sprintf(prnth, "grep -o '%s' Novel.txt | wc -l", nama);
        char hsl[10];
        printf("%s : ", nama);
        FILE *A;
        A = popen(prnth, "r");
        while (fgets(hsl, sizeof(hsl), A)) 
        {
                printf("%s", hsl);
        }
        pclose(A);
        status++;

        return NULL;
}


int main(int bts, char * argv [])
{
        int i = 0,err;
        while (i < bts) 
        {
                while(status != i)
                {

                }
                pthread_create(&(tid[i]), NULL, &wordss, (void*)argv[i+1]);
                i++;
        }
        for(i = 0; i < bts - 1; i++)
        {
           pthread_join(tid[i],NULL);
        }
        return 0;
}
