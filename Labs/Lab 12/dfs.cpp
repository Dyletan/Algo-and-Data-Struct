#include <iostream>
#include <vector>
using namespace std;

const int N = 1e4;
vector<int> g[N];
bool was[N] = {false};

void dfs(int v){
    was[v] = true;
    for(int u : g[v]){
        if(!was[u]){
            dfs(u);
        }
    }
}


void dfs(int v, int n){
    was[v] = true;
    for(int u = 0; u < n; ++u){
        if(g[v][u] == 1 && !was[u+1]){
            dfs(u, n);
        }
    }
}