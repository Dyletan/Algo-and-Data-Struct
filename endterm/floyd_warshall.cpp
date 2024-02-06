#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

void floydWarshall(vector<vector<int>>& graph) {
    int n = graph.size();

    // Create a separate matrix to store distances
    vector<vector<int>> dist = graph;

    // Floyd-Warshall algorithm
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                // Update dist[i][j] only if it is beneficial
                dist[i][j] = (dist[i][k] != INF && dist[k][j] != INF) ? min(dist[i][j], dist[i][k] + dist[k][j]) : dist[i][j];

            }
        }
    }

    // Print the shortest distances
    cout << "Shortest distances between all pairs of vertices:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n, vector<int>(n, INF));

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
    }

    floydWarshall(graph);
}
