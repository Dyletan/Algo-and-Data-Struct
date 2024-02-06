#include <iostream>
#include <vector>

using namespace std;

void dfs(int current, int size, const vector<vector<int>> &matrix, vector<vector<bool>> &visited) {
    for (int i = 0; i < size; ++i) {
        if (matrix[current][i] == 1 && !visited[current][i]) {
            visited[current][i] = true;
            dfs(i, size, matrix, visited);
        }
    }
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> matrix[i][j];

    for (int query = 0; query < q; ++query) {
        int q1, q2, q3;
        cin >> q1 >> q2 >> q3;

        vector<vector<bool>> visited(n, vector<bool>(n, false));
        --q1;
        --q2;
        --q3;
        dfs(q1, n, matrix, visited);

        cout << (visited[q1][q2] && visited[q1][q3] && visited[q2][q3] ? "YES" : "NO") << "\n";
    }

    return 0;
}
