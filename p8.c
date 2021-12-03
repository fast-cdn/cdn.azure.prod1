#include <stdio.h>
#include <string.h>
int max(int a, int b)
{
    return (a > b) ? a : b;
}

int main()
{
    char X[20];
    char Y[20];
    printf("Enter String 1: ");
    scanf("%s", X);
    printf("Enter String 2: ");
    scanf("%s", Y);

    int m = strlen(X);
    int n = strlen(Y);

    int L[m + 1][n + 1];
    int i, j;

    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;

            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;

            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
    printf("\nGenerated Matrix =\n");
    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
            printf(" %d ", L[i][j]);
        }
        printf("\n");
    }

    int index = L[m][n];
    char lcsAlgo[index + 1];
    lcsAlgo[index] = '\0';

    i = m;
    j = n;
    while (i > 0 && j > 0)
    {
        if (X[i - 1] == Y[j - 1])
        {
            lcsAlgo[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        }

        else if (L[i - 1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }

    printf("\nS1 : %s \nS2 : %s \n", X, Y);
    printf("LCS: %s\n", lcsAlgo);
    printf("Length of LCS is %d", L[m][n]);

    return 0;
}