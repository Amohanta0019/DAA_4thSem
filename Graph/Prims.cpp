#include <iostream>
#include <climits>
#include <fstream>
using namespace std;

int prims(int n, int **cost, int t[][2])
{
	int mincost = INT_MAX;
	int *near = new int[n];
	int i, j, k, l, k1;

	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (cost[i][j] < mincost)
			{
				k = i;
				l = j;
				mincost = cost[i][j];
			}
		}
	}
	t[0][0] = k;
	t[0][1] = l;

	for (i = 1; i < n; i++)
	{
		if (cost[i][k] < cost[i][l])
		{
			near[i] = k;
		}
		else
			near[i] = l;

		near[k] = near[l] = -1;
	}

	for (i = 1; i < n - 1; i++)
	{
		int min = INT_MAX;
		int idx, j = 0;
		for (idx = 0; idx < n; idx++)
		{
			if (near[idx] != -1 && cost[idx][near[idx]] < min)
			{
				min = cost[idx][near[idx]];
				j = idx;
			}
		}
		t[i][0] = j;
		t[i][1] = near[j];
		mincost += cost[j][near[j]];
		near[j] = -1;

		for (k1 = 0; k1 < n; k1++)
		{
			if (near[k1] != -1 && cost[k1][near[k1]] > cost[k1][j])
			{
				near[k1] = j;
			}
		}
	}

	delete[] near;
	return mincost;
}

int main(void)
{
	int rows, cols; 

	ifstream inp("adjacency.txt");
	inp >> rows >> cols;
	int **cost = new int *[rows];
	for (int i = 0; i < rows; i++)
	{
		cost[i] = new int[cols];
		for (int j = 0; j < cols; j++)
		{
			inp >> cost[i][j];
		}
	}
	int t[rows-1][2];

	int mc = prims(rows,cost,t);
	cout<<"min cost :- "<<mc<<endl;
	for (int i = 0; i < rows-1; i++)
	{
		cout<< t[i][0] << "---" << t[i][1]<<endl;
	}
	inp.close();
	return 0;
}