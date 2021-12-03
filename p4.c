//kadane

#include <stdio.h>
void kadane_algo(int arr[], int size)
{
    int max_sum = 0;
    int max_start = 0;
    int max_end = 0;
    int local_sum = 0;
    int current_start = 0;
    int current_end = 0;
    for (int i = 0; i < size; i++)
    {
        current_end = i;
        local_sum += arr[i];
        if (local_sum < arr[i])
        {
            local_sum = 0;
            current_start = i;
            i = i - 1;
        }
        if (max_sum < local_sum)
        {

            max_sum = local_sum;
            max_start = current_start;
            max_end = current_end;
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
    kadane_algo(arr, size);
}