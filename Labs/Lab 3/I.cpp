#include <iostream>
using namespace std;

bool binary_search (int a[], int k, int n){
    int l = 0;
    int r = n-1;
    if(k<a[l] || k>a[r]) return false;

    while(l <= r){
        int mid = (l + r)/2;
        if(a[mid] == k){
            return true;
        } else if(a[mid]>k){
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return false;
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int k; cin >> k;
    binary_search(a, k, n) ? cout << "Yes" : cout << "No";

}