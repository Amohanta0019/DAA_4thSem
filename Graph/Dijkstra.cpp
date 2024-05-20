#include <iostream>
#include <fstream>
#include <climits>
using namespace std;

int V;

void printSolution(int d[]) {
    cout << "\nVertex Distance from Source\n";
    for (int i = 0; i < V; i++) {
        cout << i << "\t\t" << d[i] << endl;
    }
}

int extractMin(int dist[], bool spt[]) {
    int min = INT_MAX, minIndex;
    for (int v = 0; v < V; v++) {
        if (!spt[v] && dist[v] <= min) {
            min = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void dijkstra(int g[][100]) {
    int d[100], s, count, u, v;
    bool spt[100];

    for (int i = 0; i < V; i++) {
        d[i] = INT_MAX;
        spt[i] = false;
    }
    
    cout << "Enter the source Vertex: ";
    cin >> s;
    d[s] = 0;
    count = 0;

    while (count < V - 1) {
        u = extractMin(d, spt);
        spt[u] = true;
        for (v = 0; v < V; v++) {
            if (!spt[v] && g[u][v] && d[u] != INT_MAX && d[v] > d[u] + g[u][v]) {
                d[v] = d[u] + g[u][v];
            }
        }
        count++;
    }
    printSolution(d);
}

int main() {
    ifstream file("matrix_dks.txt");
    if (!file.is_open()) {
        cerr << "Error in opening file!!!" << endl;
        return 1;
    }

    file >> V;

    int cost[100][100];
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            file >> cost[i][j];
        }
    }

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << cost[i][j] << "\t";
        }
        cout << endl;
    }

    dijkstra(cost);

    file.close();
    return 0;
}
