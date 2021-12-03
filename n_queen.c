#include <stdio.h>

int N = 8;
int safe_move(int board[N][N], int row, int col);
int nq(int board[N][N], int col)
{
    if (col >= N)
        return 1;

    for (int i = 0; i < N; i++)
    {
        if (safe_move(board, i, col))
        {
            board[i][col] = 1;

            if (nq(board, col + 1))
                return 1;

            board[i][col] = 0;
        }
    }
    return 0;
}

int safe_move(int board[N][N], int row, int col)
{
    int i, j;

    for (i = 0; i < col; i++)
        if (board[row][i])
            return 0;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return 0;

    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return 0;

    return 1;
}

void main()
{
    int board[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            board[i][j] = 0;
        }
    }

    if (nq(board, 0) == 0)
    {
        printf("Solution does not exist");
    }
    printf("Solution for %d-queens.\n", N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
}
