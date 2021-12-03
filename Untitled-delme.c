#include <stdio.h>
#include <stdbool.h>
#define INF 9999

int find_min(int status[], int key[], int root[])
{
    int min = INF, id;
    for (int i = 0; i < 5; i++)
    {
        if (status[i] != 2 && status[i] != 1)
        {
            if (key[i] < min)
            {
                min = key[i];
                id = i;
            }
        }
    }
    return id;
}

void main()
{
    int G[5][5] = {
        {0, 10, 7, 1, 0},
        {10, 0, 14, 0, 7},
        {7, 14, 0, 2, 6},
        {1, 0, 2, 0, 4},
        {0, 7, 6, 4, 0}};
    int V = 5;
    int status[] = {0, 0, 0, 0, 0};
    int key[] = {0, INF, INF, INF, INF};
    int root[] = {0,
                  0,
                  0,
                  0,
                  0};
    int vc = 0;
    int curr_root;
    int prev_root = 0;

    while (vc < V)
    {
        curr_root = find_min(status, key, root);
        //printf("\n>> Current Root = %d ", curr_root);

        if (curr_root != prev_root)
        {
            printf("\n%d - %d : %d", prev_root, curr_root, G[prev_root][curr_root]);
        }
        prev_root = curr_root;
        status[curr_root] = 1;
        int prev_i = -1;
        for (int i = 0; i < V; i++)
        {
            if (G[curr_root][i] && status[i] != 1 && status[i] != 2)
            {
                if (key[i] > G[curr_root][i])
                {
                    key[i] = G[curr_root][i];
                    root[i] = curr_root;
                }
            }
        }
        //printf("\n----------------------------");
        //printf("\n %d\t%d\t%d\t%d\t%d", status[0], status[1], status[2], status[3], status[4]);
        //printf("\n %d\t%d\t%d\t%d\t%d", key[0], key[1], key[2], key[3], key[4]);
        //printf("\n %d\t%d\t%d\t%d\t%d", 0, 1, 2, 3, 4);
        //printf("\n %d\t%d\t%d\t%d\t%d", root[0], root[1], root[2], root[3], root[4]);
        status[curr_root] = 2;
        vc++;
    }
}