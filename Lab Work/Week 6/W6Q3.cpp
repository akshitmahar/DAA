#include<iostream>
#include<set>
#define NODE 5
using namespace std;

int graph[NODE][NODE] ;

bool dfs(int vertex, set<int>&visited, int parent) {
   visited.insert(vertex);
   for(int v = 0; v<NODE; v++) {
      if(graph[vertex][v]) {
         if(v == parent)    //if v is the parent not move that direction
            continue;
         if(visited.find(v) != visited.end())    //if v is already visited
            return true;
         if(dfs(v, visited, vertex))
            return true;
      }
   }
   return false;
}

bool hasCycle() {
   set<int> visited;       //visited set
   for(int v = 0; v<NODE; v++) {
      if(visited.find(v) != visited.end())    //when visited holds v, jump to next iteration
         continue;
      if(dfs(v, visited, -1)) {    //-1 as no parent of starting vertex
         return true;
      }
   }
   return false;
}

int main() {
    int n;
    cin>>n;
    for(int i=0;i<=n-1;i++)
    {
        for(int j=0;j<=n-1;j++)
        {
            cin>>graph[i][j];
        }
    }
    bool res;
    res = hasCycle();
    if(res)
        cout << "The graph has cycle." << endl;
    else
        cout << "The graph has no cycle." << endl;
    return 0;
}
