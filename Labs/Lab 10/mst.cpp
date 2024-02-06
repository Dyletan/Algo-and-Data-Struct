#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> pii;
const int N = (int)1e5 + 7;
// const int inf = (int)1e9;
int n, m;
vector<pair<int, pii>> edges;
int par[N], sz[N];

void make_set()
{
    for (int i = 1; i <= n; i++)
    {
        par[i] = i;
        sz[i] = 1;
    }
}

int find(int a)
{
    if (a == par[a])
        return a;
    int pa = find(par[a]);
    par[a] = pa;
    return pa;
}

void unite(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b)
    {
        return;
    }
    if (sz[b] > sz[a])
    {
        swap(a, b);
    }
    par[b] = a;
    sz[a] += sz[b];
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        edges.push_back(make_pair(w, make_pair(a, b)));
    }

    make_set();
    sort(edges.begin(), edges.end());

    vector<pii> mst;
    int mst_sum = 0;
    for (auto [w, e] : edges)
    { 
        // w-weight of edge
        // e- pair of vertices edge connects if (find(e.first) != find (e.second)) { mst.push_back(e);
        if (find(e.first) != find(e.second))
        {   
            mst.push_back(e);
            mst_sum += w;
            unite(e.first, e.second);
        }
        cout << mst_sum << "\n";
        for (auto [a, b] : mst)
        {
            cout << a << ' ' << b << "\n";
        }
        return 0;
    }
   
}