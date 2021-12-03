#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(arr, min, i);
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
    selectionSort(arr, n);
    printf("[DONE] : Sorting\n");
    end = time(NULL);
    printf("\nTime taken  = %ld seconds\n", (end - start));

    return 0;
}