#include <stdio.h>
#include "mpi.h"

int mat[3][3] = {1,2,3,4,5,6,7,8,9}, vec[3] = {1,2,3}, val[3];

int cal(int rank, int n) {
        int val = 0, i;
        for(i = 0; i < n; i++)
                val += mat[rank - 1][i] * vec[i];
       // printf("returning %d for rank = %d\n", val, rank);
        return val;
}

int main(int argc, char **argv) {
        int size, rank,m = 3,n = 3, i, j, dest = 0, tag = 1, value;
        MPI_Status stat;
        MPI_Init(&argc, &argv);
        MPI_Comm_size(MPI_COMM_WORLD, &size);
        MPI_Comm_rank(MPI_COMM_WORLD, &rank);

        if(rank == 0) {
                printf("For Matrix: ");
                for(i = 0; i < m; i++){for(j = 0; j < n; j++)printf("%d ",mat[i][j]);putchar(10);}
                for(i = 0; i < m; i++)
                        MPI_Recv(&val[i], 1, MPI_INTEGER, i + 1, tag, MPI_COMM_WORLD, &stat);
                printf("Computed matrix vector multiplication:\n");
                for(i = 0; i < m; i++) {
                        printf("%d\n", val[i]);
                }
        }
        else {
                if(rank > m + 1) {
                        value = 0;
                       // printf("Setting 0\n");
                }
                else value = cal(rank , n);
                MPI_Send(&value, 1, MPI_INTEGER, dest, tag, MPI_COMM_WORLD);
        }
        MPI_Finalize();
        return 0;
}
