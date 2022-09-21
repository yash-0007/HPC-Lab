#include <stdio.h>
#include <omp.h>

int main()
{
    double start, end;
    int sum = 0;
    start = omp_get_wtime();
#pragma omp parallel for reduction(+ \
                                   : sum) num_threads(5)
    for (int i = 0; i < 100; i++)
    {
        sum += (i * i);
    }
    end = omp_get_wtime();
    printf("Sum of squares till 100 is %d\n", sum);
    printf("Parallel Execution Time: %f\n", (end - start));
    return 0;
}
