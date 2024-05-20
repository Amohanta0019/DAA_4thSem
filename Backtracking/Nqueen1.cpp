#include <iostream>

using namespace std;

const int MAXN = 10;

char solutions[MAXN][MAXN * MAXN];
int solCount = 0;

void addSolution(char ans[][MAXN * MAXN], int board[][MAXN], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 1)
            {
                ans[solCount][i * n + j] = 'Q';
            }
            else
            {
                ans[solCount][i * n + j] = '-';
            }
        }
    }
    solCount++;
}

bool isSafe(int row, int col, int board[][MAXN], int n)
{
    int x = row;
    int y = col;

    while (y >= 0)
    {
        if (board[x][y] == 1)
            return false;
        y--;
    }

    x = row;
    y = col;

    while (x >= 0 && y >= 0)
    {
        if (board[x][y] == 1)
            return false;
        y--;
        x--;
    }

    x = row;
    y = col;

    while (x < n && y >= 0)
    {
        if (board[x][y] == 1)
            return false;
        y--;
        x++;
    }

    return true;
}

void solve(int col, char ans[][MAXN * MAXN], int board[][MAXN], int n)
{
    if (col == n)
    {
        addSolution(ans, board, n);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, board, n))
        {
            board[row][col] = 1;
            solve(col + 1, ans, board, n);
            board[row][col] = 0;
        }
    }
}

void nQueens(int n)
{
    int board[MAXN][MAXN] = {0};
    solve(0, solutions, board, n);
}

int main()
{
    int n;
    cout << "Enter the number of Queens: ";
    cin >> n;

    nQueens(n);

    cout << "Number of solutions: " << solCount << endl;

    cout << "Solutions:\n";
    for (int i = 0; i < solCount; i++)
    {
        cout << "Solution " << i + 1 << ":\n";
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                cout << solutions[i][j * n + k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
