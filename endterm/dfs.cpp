#include <iostream>
#include <vector>
using namespace std;

const int N = 1e4; // some number decided by the problem description
vector<bool> was(N, false);
vector<int> g[N]; // adjacency list (array of vectors)


void dfs(int v){
    was[v] = true;
    for(int u : g[v]){
        if(!was[u]){
            dfs(u);
        }
    }
}

int main()
{
    int n;            // number of vertices
    int m;            // number of edges
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        // in case of undirected graph
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(4);
}