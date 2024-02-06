#include <iostream>
using namespace std;

bool check(pair<long long, long long> a[], int n, int mid, int k){
    int cur_k = 0;
    for(int i = 0; i < n; i++){
        if(a[i].first <= mid && a[i].second <= mid){
            cur_k++;
        }
    }
    return cur_k >= k;
}

int main()
{
    long long n;
    cin >> n;
    long long k;
    cin >> k;
    long long x1, y1, x2, y2;
    long long min = 10e9 + 1, max = -1;
    pair<long long, long long> a[n];

    for(long long i = 0; i < n; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        a[i] = {x2, y2};
        if(x2 < min){
            min = x2;
        }
        if(y2 < min){
            min = y2;
        }
        if(x2 > max){
            max = x2;
        }
        if(y2 > max){
            max = y2;
        }
    }
    int result;
    while(min<=max){
        long long mid = (max+min)/2; 
        if(check(a, n, mid, k)){
            result = mid;
            max = mid-1;
        }
        else{
            min = mid+1;
        }
    }
    cout << result;
}