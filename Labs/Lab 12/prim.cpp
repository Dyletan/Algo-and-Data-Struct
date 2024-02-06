#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

const int N = 1e4;

vector<pii> g[N];
bool was[N];
int mst_sum = 0;
vector<pii> mst;


void prim(int st){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, st});
    while(!pq.empty()){
        int w = pq.top().first;
        int v = pq.top().second;
        pq.pop();
        if(!was[v]){
            was[v] = true;
            mst_sum += w;
            for(pii u : g[v]){
                if(!was[u.second]){
                    pq.push(u);
                    mst.push_back({v, u.second});
                }
            }
        }
    }
}