#include <iostream>
#include <fstream>
using namespace std;
int n;
int graph[100][100] = {0};

void readGraph()
{
    ifstream input("graph.txt");
    input >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            input >> graph[i][j];
        }
    }
    input.close();
}

int visited[100] = {0};
void dfs_rec(int v)
{
    cout << char('A' + v) << "  ";
    visited[v] = 1;
    for (int i = 0; i < n; i++)
    {
        if (graph[v][i] && !visited[i])
        {
            dfs_rec(i);
        }
    }
}

int stack[100] = {0};
int top = -1;
bool isEmpty()
{
    return top == -1;
}
void push(int ele)
{
    stack[top++] = ele;
}
void pop()
{
    top--;
}
int peek()
{
    return stack[top];
}

void dfs_norm(int v)
{
    push(v);
    cout << char('A' + v) << "  ";
    visited[v] = 1;
    while (!isEmpty())
    {
        int currNode = peek();
        pop();
        for (int i = 0; i < n; i++)
        {
            if (graph[currNode][i] && !visited[i])
            {
                push(i);
                cout<< char('A' + i) << "  ";
                visited[i] = 1;
            }
            
        }
    }
}
int main(void)
{
    readGraph();
    // dfs_rec(0);
    dfs_norm(0);
    return 0;
}