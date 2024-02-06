#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

// this task is aimed towards solving the 
// problem of finding the index of some element x
// inside the array a[n]
// the fastest way is to implement binary search
// and return the index

const int N = (int)1e5 + 5; // 100005
pii a[N];
int n, m;

int lin_search(int x){
    for(int i = 1; i < n; i++){
        if(a[i].first == x)
            return a[i].second;
    }
    return -1;
}

// gives us the index where the desired x is located
int bin_search(int x){
    if(x < a[1].first || x > a[n].first)
        return -1;

    int l = 1;
    int r = n;
    int res = -1;

    while(l <= r){
        int mid = (l + r)/2;
        if(x <= a[mid].first){
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    // exmaple of how it works
    // x = 20
	//          v
	// a: 10 10 20 20 20 30 30
	/*				 mid
		a: [10 10 20 20 20 30 30] 1-st iteration
		       mid
		a: [10 10 20], res = 4    2-nd iteration
				  mid
		a:       [20], res = 4    3-rd iteration
		       ] [     res = 3
	*/

    if (res == -1 || a[res].first != x)
        return -1;
    return a[res].second;
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i].first);
        a[i].second = i;
    }

    sort(a+1, a+n+1);

    scanf("%d", &m);
    for(int i = 1; i <= m; i++){
        int x;
        scanf("%d", &x);
        int pos = bin_search(x);
        printf("%d\n", pos);
    }

    return 0;
}