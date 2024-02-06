#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 7; // Number of vertices
vector<vector<int>> g(N); // Adjacency list (array of vectors)
vector<bool> visited(N, false);
vector<int> topologicalOrder;

void dfs(int v) {
    visited[v] = true;
    for (int u : g[v]) {
        if (!visited[u]) {
            dfs(u);
        }
    }
    topologicalOrder.push_back(v);
}

void topologicalSort() {
    for (int i = 0; i < N; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    reverse(topologicalOrder.begin(), topologicalOrder.end());
}

int main() {
    // Constructing a directed acyclic graph
    g[0+1].push_back(1+1);
    g[0+1].push_back(2+1);
    g[1+1].push_back(3+1);
    g[2+1].push_back(3+1);
    g[2+1].push_back(4+1);
    g[3+1].push_back(5+1);

    cout << "Graph before topological sort:" << endl;
    for (int i = 1; i < N; ++i) {
        cout << i << ": ";
        for (int u : g[i]) {
            cout << u << " ";
        }
        cout << endl;
    }

    topologicalSort();

    cout << "\nTopological Order:" << endl;
    for (int v : topologicalOrder) {
        cout << v << " ";
    }

    return 0;
}
