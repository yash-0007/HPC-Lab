#include <stdio.h>
#include <omp.h>

int main()
{
    double start, end;
    int a[200];
    int b[200];
    int c = 200;
    for (int i = 0; i < 200; i++)
    {
        a[i] = i;
    }
    start = omp_get_wtime();
#pragma omp parallel for firstprivate(c) shared(a, b) schedule(static) num_threads(5)
    for (int i = 0; i < 200; i++)
    {
        b[i] = a[i] + c;
    }
    end = omp_get_wtime();
    printf("Vector Scalar Addition\n");
    for (int i = 0; i < 200; i++)
    {
        printf("b[%d] = %d\n", i, b[i]);
    }
    printf("Parallel Execution Time: %f\n", (end - start));
    return 0;
}
