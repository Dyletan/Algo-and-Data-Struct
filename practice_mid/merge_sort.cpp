#include <iostream>
#include <vector>
using namespace std;

void merge(int *a, int n, int *b, int m){
    vector<int> c;
    int i = 0, j =0;
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
    for(int i = 0; i < m+n; i++){
        a[i] = c[i];
    }
}

void merge_sort(int *a, int n){
    if(n == 1) return;
    merge_sort(a, n/2);
    merge_sort(a+n/2, n-n/2);
    merge(a, n/2, a+n/2, n-n/2);
}