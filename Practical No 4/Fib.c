#include <stdio.h>
#include <omp.h>

double start, end;

int fib(int n)
{
    int f[n + 2];
    int i;
    f[0] = 0;
    f[1] = 1;
    start = omp_get_wtime();
#pragma omp parallel for ordered num_threads(5)
    for (i = 2; i <= n; i++)
    {
#pragma omp ordered
        {
            f[i] = f[i - 1] + f[i - 2];
        }
    }
    end = omp_get_wtime();
    return f[n];
}

int main()
{
    int n = 9;
    printf("%d\n", fib(n));
    printf("Parallel Execution Time: %f\n", (end - start));
    return 0;
}
