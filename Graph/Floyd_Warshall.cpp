#include <iostream>
#include <fstream>

#define INF 1e9
using namespace std;

int V;
int **G = new int *[V];

void readGraph()
{
    ifstream input("Floyd_Warshall.txt");
    if (!input)
    {
        cout << "Error in opening file";
        return;
    }
    else
    {
        input >> V;
        for (int i = 0; i < V; i++)
        {
            G[i] = new int[V];
            for (int j = 0; j < V; j++)
            {
                input >> G[i][j];
            }
        }
    }
    input.close();
}

void shortest_path(int **G, int V)
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (G[i][j] == -1)
            {
                G[i][j] = INF; // change -1 to infinity for ease of calculation
            }
            if (i == j)
            {
                G[i][j] = 0; // dist form 1 node to same node = 0
            }
        }
    }

    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                G[i][j] = min(G[i][j], (G[i][k] + G[k][j])); // minimum b/w original dist b/w i & j and dist got by inserting K vertex b/w i & j
            }
        }
    }

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (G[i][j] == INF)
            {
                G[i][j] = -1;
            }
        }
    }
}

void print(int **G, int V)
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cout << G[i][j] << " ";
        }
        cout << endl;
    }
}
int main(void)
{
    readGraph();

    /*
     for (int i = 0; i < V; i++) {
         G[i] = new int [V];
         for (int j = 0; j < V; j++) {
             G[i][j] = -1;
         }
     }
     G[0][1] = 2;
     G[1][0] = 1;
     G[1][2] = 3;
     G[3][0] = 3;
     G[3][1] = 5;
     G[3][2] = 4;
     */
    shortest_path(G, V);
    print(G,V);
    // delete[] G;

    return 0;
}