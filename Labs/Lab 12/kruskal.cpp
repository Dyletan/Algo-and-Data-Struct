#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

vector<pair<int, pii>> edges; 

const int N = 1e4;
int n, m;
int par[N], sz[N];

void make_set(){
    for(int i = 1; i<=n;i++){
        par[i]=i;
        sz[i]=1;
    }
}

int find(int a){
    if(a == par[a]) return a;
    int pa = find(par[a]);
    par[a] = pa;
    return pa;
}

void unite(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return;
    if(sz[b] > sz[a]){
        swap(a, b);
    }
    par[b] = a;
    sz[a] += sz[b];
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        edges.push_back({w, {a, b}});
    }
    make_set();
    vector<pii> mst;
    int mst_sum = 0;
    sort(edges.begin(), edges.end());
    for(auto [w, e] : edges){
        if(find(e.first) != find(e.second)){
            unite(e.first, e.second);
            mst.push_back(e);
            mst_sum += w;
        }
    }
}