#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
const int N = int(1e5)+7;

int n, m;
vector<pair<int, pii>> edges;
int par[N], sz[N];

// to divide each vertice into it's component
void make_set(){
    for(int i = 1; i <=n; i++){
        par[i] = i; // it is a parent of it's component
        sz[i] = 1;
    }
}

// to find head of component
int find(int a){
    if(a == par[a]){
        return a; // this is a head
    }
    int par_a = find(par[a]);
    // now we set the the parent of current node to head
    par[a] = par_a;
    return par_a;
}

void unite(int a, int b){
    // get both heads of the components
    a = find(a);
    b = find(b);
    if(a == b){
        return;
    }
    if(sz[b] > sz[a]){
        swap(a, b);
    }
    // merge a to b
    par[b] = a;
    sz[a] += sz[b];
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int w, a, b;
        cin >> w >> a >> b;
        edges.push_back({w, {a, b}});
    }
    make_set();
    sort(edges.begin(), edges.end());
    vector<pii> mst;
    int mst_sum = 0;
    for(auto [w, e] : edges){
        if(find(e.first) != find(e.second)){
            mst.push_back(e);
            mst_sum += w;
            unite(e.first, e.second);
        }
    }
    cout << "weight of mst: " << mst_sum << endl;
    for(auto [a, b] : mst){
        cout << a << " " << b << endl;
    } 
}
