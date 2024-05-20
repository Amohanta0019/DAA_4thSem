#include <iostream>
#include <climits>
using namespace std;

const int MAX = 100;
int m[MAX][MAX] = {0};
int s[MAX][MAX] = {0};

void printOptimalParens(int s[MAX][MAX], int i, int j)
{
    if (i == j)
    {
        cout << "A" << i;
    }
    else
    {
        cout << "(";
        printOptimalParens(s, i, s[i][j]);
        printOptimalParens(s, s[i][j] + 1, j);
        cout << ")";
    }
}

void MatrixChain(int p[MAX], int n)
{
    int min;

    for (int d = 1; d < n - 1; d++)
    {
        for (int i = 1; i < n - d; i++)
        {
            int j = i + d;
            // m[i][j] = INT_MAX;
            min = INT_MAX;
            for (int k = i; k <= j - 1; k++)
            {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < min)
                {
                    min = q;
                    s[i][j] = k;
                }
            }
            m[i][j] = min;
        }
    }
    cout << "Minimum number of multiplications is :- " << m[1][n - 1] << endl;

}
int main()
{
    int n = 5;
    int p[] = {5, 4, 6, 2, 7};

    MatrixChain(p,n);
    cout << "Optimal Parenthesization is:- ";
    printOptimalParens(s, 1, n - 1);
    cout << endl;

    return 0;
}
