#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#define MAX 5
 
 
void *mult(void* arg)
{
    int *veri = (int *)arg;
    int k = 0, i = 0;
     
    int x = veri[0];
    for (i = 1; i <= x; i++)
           k += veri[i]*veri[i+x];
     
    int *p = (int*)malloc(sizeof(int));
         *p = k;
     
    pthread_exit(p);
}
 
int main()
{
 
    int A[MAX][MAX];
    int B[MAX][MAX];
     
    int r1=MAX,c1=MAX,r2=MAX,c2=MAX,i,j,k;
    printf("A MATRISI  \n");
 
    for (i = 0; i < r1; i++)
            for (j = 0; j < c1; j++)
                   A[i][j] = rand() % 10;
           
    for (i = 0; i < r1; i++)
            for (j = 0; j < c1; j++)
                   B[i][j] = rand() % 10;
      
    for (i = 0; i < r1; i++){
        for(j = 0; j < c1; j++)
            printf("%d ",A[i][j]);
        printf("\n");
    }
      printf("\nB MATRISI \n");            
    for (i = 0; i < r2; i++){
        for(j = 0; j < c2; j++)
            printf("%d ",B[i][j]);
        printf("\n");   
    }
     
     
    int max = r1*c2;
     
          
    pthread_t *threads;
    threads = (pthread_t*)malloc(max*sizeof(pthread_t));
     
    int count = 0;
    int* veri = NULL;
    for (i = 0; i < r1; i++)
        for (j = 0; j < c2; j++)
               {
                
            veri = (int *)malloc((20)*sizeof(int));
            veri[0] = c1;
     
            for (k = 0; k < c1; k++)
                veri[k+1] = A[i][k];
     
            for (k = 0; k < r2; k++)
                veri[k+c1+1] = B[k][j];
              
                pthread_create(&threads[count++], NULL,
                               mult, (void*)(veri));
                 
                }
     
    printf("\nMATRIS CARPIMI SONUCU  \n");
    for (i = 0; i < max; i++)
    {
      void *k;
       
      pthread_join(threads[i], &k);
          int *p = (int *)k;
      printf("%d ",*p);
      if ((i + 1) % c2 == 0)
          printf("\n");
    }
 
     
 
  return 0;
}
