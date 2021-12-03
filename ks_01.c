#include <stdio.h>
int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
void main()
{
    int MAX = 10;
    int wt[] = {2, 4, 5, 7, 8};
    int val[] = {5,
                 36,
                 61,
                 44,
                 65};
    int K[6][11];
    int cw = 0;
    int cv = 0;
    for (int i = 0; i <= 5; i++)
    {
        for (int w = 0; w <= 10; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
            {
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            }
            else
                K[i][w] = K[i - 1][w];
        }
    }
    for (int i = 0; i <= 5; i++)
    {
        for (int w = 0; w <= 10; w++)
        {
            printf("%d ", K[i][w]);
        }
        printf("\n");
    }
}