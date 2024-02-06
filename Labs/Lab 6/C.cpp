#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int partition(int *a, int l, int r){
    int p = rand() % (r-l+1)+l;
    swap(a[r], a[p]);
    int piv = a[r];
    int j = l - 1;
    for(int i = l; i < r; i++){
        if(a[i]<piv){
            j++;
            swap(a[j], a[i]);
        }
    }
    j++;
    swap(a[r], a[j]);
    return j;
}

void qsort(int *a, int l, int r){
    if(l>=r) return;
    int piv = partition(a, l, r);
    qsort(a, l, piv - 1);
    qsort(a, piv + 1, r);
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    qsort(a, 0, n-1);

    int min_diff = 10e6;
    vector<pair<int, int>> b;
    for(int i = 0; i < n; i++){
        if(i==n-1) continue;
        if(abs(a[i+1]-a[i]) == min_diff){
            b.push_back({a[i], a[i+1]}); 
        }
        else if(abs(a[i+1]-a[i]) < min_diff){
            min_diff = abs(a[i+1]-a[i]);
            b.clear();
            pair<int, int> p = make_pair(a[i], a[i+1]);
            b.push_back(p); 
        }
    }
    for(int i = 0; i < b.size(); i++){
        cout << b[i].first << " " << b[i].second << " ";
    }

}
