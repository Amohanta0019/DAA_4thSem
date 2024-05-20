#include <iostream>
#include <climits>
using namespace std;

int *bellman_ford(int V, int G[][3], int S)
{
    int *dist = new int[V];
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT16_MAX;
    }
    dist[S] = 0;
    for (int i = 0; i < V - 1; i++)
    {
        for (int j = 0; j < V; j++)
        {
            int u = G[j][0];
            int v = G[j][1];
            int wt = G[j][2];

            if (dist[u] != INT16_MAX && dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt;
            }
        }
    }
    for (int j = 0; j < V; j++)
    {
        int u = G[j][0];
        int v = G[j][1];
        int wt = G[j][2];

        if (dist[u] != INT16_MAX && dist[u] + wt < dist[v])
        {
            return NULL;
        }
    }

    return dist;
}

int main(void)
{
    int V = 6;
    int G[7][3] = {
                    {0, 1, 5},
                    {1, 2, 1},
                    {1, 3, 2},
                    {2, 4, 1},
                    {4, 3, -1},
                    {3, 5, 2},
                    {5, 4, -3}
                };
    int S = 0;
    int *dist = bellman_ford(V, G, S);
    if (dist == NULL)
    {
        cout << "Negative cycle detected." << std::endl;
    }
    else
    {
        for (int i = 0; i < V; i++)
        {
            cout << dist[i] << " ";
        }
        cout << endl;
        delete[] dist;
    }
    return 0;
}