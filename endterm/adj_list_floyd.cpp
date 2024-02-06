#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

void floydWarshall(vector<vector<pair<int, int>>>& adjList) {
    int n = adjList.size();

    // Initialize distance matrix with direct edge weights
    vector<vector<int>> dist(n, vector<int>(n, INF));

    for (int i = 0; i < n; ++i) {
        dist[i][i] = 0;
        for (const auto& neighbor : adjList[i]) {
            int v = neighbor.first;
            int w = neighbor.second;
            dist[i][v] = w;
        }
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
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

    vector<vector<pair<int, int>>> adjList(n);

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].emplace_back(v, w);
    }

    floydWarshall(adjList);

    return 0;
}
