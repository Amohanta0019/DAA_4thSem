#include <bits/stdc++.h>
using namespace std;
class ro
{
public:
    int orangesRotten(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int, int>, int>> q;
        int visited[n][m];
        int fresh = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({{i, j}, 0});
                    visited[i][j] = 2;
                }
                else
                {
                    visited[i][j] = 0;
                }
                if (grid[i][j] == 1)
                {
                    fresh++;
                }
            }
        }

        int time = 0;
        int delta_row[] = {-1, 0, +1, 0};
        int delta_col[] = {0, +1, 0, -1};
        int count = 0;

        while (!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;

            time = max(time, t);
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nrow = r + delta_row[i];
                int ncol = c + delta_col[i];

                if (nrow >= 0 && ncol >= 0 && ncol < m && nrow < n && visited[nrow][ncol] == 0 && grid[nrow][ncol] == 1)
                {
                    q.push({{nrow, ncol}, t + 1});
                    visited[nrow][ncol] = 2;
                    count++;
                }
            }
        }
        if (count != fresh)
        {
            //cout << "oranges left " << endl;
            return -1;
        }
        else
        {
            return time;
        }
    }
};

int main(void)
{
    vector<vector<int>> grid{{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    ro obj;
    int ans = obj.orangesRotten(grid);
    cout << "time taken :- " << ans << "\n";

    return 0;
}