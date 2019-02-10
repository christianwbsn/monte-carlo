#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	double niter = 100000;
	double x, y;
	int i;
    int count = 0;
	double z;
	double pi;
    clock_t t;
    t = clock();
	for (i=0; i<=niter; ++i)
	{
		x = (double) drand48();
		y = (double) drand48();
		z = ((x * x) + (y * y));
		if (z <= 1)
		{
			++count;
		}
	}
	pi = ((double) count / (double) niter) * 4.0;
	t = clock() - t;
	double time_taken = ((double)t) / CLOCKS_PER_SEC;
	printf("Pi: %f\n", pi);
	printf("Took %f seconds to execute \n", time_taken);
	return 0;

}