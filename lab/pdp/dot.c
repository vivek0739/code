#include<stdio.h>
#include<string.h>
#include<mpi.h>
int main(int argc,char *argv[])
{
    int dest,source,tag,p,my_rank;
    tag=0;
    char message[100];
    int X[4]={0,1,2,3};
    int Y[4]={4,5,6,7};
    MPI_Status status;
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&my_rank);
    MPI_Comm_size(MPI_COMM_WORLD,&p);
    if(my_rank!=0)
    {
        dest=0;
        int sum=X[my_rank-1]*Y[my_rank-1];
        sprintf(message,"%d",sum);
        MPI_Send(message,strlen(message)+1,MPI_CHAR,dest,tag,MPI_COMM_WORLD);
    }
    else
    {
        int sum=0;
        for(source=1;source<p;source++)
        {
            int temp;
            MPI_Recv(message,100,MPI_CHAR,source,tag,MPI_COMM_WORLD,&status);
            sscanf(message,"%d",&temp);
            sum+=temp;
        }
        printf("%dn",sum);
    }
    MPI_Finalize();
    return 0;
}
