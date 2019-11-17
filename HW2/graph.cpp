#include "graph.h"

Graph::Graph(int verticies)
{
    v = verticies;
    e = 0;
    matrix = new int *[v];
    for (int row = 0; row < v; row++)
    {
        matrix[row] = new int[v];
        for (int col = 0; col < v; col++)
        {
            matrix[row][col] = 0;
        }
    }
}

void Graph::addEdge(int start, int end)
{
    // Bidirectional only
    matrix[start][end] = 1;
    matrix[end][start] = 1;
    e++;
}

void Graph::makeComplete()
{
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (i != j)
            {
                addEdge(i, j);
            }
        }
    }
}

void Graph::printMatrix()
{
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            std::cout << matrix[i][j];
        }
        std::cout << std::endl;
    }
}

int Graph::visitedIndexSum(int *arr, std::vector<bool> visited)
{
    int sum = 0;
    for (int i = 0; i < visited.size(); i++)
    {
        if (visited[i])
        {
            sum += arr[i];
        }
    }
    return sum;
}

int Graph::vectorDepth(std::vector<bool> visited)
{
    int depth = 0;
    for (int i = 0; i < visited.size(); i++)
    {
        if (visited[i])
        {
            depth++;
        }
    }
    return depth;
}

int Graph::dfsIndexCount(int first, int depth, int *arr, int len, std::vector<bool> visited)
{
    visited[first] = true;
    int acc = 0; // Acumulator

    for (int i = first; i < v; i++)
    {
        if (vectorDepth(visited) == depth)
        {
            if (visitedIndexSum(arr, visited) == 33)
            {
                acc++;
            }
            visited[i] = false;
            if (i + 1 < v)
            {
                visited[i + 1] = true;
            }
        }
        else if (!visited[i] && matrix[first][i])
        {
            acc += dfsIndexCount(i, depth, arr, len, visited);
        }
    }
    visited[first] = false;
    return acc;
}

//EEEHHH
int **Graph::getMatrix()
{
    return matrix;
}

int Graph::getNumVerticies()
{
    return v;
}
