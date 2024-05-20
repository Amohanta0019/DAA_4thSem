#include <iostream>
#include <fstream>
#include <climits>
using namespace std;

int prim(int n, int** cost, int t[][2]) {
    int mincost = INT_MAX;
    int* near = new int[n];
    int i, j, k, l, k1;

    // Let (k, l) be an edge of minimum cost
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (cost[i][j] < mincost) {
                k = i;
                l = j;
                mincost = cost[i][j];
            }
        }
    }
    // mincost = cost[k][l];
    t[0][0] = k;
    t[0][1] = l;

    //modify near[] by checking which vertex is near to i
    for (i = 0; i < n; i++) {
        if (cost[i][l] < cost[i][k]) {
            near[i] = l;
        } else {
            near[i] = k;
        }
    }
    near[k] = near[l] = -1;

    for (i = 1; i < n - 1; i++) {
        int min = INT_MAX;
        int idx, j = 0;
        for (idx = 0; idx < n; idx++) {
            if (near[idx] != -1 && cost[idx][near[idx]] < min) {
                min = cost[idx][near[idx]];
                j = idx;
            }
        }
        t[i][0] = j;
        t[i][1] = near[j];
        mincost += cost[j][near[j]];
        near[j] = -1;

        // Update near[]
        for (k1 = 0; k1 < n; k1++) {
            if (near[k1] != -1 && cost[k1][near[k1]] > cost[k1][j]) {
                near[k1] = j;
            }
        }
    }
    delete[] near;
    return mincost;
}

int main() {
    ifstream file("adjacency.txt");
    if (!file.is_open()) {
        cout << "Error in opening file !!!" << endl;
        return 1;
    }

    int rows, cols;
    // Read the dimensions of the matrix
    file >> rows >> cols;
    int** cost = new int*[rows];
    for (int i = 0; i < rows; i++) {
        cost[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            file >> cost[i][j];
        }
    }

    int t[rows - 1][2];
    int mincost = prim(rows, cost, t);
    cout << "\n\nMinimum Cost of Spanning tree is: " << mincost << endl;

    cout << "Edges of the Minimum Spanning Tree:" << endl;
    for (int i = 0; i < rows - 1; i++) {
        cout << t[i][0] << "--" << t[i][1] << endl;
    }

    for (int i = 0; i < rows; i++) {
        delete[] cost[i];
    }
    delete[] cost;

    file.close();
    return 0;
}
