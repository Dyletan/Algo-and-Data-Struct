#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1e4; // some number decided by the problem description
vector<bool> was(N, false);
vector<int> g[N]; // adjacency list (array of vectors)
vector<int> sorted; // vector to store the topological order

void dfs(int v){
    was[v] = true;
    for(int u : g[v]){
        if(!was[u]){
            dfs(u);
        }
    }
    sorted.push_back(v);
}

void topsort(int n) {
    for (int i = 1; i <= n; ++i) {
        if (!was[i]) {
            dfs(i);
        }
    }
    reverse(sorted.begin(), sorted.end());
}

int main() {
    int n; // number of vertices
    int m; // number of edges
    cin >> n >> m;

    // Taking in the graph
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        // Assuming a directed graph for topological sort
    }

    topsort(n);

    return 0;
}
