#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <mpi.h>

int main(int argc, char* argv[])
{
	int niter = 100000;
	int myid;
	double x,y;
	int i;
    int count = 0;
	double z;
	double pi;
	int numnodes;
	int reducedcount;
    clock_t t;
    t = clock();

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &myid);
	MPI_Comm_size(MPI_COMM_WORLD, &numnodes);

	srand48(time(NULL)+myid);

	for(i = 0; i < niter; i++)
	{
		x = (double)drand48();
		y = (double)drand48();
		z = ((x*x)+(y*y));
		if (z <= 1)
		{
			count++;
		}
	}

	MPI_Reduce(&count, &reducedcount, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
	int total_iter = niter * numnodes;

	if (myid == 0)
	{
		pi = ((double)reducedcount/(double)total_iter)*4.0;
		printf("Pi: %f\n", pi);
        t = clock() - t;
        double time_taken = ((double)t) / CLOCKS_PER_SEC;
        printf("Took %f seconds to execute \n", time_taken);
	}
	MPI_Finalize();
	return 0;
}