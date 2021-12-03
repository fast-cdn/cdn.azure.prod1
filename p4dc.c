// divide and conqure
#include <stdio.h>
int find_max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}
int divide_conqure(int A[], int low, int high)
{
    if (high == low)
    {
        return A[low];
    }

    int mid = (low + high) / 2;

    int left_max = 0;
    int sum = 0;
    for (int i = mid; i >= low; i--)
    {
        sum += A[i];
        if (sum > left_max)
        {
            left_max = sum;
        }
    }
    int right_max = 0;
    sum = 0;
    for (int i = mid + 1; i <= high; i++)
    {
        sum += A[i];
        if (sum > right_max)
        {
            right_max = sum;
        }
    }

    int max_left_right = find_max(divide_conqure(A, low, mid),
                                  divide_conqure(A, mid + 1, high));

    return find_max(max_left_right, left_max + right_max);
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
    int max = divide_conqure(arr, 0, size - 1);
    printf("MAX SUM = %d", max);
}