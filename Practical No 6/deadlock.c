#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    MPI_Init(NULL, NULL);

    int a[10], b[10], myrank;
    MPI_Status s1, s2;

    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);

    if (myrank == 0)
    {
        MPI_Send(a, 10, MPI_INT, 1, 1, MPI_COMM_WORLD);
        MPI_Recv(b, 10, MPI_INT, 0, 2, MPI_COMM_WORLD, &s1);
    }
    else if (myrank == 1)
    {
        MPI_Send(b, 10, MPI_INT, 1, 2, MPI_COMM_WORLD);
        MPI_Recv(a, 10, MPI_INT, 0, 1, MPI_COMM_WORLD, &s2);
    }

    MPI_Finalize();
}
