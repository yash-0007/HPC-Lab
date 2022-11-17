#include <mpi.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    MPI_Init(NULL, NULL);

    int a[10], b[10], npes, myrank;
    MPI_Status status;

    MPI_Comm_size(MPI_COMM_WORLD, &npes);
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);

    if (myrank % 2 == 1)
    {
        MPI_Send(a, 10, MPI_INT, (myrank + 1) % npes, 1,
                 MPI_COMM_WORLD);
        MPI_Recv(b, 10, MPI_INT, (myrank - 1 + npes) % npes, 1,
                 MPI_COMM_WORLD, &status);
    }
    else
    {
        MPI_Recv(b, 10, MPI_INT, (myrank - 1 + npes) % npes, 1,
                 MPI_COMM_WORLD, &status);
        MPI_Send(a, 10, MPI_INT, (myrank + 1) % npes, 1,
                 MPI_COMM_WORLD);
    }

    MPI_Finalize();
}
