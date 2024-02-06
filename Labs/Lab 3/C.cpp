#include <iostream>
#include <algorithm>
using namespace std;

// find the number on position a[mid] that is the closest number that is less or equal to find;
int bin_search(int a[], int min, int max, int find, bool isLeftBoundary){
    int mid;
    while(min <= max){
        mid = (min + max) / 2;
        if(find < a[mid] || (isLeftBoundary && find == a[mid])){
            max = mid - 1;
        } else {
            min = mid + 1;
        }
    }
    return isLeftBoundary ? min : max;
}


int count(int a[], int n, int l1, int r1, int l2, int r2){
    int min = 0;
    int max = n-1;
    int left1, left2, right1, right2;
    // 1 2 3 5 8 13 21
    right1 = bin_search(a, min, max, r1, false);
    left1 = bin_search(a, 0, right1, l1, true);
    right2= bin_search(a, 0, n-1, r2, false);
    left2 = bin_search(a, 0, right2, l2, true);


    int start = std::max(left1, left2);
    int end = std::min(right1, right2);

    int intersection = 0;

    // [0, 2] [1,4]

    if (start <= end) {
        intersection = end - start + 1;
    } 

    return (right1 - left1 + 1) + (right2 - left2+1) - intersection;  
}

int main(){
    int n;
    cin >> n;
    int a[n];
    int q;
    cin >> q;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a+n);

    int l1, r1, l2, r2; 
    for(int i = 0; i < q; i++){
        int sum = 0;
        cin >> l1 >> r1 >> l2 >> r2;
        sum = count(a, n, l1, r1, l2, r2);
        cout << sum << endl;
    }
}