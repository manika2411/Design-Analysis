#include <iostream>
using namespace std;
const int MAX = 10; 
int graph[MAX][MAX];
int color[MAX];
bool isSafe(int V, int v, int c) 
{
    for (int i = 0; i < V; i++) 
	{
        if (graph[v][i] == 1 && color[i] == c) 
		{
            return false;
        }
    }
    return true;
}
bool graphColoringUtil(int V, int m, int v) 
{
    if (v == V) 
	{
        return true;
    }
    for (int c = 1; c <= m; c++) 
	{
        if (isSafe(V, v, c)) 
		{
            color[v] = c;
            if (graphColoringUtil(V, m, v + 1)) 
			{
                return true;
            }
            color[v] = 0; 
        }
    }
    return false;
}
bool graphColoring(int V, int m) 
{
    for (int i = 0; i < V; i++) color[i] = 0;
    if (!graphColoringUtil(V, m, 0)) 
	{
        cout << "Output: Solution does not exist\n";
        return false;
    }
    cout << "Output: Solution Exists: \nFollowing are the assigned colors: ";
    for (int i = 0; i < V; i++) {
        cout << color[i] << " ";
    }
    cout << endl;
    return true;
}
int main() 
{
    int V;
    cout<<"enter number of vertices:";
    cin>>V;
    int m;
    cout<<"enter maximum colors allowed:";
    cin>>m;
    int g1[V][V] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };
    for (int i = 0; i < V; i++)
    {
    	for (int j = 0; j < V; j++)
        {
        	graph[i][j] = g1[i][j];
		}  
	}  
    graphColoring(V, m);
    return 0;
}

