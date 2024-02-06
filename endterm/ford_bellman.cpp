#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

int n, m;
vector<pair<int, pair<int, int>>> edges(m);

void bellmanFord(int start) {
    vector<int> distance(n, INF);
    distance[start] = 0;

    // Relax all edges |V| - 1 times
    for (int i = 0; i < n - 1; ++i) {
        for (auto edge : edges) {
            int u = edge.second.first;
            int v = edge.second.second;
            int w = edge.first;

            if (distance[u] != INF && distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
            }
        }
    }

    // Check for negative-weight cycles
    for (auto edge : edges) {
        int u = edge.second.first;
        int v = edge.second.second;
        int w = edge.first;

        if (distance[u] != INF && distance[u] + w < distance[v]) {
            cout << "Graph contains negative-weight cycle!" << endl;
            return;
        }
    }

    // Print the shortest distances
    for (int i = 0; i < n; ++i) {
        cout << i << ": " << distance[i] << endl;
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int w, a, b;
        cin >> w >> a >> b;
        edges[i] = {w, {a, b}};
    }

    int start;
    cin >> start;

    bellmanFord(start);

    return 0;
}
