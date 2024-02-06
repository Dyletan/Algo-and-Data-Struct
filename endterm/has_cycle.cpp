#include <iostream>
#include <vector>
using namespace std;

const int N = 1e4;
vector<bool> was(N, false);
vector<int> g[N]; // adjacency list (array of vectors)

bool dfs(int v, int parent) {
    was[v] = true;

    for (int u : g[v]) {
        if (!was[u]) {
            dfs(u, v);
        } else if (parent != u) {
            // If u is was and not the parent of v, there is a cycle
           return true;
        }
    }
    return false;
}