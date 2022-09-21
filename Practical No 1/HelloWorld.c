#include <stdio.h>
#include <omp.h>

int main()
{
    double start, end;
    start = omp_get_wtime();
#pragma omp parallel num_threads(5)
    {
        printf("Hello World by Thread %d\n", omp_get_thread_num());
    }
    end = omp_get_wtime();
    printf("Parallel Execution Time: %f\n", (end - start));
    return 0;
}
