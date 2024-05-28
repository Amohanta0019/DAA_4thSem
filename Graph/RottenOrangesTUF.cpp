#include<bits/stdc++.h>        
using namespace std;
class ro{
    public:
    int orangesRotten(vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair <int,int>, int>>q;
        int visited[n][m];
        int fresh = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({{i,j},0});
                    visited[i][j] = 2;
                }
                else
                {
                    visited[i][j] = 0;
                }
                if (visited[i][j]==1)
                {
                    fresh++;
                }               
            }  
        }

        int time = 0;
        int delta_row[] = {-1,0,+1,0};
        int delta_col[] = {0,+1,0,-1};
        
    }
};

int main(void)
{
    
return 0;
}