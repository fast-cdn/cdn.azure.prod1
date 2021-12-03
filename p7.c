#include <stdio.h>
#include <limits.h>
#define INFINITE 999999999
long int m[20][20];
int s[20][20];
int p[20], i, j, n;

void print_optimal_chain(int i, int j)
{
    if (i == j)
        printf(" A%d ", i);
    else
    {
        printf("( ");
        print_optimal_chain(i, s[i][j]);
        print_optimal_chain(s[i][j] + 1, j);
        printf(" )");
    }
}

void generate_tables(void)
{
    long int q;
    int k;
    for (i = n; i > 0; i--)
    {
        for (j = i; j <= n; j++)
        {
            if (i == j)
                m[i][j] = 0;
            else
            {
                for (k = i; k < j; k++)
                {
                    q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                    if (q < m[i][j])
                    {
                        m[i][j] = q;
                        s[i][j] = k;
                    }
                }
            }
        }
    }
}

void main()
{
    int k;
    printf("Enter the number of matrix: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        for (j = i + 1; j <= n; j++)
        {
            m[i][i] = 0;
            m[i][j] = INFINITE;
            s[i][j] = 0;
        }
    printf("\nEnter the dimensions: \n");
    for (k = 0; k <= n; k++)
    {
        printf("P%d: ", k);
        scanf("%d", &p[k]);
    }
    generate_tables();
    printf("\nMatrix M:\n");
    for (int x = 1; x <= n; x++)
    {
        for (int y = 1; y <= n; y++)
        {
            printf("%d\t", m[x][y]);
        }
        printf("\n");
    }
    printf("\nMatrix S:\n");
    for (int x = 1; x <= n; x++)
    {
        for (int y = 1; y <= n; y++)
        {
            printf("%d\t", s[x][y]);
        }
        printf("\n");
    }
    i = 1, j = n;
    printf("\nOptimum multiplication sequence : ");
    print_optimal_chain(i, j);
    printf("\nMinimum scalar multiplications : %d \n",
           m[1][n]);
}

//https://sahebg.github.io/computersceince/matrix-multiplication-chain-c-program/