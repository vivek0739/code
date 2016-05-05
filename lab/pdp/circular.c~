#include<stdio.h>
#include<string.h>
#include "mpi.h"
main(int argc,char *argv[])
{
    int my_rank,p,source,dest,tag=1;
    char message[100];
    MPI_Status status;
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&my_rank);
    MPI_Comm_size(MPI_COMM_WORLD,&p);
    dest=(my_rank+1+p)%p;
    sprintf(message,"Greeting from process %d",my_rank);
    MPI_Send(message,strlen(message)+1,MPI_CHAR,dest,tag,MPI_COMM_WORLD);
    //printf(" to process %d",dest);
    MPI_Recv(message,100,MPI_CHAR,(my_rank-1+p)%p,tag,MPI_COMM_WORLD,&status);
    printf("%s to process %d\n",message,my_rank);
    MPI_Finalize();
}
