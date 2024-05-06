#include <mpi.h>
#include <stdio.h>
#include <stdlib.h> // Include for getenv
#include <unistd.h> // Include for gethostname
#define HOSTNAME_MAX_LENGTH 256 // Define a suitable buffer size for hostname

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    char hostname[HOSTNAME_MAX_LENGTH];
    gethostname(hostname, HOSTNAME_MAX_LENGTH); // Get the hostname

    printf("Hello world from processor %s, rank %d out of %d processors\n",
           hostname, world_rank, world_size);

    MPI_Finalize();
    return 0;
}