// C Program to find the minimum scalar product of two vectors (dot product)
#include <stdio.h>
#include <omp.h>

int sort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

int sort_des(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n; ++i)
    {
        for (j = i + 1; j < n; ++j)
        {
            if (arr[i] < arr[j])
            {
                int a = arr[i];
                arr[i] = arr[j];
                arr[j] = a;
            }
        }
    }
}

int main()
{
    // fill the code;
    double start, end;
    int n;
    scanf("%d", &n);
    int arr1[n], arr2[n];
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
    }
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr2[i]);
    }
    sort(arr1, n);
    sort_des(arr2, n);
    int sum = 0;
    start = omp_get_wtime();
#pragma omp parallel for reduction(+ \
                                   : sum) shared(arr1, arr2) num_threads(5)
    for (i = 0; i < n; i++)
    {
        sum = sum + (arr1[i] * arr2[i]);
    }
    end = omp_get_wtime();
    printf("%d\n", sum);
    printf("Parallel Execution Time: %f\n", (end - start));
    return 0;
}
