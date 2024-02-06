#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

const int N = int(1e5) + 7;
const int inf = (int)1e9;
int n, m;
vector<pii> g[N];
int d[N], was[N], par[N];

int main()
{
    int st;
    cin >> n >> m >> st;
    for (int i = 1; i <= m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        g[a].push_back({w, b});
        g[b].push_back({w, a});
    }
    for (int i = 1; i <= n; i++)
    {
        d[i] = inf;
    }
    d[st] = 0;
    for (int i = 1; i <= n; i++)
    {
        int v = -1;
        // finds the vertex v with the minimum distance among the unvisited vertices
        for (int j = 1; j <= n; j++)
        {
            if (!was[j] && (v == -1 || d[j] < d[v]))
            {
                v = j;
            }
        }
        // if minimum is infinity then every other vertex is unrichable
        if (d[v] == inf)
            break;
        was[v] = true;
        // do relaxation from vertex v
        // updates the distances and parent vertices for the
        // neighboring vertices of v if a shorter path is found.
        for (auto [w, u] : g[v])
        {
            if (d[v] + w < d[u])
            {
                d[u] = d[v] + w;
                par[u] = v;
            }
        }
    }

    for(int i = 1; i <= n; i++){
        cout << "d[" << i << "] = " << (d[i] == inf ? -1 : d[i]) << endl;
    }
}