#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N = 100; 
vector<vector<int>> adjMatrix(N, vector<int>(N));

vector<int> bfs(int n, int st) { 
    vector<bool> was(n, false); 
    vector<int> longestPath(n); 
    queue<int> q;

    q.push(st);
    was[st] = true;

    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        for (int u = 0; u < n; u++)
        {
            if (adjMatrix[v][u] == 1 && !was[u])
            {
                longestPath[u] = longestPath[v] + 1;
                was[u] = true;
                q.push(u);
            }
        }
    }
    return longestPath;
}

int main() { 
    int n; 
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> adjMatrix[i][j];
        }
    }
    int st, end;
    cin >> st >> end;

    vector<int> longestPath = bfs(n, st-1);
    if(longestPath[end-1] == 0){
        cout << -1;
        return 0;
    }
    cout << longestPath[end-1];
}
