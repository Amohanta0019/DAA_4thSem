#include <iostream>
#include <fstream>
using namespace std;
int G[100][100];
int V;
int m;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void readGraph()
{
    ifstream input("mColoring.txt");
    input >> V; // reads number of vertices
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            input >> G[i][j]; // read matrix
        }
    }
    input.close();
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

bool isSafe(int node, int color[], int G[100][100], int V, int rong)
{
    for (int k = 0; k < V; k++)
    {
        if (k != node && G[k][node] == 1 && color[k] == rong)
        //  not same node && adj to given node && k has the same color
        {
            return false;
        }
    }
    return true;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

bool solve(int G[100][100], int node, int color[], int m, int V)
{
    if (node == V) //last node
    {
        return true;
    }
    else
    {
        for (int i = 1; i <= m; i++) //try all color
        {
            if (isSafe(node, color, G, V, i))  //check if i can color
            {
                color[node] = i;  //assign color

                if (solve(G, node + 1, color, m, V)) // recursive call
                {
                    return true;  // successful, can color
                }
                color[node] = 0;  //backtrack , can't color ... erase prev color
            }
        }
    }
    return false; 
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

bool graphColoring(int G[100][100], int m, int V)
{
    int color[V] = {0}; // initialize color[] by max val as max V colors can use
    if (solve(G, 0, color, m, V))
    {
        return true;
    }
    return false;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int main(void)
{
    readGraph();
	cout << "Enter the number of colors: ";
    cin >> m;
    if (graphColoring(G, V, m))
        cout << "Graph can be colored with " << m << " colors.";
    else
        cout << "Graph cannot be colored with " << m << " colors.";
    return 0;
}