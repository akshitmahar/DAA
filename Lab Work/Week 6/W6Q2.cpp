#include <iostream>
#include <queue>
#define V 100
 
using namespace std;
 
bool isBipartite(int G[][V], int src)
{
    int colorArr[V];
    for (int i = 0; i < V; ++i)
        colorArr[i] = -1;
    colorArr[src] = 1;
 
    queue <int> q;
    q.push(src);
 
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
 
        if (G[u][u] == 1)
        return false;
        for (int v = 0; v < V; ++v)
        {
            if (G[u][v] && colorArr[v] == -1)
            {
                colorArr[v] = 1 - colorArr[u];
                q.push(v);
            }
 
            else if (G[u][v] && colorArr[v] == colorArr[u])
                return false;
        }
    }
 
    return true;
}
 
int main()
{
    int n;
    cin>>n;
    int G[V][V];
    for(int i=0;i<=n-1;i++)
    {
        for(int j=0;j<=n-1;j++)
        {
            cin>>G[i][j];
        }
    }
    isBipartite(G, 0) ? cout << "Bipartite" : cout << "Not Bipartite";
    return 0;
}
