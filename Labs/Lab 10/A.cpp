#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>>& v, queue<pair<int, int>>& q, int n, int m) {
    while (!q.empty()) {
        int size = q.size();
        for (int k = 0; k < size; k++) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for (int dif = -1; dif <= 1; dif++) {
                if (i + dif >= 0 && i + dif <= n - 1 && v[i + dif][j] == 1) {
                    v[i + dif][j] = 2;
                    q.push(make_pair(i + dif, j));
                }

                if (j + dif >= 0 && j + dif <= m - 1 && v[i][j + dif] == 1) {
                    v[i][j + dif] = 2;
                    q.push(make_pair(i, j + dif));
                }
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> v;
    queue<pair<int, int>> q;
    int number;
    for (int i = 0; i < n; i++) {
        vector<int> row;
        for (int j = 0; j < m; j++) {
            cin >> number;
            row.push_back(number);
            if (number == 2) {
                q.push(make_pair(i, j));
            }
        }
        v.push_back(row);
    }

    int count = 0;
    bfs(v, q, n, m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == 1) {
                cout << -1;
                return 0;
            }
        }
    }
    if (count == 0) {
        cout << 0;
    } else {
        cout << count - 1;
    }

    return 0;
}

