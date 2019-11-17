#include <iostream>
#include <vector>

class Graph
{

private:
    int v;        // Verticies
    int e;        // Edges
    int **matrix; // Adjacency Matrix
    int visitedIndexSum(int *arr, std::vector<bool> visited);
    int vectorDepth(std::vector<bool> visited);

public:
    Graph(int verticies);
    ~Graph();
    void addEdge(int start, int end);
    void makeComplete();
    void printMatrix();

    int dfsIndexCount(int first, int depth, int *arr, int len, std::vector<bool> visited);

    int **getMatrix();
    int getNumVerticies();
};

int main();