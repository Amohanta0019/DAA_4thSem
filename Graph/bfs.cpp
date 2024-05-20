#include <iostream>
#include <fstream>
using namespace std;

int n;                     // number of vertices
int graph[100][100] = {0}; // graph adjacency matrix

void readGraph()
{
    ifstream input("graph.txt");
    input >> n; // reads number of vertices
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            input >> graph[i][j]; // read matrix
        }
    }
    input.close();
}

// Queue implementation
int queue[100];
int front = -1, rear = -1;

bool isEmpty()
{
    return front == -1;
}

void insert(int element)
{
    if (rear == 99)
    {
        cout << "Queue Overflow" << endl;
        return;
    }
    if (front == -1)
    {
        front = 0;
    }
    rear++;
    queue[rear] = element;
}

void remove()
{
    if (front == -1)
    {
        cout << "Queue Underflow" << endl;
        return;
    }
    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front++;
    }
}

int top()
{
    if (front == -1 || front > rear)
    {
        cout << "Queue is empty" << endl;
        return -1;
    }
    return queue[front];
}

void BFS(int source)
{
    bool visited[n] = {false}; // to track the visited vertices
    insert(source);
    visited[source] = true; // mark as visited

    while (!isEmpty())
    {
        int currNode = top();
        remove();
        cout << char('A' + currNode) << " ";

        for (int i = 0; i < n; i++)
        {
            // edge is available and not visited yet
            if (graph[currNode][i] && !visited[i])
            {
                insert(i);
                visited[i] = true; // mark as visited
            }
        }
    }
}

int main()
{
    readGraph();
    BFS(0); // starting from node 0
    return 0;
}
