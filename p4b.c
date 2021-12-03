// brute force
#include <stdio.h>
void brute_force(int arr[], int size)
{
    int max_sum = 0;
    int max_start = 0;
    int max_end = 0;
    int local_sum;
    for (int i = 0; i < size; i++)
    {
        local_sum = 0;
        for (int j = i; j < size; j++)
        {
            local_sum += arr[j];
            if (local_sum > max_sum)
            {
                max_sum = local_sum;
                max_start = i;
                max_end = j;
            }
        }
    }
    printf("MAX SUM = %d , start = %d, end = %d", max_sum, max_start, max_end);
}
void main()
{
    int size;
    printf("Enter size of array : ");
    scanf(" %d", &size);
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        printf("Enter arr[%d] : ", i);
        scanf(" %d", &arr[i]);
    }
    brute_force(arr, size);
}