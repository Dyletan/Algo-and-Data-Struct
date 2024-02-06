#include <iostream>
using namespace std;

int bin_search(int a[], int n, int k){
    int min_len = n + 1;
    for(int i = 0; i < n; i++){
        int begin = i, end = n, mid;
        while(begin < end){
            mid = begin + (end - begin) / 2;
            // the sum of the subarray from i to j is prefix_sum[j] - prefix_sum[i - 1]
            // (or just prefix_sum[j] if i = 0)
            if(a[mid] - (i > 0 ? a[i - 1] : 0) < k){
                begin = mid + 1;
            }
            else{
                end = mid;
            }
        }
        // if we reached the end there is no such subarray that
        // it's sum is >= k so we break
        if(begin==n){
            break;
        }
        else{
            int cur_min_len = begin - i + 1;
            if(cur_min_len < min_len){
                min_len = cur_min_len;
            }
        }
    }
    return min_len; 
}

int main(){
    int n; cin >> n;
    int k; cin >> k;
    int a[n];
    for(int i=0; i < n; i++){
        cin >> a[i];
        if(i!=0){
            a[i] += a[i-1];
        }
    }
    cout << bin_search(a, n, k);

}
