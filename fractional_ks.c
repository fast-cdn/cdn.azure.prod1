#include <stdio.h>
void main()
{
    int MAX = 10;
    float weight[] = {2, 4, 5, 7, 8};
    float profit[] = {5,
                      36,
                      61,
                      44,
                      65};
    float ratio[5];
    for (int i = 0; i < 5; i++)
    {
        ratio[i] = profit[i] / weight[i];
        printf(" %f ", ratio[i]);
    }
    int placed[] = {0, 0, 0, 0, 0};
    int bkt = 0;
    int Imax = -999;
    int max_p, max_v;
    float max_profit = 0;
    for (int j = 0; j < 5; j++)
    {
        Imax = -1;
        max_p = -1;
        max_v = -1;
        if (bkt < MAX)
        {
            for (int i = 0; i < 5; i++)
            {
                if (Imax < ratio[i] && placed[i] == 0)
                {
                    Imax = ratio[i];
                    max_p = i;
                    max_v = profit[i];
                }
            }
            placed[max_p] = 1;
            if ((MAX - bkt) < weight[max_p])
            {

                float temp = weight[max_p] - (MAX - bkt);
                temp = (temp * profit[max_p]) / weight[max_p];
                max_profit += temp;
                bkt = MAX;
            }
            else
            {

                bkt = bkt + weight[max_p];
                max_profit += profit[max_p];
            }
        }
    }
    for (int i = 0; i < 5; i++)
    {
        printf(" %d ", placed[i]);
    }
    printf("\nMAX profit : %f", max_profit);
}