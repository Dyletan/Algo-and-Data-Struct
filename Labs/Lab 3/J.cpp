#include <bits/stdc++.h>
using namespace std;

int maxx(int a[], int n){
    int max = -999;
    for(int i = 0; i < n; i++){
        if(a[i]>max){
            max = a[i];
        }
    }
    return max;
}

bool willFit(int a[], int n, int h, int mid){
    int hours = 0;
    for(int i = 0; i <n; i++){
        hours += ceil(double(a[i])/mid);
    }
    return hours <=h;
}

int minBag(int a[], int n, int h){
    int min = 1;
    int max = maxx(a, n);
    int mid;
    while(min<max){
        mid = (min+max)/2;
        if(willFit(a, n, h, mid)){
            if(!willFit(a, n, h, mid+1)){
                return max;
            }
            max = mid;
        }
        else{
            min = mid + 1;
        }
    }
    return max;
}

int main(){
    int n, h;
    cin >> n >> h;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << minBag(a, n, h);
}