#include<stdio.h>
#include<string.h>
#include "mpi.h"
int main(int argc, char *argv[])
{
	int my_rank,p,source,dest,tag=0;
	MPI_Init(&argc,&argv);
	MPI_Status status;
	MPI_Comm_size(MPI_COMM_WORLD,&p);
	MPI_Comm_rank(MPI_COMM_WORLD,&my_rank);
	dest=(my_rank+1)%p;
	char message[100];
	sprintf(message,"%d",my_rank);
	MPI_Send(message,strlen(message)+1,MPI_CHAR,dest,tag,MPI_COMM_WORLD);
	source=(my_rank-1+p)%p;
	MPI_Recv(message,100,MPI_CHAR,source,tag,MPI_COMM_WORLD,&status);
	printf("Message from %s to %d\n", message , my_rank );
	MPI_Finalize();
}
