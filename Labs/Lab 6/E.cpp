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
        if(a[i]>piv){
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
    int n, m;
    cin >> n >> m;
    int a[m][n];

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> a[j][i];
        }
    }

    for(int i = 0; i < m; i++){
        qsort(a[i], 0, n-1);
    }

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cout << a[j][i] << " ";
        }
        cout << endl;
    }

    return 0;
}