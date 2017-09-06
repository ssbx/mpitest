#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <mpi.h>
#define USE_MPI
#define ITER_MAX 1000
#define RAND_SEED 68111

int
main(int argc, char** argv) {

    double x, y, z, pi;
    int i, j, mycount, count, niter, myid, 
        numprocs, proc, master, tag;
    MPI_Status status;

    if (argc < 2) {
        fprintf(stderr, "Not enough arguments");
        exit(1);
    }

    niter = master = count = mycount = 0;
    tag = 123;
   
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);

    sscanf(argv[1], "%d", &niter);

    srand48(RAND_SEED);
    for (i=0; i<niter; i++) {
        x = (double) drand48();
        y = (double) drand48();
        z = x*x + y*y;
        if (z <= 1) {
            mycount++;
        }
    }

    if (myid == 0) {
        count = mycount;

        for (proc=1; proc<numprocs; proc++) {
            MPI_Recv(&mycount, 1, MPI_REAL, proc, tag, MPI_COMM_WORLD, &status);
            count += mycount;
        }

        pi = (double) count / (niter * numprocs) * 4;
        printf("\n# numprocs = %i of trials = %d, estimate of pi is %g \n", numprocs, niter * numprocs, pi);
    } else {
        printf("Processor %d sending results = %d to master process\n", myid, mycount);
        MPI_Send(&mycount, 1, MPI_REAL, master, tag, MPI_COMM_WORLD);
    }

    MPI_Finalize();
    return 0;
}
