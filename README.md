# monte-carlo
Serial and parallel benchmark comparison between serial program, mpi and pthread

## How to compile
```
    gcc serial_monte_carlo.c -o serial
    mpicc mpi_monte_carlo.c -o mpi
    gcc pthread_monte_carlo.c  -lm -pthread -o pthread;
```
