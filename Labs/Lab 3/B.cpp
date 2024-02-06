#include <iostream>
#include <algorithm>

using namespace std;

bool canSplit(long long mid, long long a[], long long n, long long k) {
    long long cur_k = 1, cur_sum = 0;
    for (long long i = 0; i < n; i++) {
        cur_sum += a[i];
        if (cur_sum > mid) {
            cur_k += 1;
            cur_sum = a[i];
        }
    }
    return cur_k <= k;
}

int main() {
    long long n, k;
    cin >> n >> k;
    long long a[n], max = 0; 
    for (long long i = 0; i < n; i++) {
        cin >> a[i];
        max += a[i];
    }
    long long min = *max_element(a, a + n);
    long long res = max, mid;
    while( min <= max) {
        mid = (min+max)/2;
        if (canSplit(mid, a, n, k)) {
            res = mid;
            max = mid - 1;
        }
        else {
            min = mid + 1;
        }
    }
    cout << res;
}

// #include <iostream>
// #include <cmath>
// #include <algorithm>
// using namespace std;

// bool check(unsigned long long a[], int n, int k, int mid)
// {
//     long long begin = 0;
//     int cur_k = 1;
//     for (long long i = 0; i < n; i++)
//     {
//         if (a[i] - (begin == 0 ? 0 : a[begin]) > mid)
//         {
//             cur_k++;
//             begin = i-1;
//         }
//     }
//     return cur_k <= k;
// }

// int bin_search(unsigned long long a[], int n, int k, long long min)
// {
//     unsigned long long max = a[n - 1];
//     unsigned long long  mid = 0;
//     unsigned long long result = 0;
//     // 1 2 3 4 5
//     // 1 3 k 6 k 10 k 15
//     while (min <= max)
//     {
//         mid = (max + min) / 2;
//         if (check(a, n, k,  mid))
//         {   
//             result =  mid;
//             max =  mid-1;
//         }
//         else
//         {
//             min =  mid+1;
//         }
//     }
//     return result;
// }

// int main()
// {
//     int n;
//     cin >> n;
//     int k;
//     cin >> k;
//     unsigned long long a[n];
//     long long min;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//         if (a[i] < min)
//         {
//             min = a[i];
//         }

//         if (i != 0)
//         {
//             a[i] += a[i - 1];
//         }
//     }

//     cout << bin_search(a, n, k, min);
// }
