#include <bits/stdc++.h>
using namespace std;

int bin_find_interval(int a[], int l, int n){
    int max = n-1;
    int min = 1;
    int mid = 0;
    if(l<=a[0]) return 1; // works faster this way, other way without it amd min = 0
    while(min<=max){
        mid = (min+max)/2; 
        if(l == a[mid]){
            return mid + 1;
        } else if (l > a[mid]){
            min = mid + 1;
            if(l <= a[mid+1]){
                return mid+2;
            }
        } else {
            max = mid-1;
        }
    }
    return mid+1;
}

int main(){
    int b, m;
    cin >> b >> m;
    int a[b];
    int sum = 0;
    for(int i = 0; i < b; i++){
        cin >> a[i];
        if(i!=0){
            sum = a[i-1]+a[i];
            a[i] = sum;
        }
    }

    // for(int i = 0; i < b; i++){
    //     cout << a[i] << " ";
    // }
    int l; 
    for(int i = 0; i < m; i++){
        cin >> l;
        cout << bin_find_interval(a, l, b) << endl;
    }

}