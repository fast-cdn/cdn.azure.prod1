#include <stdio.h>
#include <stdbool.h>

#define MAX_VALUE 9999999
#define VERTICES 5

//Predefined Graph vertices.
int graph[VERTICES][VERTICES] = {
    {5, 7, 2, 0, 0},
    {7, 0, 14, 5, 0},
    {2, 14, 0, 5, 6},
    {0, 5, 5, 0, 15},
    {0, 0, 6, 15, 0}};

int main()
{
    int no_edge = 0;
    int selected[VERTICES];
    for (int i = 0; i < VERTICES; i++)
    {
        selected[i] = false;
    }

    selected[0] = true;

    int x;
    int y;
    printf("Edge , Weight\n");

    while (no_edge < VERTICES - 1)
    {
        int min = MAX_VALUE;
        x = 0;
        y = 0;

        for (int i = 0; i < VERTICES; i++)
        {
            if (selected[i])
            {
                for (int j = 0; j < VERTICES; j++)
                {
                    if (!selected[j] && graph[i][j])
                    {
                        if (min > graph[i][j])
                        {
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        printf("%d - %d , %d\n", x, y, graph[x][y]);
        selected[y] = true;
        no_edge++;
    }

    return 0;
}