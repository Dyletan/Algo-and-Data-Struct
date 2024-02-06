#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 1e4;
vector<int> g[N];
bool was[N] = {false};
int path_len[N];

void bfs(int st){
    queue<int> q;
    q.push(st);
    was[st] = true;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int u : g[v]){
            if(!was[u]){
                was[u] = true;
                q.push(u);
                path_len[u] = path_len[v]+1; 
            }
        }
    }
}

void bfs(int st, int n){
    queue<int> q;
    q.push(st);
    was[st] = true;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int u = 0; u < n; u++){
            if(!was[u] && g[v][u] == 1){
                was[u] = true;
                q.push(u);
                path_len[u] = path_len[v]+1;
            }
        }
    }
}