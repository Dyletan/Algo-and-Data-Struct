#include <bits/stdc++.h>
using namespace std;

int summ(int a[], int k){
    int sum = 0;
    for(int i = 0; i < k; i++){
        sum += a[i];
    }
    return sum;
}

pair<int,int> bin_search(int a[], int n, int input){
    int l = 0, r = n-1;
    int mid;
    int sum = 0;
    if(input < a[l]) return {0, 0};
    if(input >= a[r]) {
        sum = summ(a, n);
        return {n, sum};
    }
    while(l<=r){
        mid = (l+r)/2; 
        if(a[mid] > input){
            r = mid-1;
        } else {
            if(a[mid+1] > input) {
                sum = summ(a, mid+1);
                return {mid+1, sum};
            }
            l = mid+1;
        }
    }
}


int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0 ; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    int k; cin >> k;
    int input;
    for(int i = 0; i < k; i++){
        cin >> input;
        pair<int, int> result = bin_search(a, n, input);
        cout << result.first << " " << result.second << endl;
    }

}
