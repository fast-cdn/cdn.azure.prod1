#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void selectionSort(int arr[], int start, int end)
{
    for (int i = start; i < end - 1; i++)
    {
        int min = i;

        for (int j = i + 1; j < end; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }

        swap(arr, min, i);
    }
}
void merge(int a1[], int a1_start, int a2_start, int a1_end, int a2_end)
{
    int SIZE = a2_end - a1_start;
    int result[SIZE];
    int k = 0;
    int i = a1_start;
    int j = a2_start;
    while (i < a1_end && j < a2_end)
    {
        if (a1[i] < a1[j])
        {
            result[k] = a1[i];
            i++;
        }
        else
        {
            result[k] = a1[j];
            j++;
        }
        k++;
    }
    while (i < a1_end)
    {
        result[k] = a1[i];
        k++;
        i++;
    }
    while (j < a2_end)
    {
        result[k] = a1[j];
        k++;
        j++;
    }

    k = 0;
    for (int x = a1_start; x < a1_end; x++)
    {
        a1[x] = result[k];
        k++;
    }
    for (int x = a2_start; x < a2_end; x++)
    {
        a1[x] = result[k];
        k++;
    }
}
void main()
{
    int i;
    int array[500];
    struct timeval start, end;
    FILE *fptr;
    fptr = fopen("input.txt", "wa");
    mingw_gettimeofday(&start, NULL);
    double st = (start.tv_sec) * 1000 + (start.tv_usec) / 1000;
    for (i = 0; i < 500; i++)
    {
        fprintf(fptr, "%d\n", rand() % 1000);
    }
    fclose(fptr);
    printf("\n>> 500 random numbers generated and written to \"input.txt\" file.");
    fptr = fopen("input.txt", "r");
    for (i = 0; i < 500; i++)
    {
        fscanf(fptr, "%d", &array[i]);
    }
    fclose(fptr);
    printf("\n>> Numbers fetched and stored to array from \"input.txt\" file.");
    // Sorting in batch of 50.
    for (i = 0; i < 500; i = i + 50)
    {
        selectionSort(array, i, i + 50);
    }
    // Merging two consecutive sorted array of 50 elemnts into one 100 elements array.
    for (i = 0; i < 500; i = i + 100)
    {
        merge(array, i, i + 50, i + 50, i + 100);
    }
    /* 
        Currently sorted array blocks = [100  100  100  100  100] 
        Merging 1st and 2nd 100 elements array
    */
    merge(array, 0, 100, 100, 200);
    /* 
        Currently sorted array blocks = [200  100  100  100]
        Merging 3rd and 4th 100 elements array 
    */
    merge(array, 200, 300, 300, 400);
    /* 
        Currently sorted array blocks = [200  200  100]
        Merging 2nd 200 element array with last 100 element array 
    */
    merge(array, 200, 400, 400, 500);
    /* 
        Currently sorted array blocks = [200  300]
        Merging 200 and 300 element array into final 500 element array.
    */
    merge(array, 0, 200, 200, 500);
    fptr = fopen("output.txt", "wa");

    for (i = 0; i < 500; i++)
    {
        fprintf(fptr, "%d\n", array[i]);
    }
    fclose(fptr);
    printf("\n>> Numbers sorted and written to \"output.txt\" file.\n");
    mingw_gettimeofday(&end, NULL);
    double et = (end.tv_sec) * 1000 + (end.tv_usec) / 1000;
    double time_taken = et - st;
    printf(" Time taken = %.0f ms", time_taken);
}