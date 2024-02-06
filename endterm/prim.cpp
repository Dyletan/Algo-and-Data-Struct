#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

const int N = int(1e5) + 7;

int n, m;
vector<pii> adj[N];
vector<pii> mst_edges;
bool visited[N];

void make_graph(){
    for(int i = 1; i <= m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        // undirected graph
        adj[a].push_back({w, b});
        adj[b].push_back({w, a});
    }
}

int prim(int start){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});
    int mst_sum = 0;
    while(!pq.empty()){
        int w = pq.top().first;
        int v = pq.top().second;
        pq.pop();
        if(!visited[v]){
            visited[v] = true;
            // adding the weight beacuse the weights are automatically sorted ASC
            mst_sum += w;
            for(auto u : adj[v]){ // for every neighbour with it's weight
                if(!visited[u.second]){
                    pq.push(u);

                    mst_edges.push_back({v, u.second});
                }
            }
        }
    }
    return mst_sum;
}

int main(){
    cin >> n >> m;
    make_graph();
    cout << "weight of mst: " << prim(1) << endl;
}
