#include <iostream>
#include <vector>
using namespace std;

const int N = 2e4; // some number decided by the problem description
vector<bool> was(N, false);
vector<int> g[N]; // adjacency list (array of vectors)

void dfs(int v, vector<int> &comp)
{
    was[v] = true;
    comp.push_back(v);
    for (int u : g[v])
    {
        if (!was[u])
        {
            dfs(u, comp);
        }
    }
}

int main()
{
    
    int n;            // number of vertices
    int m;            // number of edges
    cin >> n >> m;
    // taking in the graph
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        // in case of undirected graph
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<vector<int>> comps;
    // finding components
    for (int v = 1; v <= n; v++)
    {
        if (!was[v])
        {
            // new component found
            vector<int> comp;
            dfs(v, comp);
            comps.push_back(comp);
        }
    }
    
    for(vector<int> comp : comps){
        for(int v : comp){
            cout << v << " ";
        }
        cout << endl;
    }
}