#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int arr[], int i, int n)
{
    int value = arr[i];
    int j = i;
    while (j > 0 && arr[j - 1] > value)
    {
        arr[j] = arr[j - 1];
        j--;
    }

    arr[j] = value;
    if (i + 1 <= n)
    {
        insertionSort(arr, i + 1, n);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main(void)
{
    time_t start;
    time_t end;
    int size;
    printf("Enter dataset size = ");
    scanf(" %d", &size);
    int arr[size];
    printf("[NOW] : Generating random dataset\n");
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand();
    }
    printf("[DONE] : dataset generated\n");
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("[NOW] : Sorting\n");    
    start = time(NULL);
    insertionSort(arr, 1, n - 1);
    printf("[DONE] : Sorting\n");
    end = time(NULL);
    printf("\nTime taken  = %ld seconds\n", (end - start));

    return 0;
}