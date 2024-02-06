#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 2e4; // some number decided by the problem description
vector<bool> was(N, false);
vector<int> g[N]; // adjacency list (array of vectors)
vector<int> pathLength(N, 0); // array to sptore the length of paths

void bfs(int start) {
    queue<int> q;
    was[start] = true;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        cout << "was vertex: " << v << " (Path Length: " << pathLength[v] << ")" << endl;
        q.pop();

        // Get all adjacent vertices of the dequeued vertex
        for (int u : g[v]) {
            if (!was[u]) {
                was[u] = true;
                q.push(u);

                // Update the length of the path to the adjacent vertex
                pathLength[u] = pathLength[v] + 1;
            }
        }
    }
}

int main() {
    int n; // number of vertices
    int m; // number of edges
    cin >> n >> m;

    // Taking in the graph
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!was[i]) {
            bfs(i);
        }
    }

    return 0;
}
