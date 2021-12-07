#include <stdio.h>
#include <stdbool.h>

int i = 0;
int k = 0;
int r = 0;
int j = 0;

void dfs(int node, int* used, int** matrix, int countOfNodes, int countOfEdges)
{
    used[node] = true;
    int p = 0;
    for (i = k; i < countOfNodes; i++)
    {
        j = r;
        if (!used[i] && matrix[i][j] != 0)
        {
            used[i] = true;
            p = i;
            for (j = 0; j < countOfEdges; j++)
            {
                i = p;
                if (matrix[i][j] != 0)
                {
                    r = j;
                    for (k = 0; k < countOfNodes; k++)
                    {
                        j = r;

                        if ((matrix[k][j] != 0) && (!used[k]))
                        {
                            dfs(i, used, matrix, countOfNodes, countOfEdges);
                        }
                    }
                }
            }
        }
    }
}

int countOfComponents(int countOfNodes, int* used, int** matrix, int countOfEdges)
{
    int count = 0;
    for (int i = 0; i < countOfNodes; ++i) {
        if (!used[i]) {
            dfs(i, used, matrix, countOfNodes, countOfEdges);
            ++count;
        }
    }
    return count;
}


int main()
{
    int matrix[100][100] = { 0 };
    int countOfNodes = 0;
    int countOfEdges = 0;
    int adjacencyMatrix[100][100] = { 0 };
    scanf("%d %d", &countOfNodes, &countOfEdges);
    for (int i = 0; i < countOfNodes; i++)
    {
        for (int j = 0; j < countOfEdges; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    bool used[100] = { false };
    m(matrix);
  //  printf("%d", countOfComponents(countOfNodes, used, matrix, countOfEdges));
}