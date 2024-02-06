#include <iostream>
#include <vector>

using namespace std;

const int N = 1e4;
vector<int> g[N];
bool was[N] = {false};
bool hasCycle = false;

void dfs(int v, int parent) {
    was[v] = true;

    for (int u : g[v]) {
        if (!was[u]) {
            dfs(u, v);
        } else if (u != parent) {
            // If u is already visited and not the parent of the current vertex, a cycle is found
            hasCycle = true;
            return;
        }
    }
}