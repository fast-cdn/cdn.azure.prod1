#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 20
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", arr[i]);
    }
}
int partition(int arr[], int low, int high)
{

    int random = low + rand() % (high - low);
    printf("\nPivot = %d ARRAY =", random);
    printArray(arr, SIZE);
    swap(&arr[random], &arr[low]);
    int pivot = arr[low];
    int i = low - 1, j = high + 1;

    while (0 < 1)
    {

        do
        {
            i++;
        } while (arr[i] < pivot);

        do
        {
            j--;
        } while (arr[j] > pivot);

        if (i >= j)
            return j;

        swap(&arr[i], &arr[j]);
    }
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {

        int pi = partition(arr, low, high);

        quickSort(arr, low, pi);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int arr[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = rand() % 20;
    }
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);

    return 0;
}
