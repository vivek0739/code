#include<stdio.h>
#include<string.h>
#include "mpi.h"

int main(int argc,char **argv)
{
 int source,tag,dest,my_rank,num;
 MPI_Status status;
 MPI_Init(&argc,&argv);
 MPI_Comm_size(MPI_COMM_WORLD,&num);
 MPI_Comm_rank(MPI_COMM_WORLD,&my_rank);
 int i;
 double x[4]={1,2,3,4};
 double y[4]={1,4,9,16};
 int n=4;

 double X=5.5;
 char message[100];
 double l=1; 
  for(i=0;i<n;i++)
  {
   l*=(X-x[i]);
  }
 //printf("%lf\n",l);
 if(my_rank!=0)
 {
         
  
  int j=my_rank-1;
  //printf("%d %lf\n",my_rank,l);
  double p=1;
  for(i=0;i<n;i++)
  { 
   if(i==j) continue;
   else
    p*=(x[j]-x[i]);
  }
  
  sprintf(message,"%lf",l/(X-x[j])*y[j]/p);
  //printf("%lf\n",p);
  dest=0;
  tag=0;
  MPI_Send(message,strlen(message),MPI_CHAR,dest,tag,MPI_COMM_WORLD);
  
  
 }
 else
 {
  double sum=0;
  for(source=1;source<num;source++)
  {
   //printf("yes");
   MPI_Recv(message,100,MPI_CHAR,source,tag,MPI_COMM_WORLD,&status);
   double l;
   sscanf(message,"%lf",&l);
   sum+=l;
   // printf("%lf\n",l);
  }
  printf("f(x) for x is %lf\n",sum);
 }
 MPI_Finalize();
 
}
