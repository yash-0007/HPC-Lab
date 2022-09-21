#include <stdio.h>
#include <omp.h>

int main()
{
    double start, end;
    int a[200];
    int b[200];
    int c[200];
    for (int i = 0; i < 200; i++)
    {
        a[i] = i;
        b[i] = i;
    }
    start = omp_get_wtime();
#pragma omp parallel for shared(a, b, c) schedule(static) num_threads(5)
    for (int i = 0; i < 200; i++)
    {
        c[i] = a[i] + b[i];
    }
    end = omp_get_wtime();
    printf("Vector Scalar Addition\n");
    for (int i = 0; i < 200; i++)
    {
        printf("c[%d] = %d\n", i, c[i]);
    }
    printf("Parallel Execution Time: %f\n", (end - start));
    return 0;
}
