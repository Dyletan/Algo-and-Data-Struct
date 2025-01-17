#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dfs (vector <vector <int> > &adj, vector <bool> &visited, vector <bool> &red, int v, int cnt, bool &reached) {
    if (red[v] == true) {
        reached = true;
        return cnt;
    }
    visited[v] = true;
    int res = 2147483647;
    for (int i = 0; i < adj.size(); i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            res = min(dfs(adj, visited, red, i, cnt + 1, reached), res);
        }
    }
    return res;
}

int bfs (vector <vector <int> > &adj, vector <bool> &visited, vector <bool> &red, int v, int cnt, bool &reached) {
    queue <int> q;
    q.push(v);
    visited[v] = true;
    bool found = false;
    int res = 2147483647;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (red[v]) {
            found = true;
            res = min(cnt, res);
        }
        cnt++;
        for (int i = 0; i < (int)adj.size(); i++) {
            if (adj[v][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    if (found)
        return res;
    return -1;
}

void search (vector <vector <int> > &adj, vector <bool> &red, int v) {
    vector <bool> visited(adj.size(), false);
    bool reached = false;
    cout << bfs(adj, visited, red, v, 0, reached) << '\n';
}

int main() {
    int n, m, q; cin >> n >> m >> q;
    vector <vector <int> > adj(n, vector<int> (n, 0));
    vector <bool> red(n, false);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a - 1][b - 1] = 1;
        adj[b - 1][a - 1] = 1;
    }
    while(q--) {
        int i, v; cin >> i >> v;
        if (i == 1)
            red[v - 1] = true;
        else {
            search(adj, red, v - 1);
        }
    }
}