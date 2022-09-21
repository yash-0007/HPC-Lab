#include <stdio.h>
#include <omp.h>

int main()
{
    double start, end;
    int a[250][250];
    int b[250][250];
    int c[250][250];
    for (int i = 0; i < 250; i++)
    {
        for (int j = 0; j < 250; j++)
        {
            a[i][j] = i + j;
            b[i][j] = i + j;
        }
    }
    start = omp_get_wtime();
#pragma omp parallel for shared(a, b, c) num_threads(5)
    for (int i = 0; i < 250; i++)
    {
        for (int j = 0; j < 250; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    end = omp_get_wtime();
    printf("Vector Vector Addition\n");
    for (int i = 0; i < 250; i++)
    {
        for (int j = 0; j < 250; j++)
        {
            printf("c[%d][%d] = %d\n", i, j, c[i][j]);
        }
    }
    printf("Parallel Execution Time: %f\n", (end - start));
    return 0;
}
