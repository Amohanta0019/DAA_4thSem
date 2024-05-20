#include <iostream>
using namespace std;

int graph[10][10];
int n;
void readGraph()
{
    FILE *fp;
    fp = fopen("dfs_bfs.txt", "r");
    if (fp == NULL)
    {
        cout << "error";
        exit(1);
    }
    fscanf(fp, "%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fscanf(fp, "%d", &graph[i][j]);
        }
    }
    return;
}

void showGraph()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << graph[i][j];
        }
        cout << endl;
    }
    return;
}

#define MAX 20
int stack[MAX];
int top = -1;
int isEmpty()
{
    if (top == -1)
        return 1;
    return 0;
}

int isFull()
{
    if (top == MAX - 1)
    {
        return 1;
    }
    return 0;
}
void push(int item)
{
    stack[++top] = item;
}
void pop()
{
    top--;
}
int peek()
{
    return stack[top];
}

int visited[MAX] = {0};
void dfsRec(int v)
{
    visited[v] = 1;
    printf("%c\t", v + 'A');
    for (int w = 0; w < n; w++)
    {
        if (graph[v][w] == 1)
        {
            if (visited[w] == 0)
            {
                dfsRec(w);
            }
        } 
    }
}

int main(void)
{
    readGraph();
    // showGraph();
    dfsRec(0);
    return 0;
}