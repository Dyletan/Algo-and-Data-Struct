#include <iostream>
#include <vector>
using namespace std;

vector<int> merge(int *a, int n, int *b, int m){
    vector<int> c;
    int i = 0, j = 0;
    while(i < n || j < m){
        if(i == n){
            c.push_back(b[j++]);
        } else if(j == m){
            c.push_back(a[i++]);
        } else if(a[i] < b[j]){
            c.push_back(a[i++]);
        } else{
            c.push_back(b[j++]);
        } 
    }
    return c;

}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int m;
    cin >> m;
    int b[m];
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    vector<int> c = merge(a, n, b, m);
    for(int i = 0; i < c.size(); i++){
        cout << c[i] << " ";
    }
}