#include <iostream>
using namespace std;

int partition(char *a, int l, int r){
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

void qsort(char *a, int l, int r){
    if(l>=r) return;
    int piv = partition(a, l, r);
    qsort(a, l, piv - 1);
    qsort(a, piv + 1, r);
}

int main(){
    int n;
    cin >> n;
    char a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    qsort(a, 0, n-1);
    char ch;
    cin >> ch;
    for(int i = 0; i < n; i++){
        if(a[i]>ch){
            cout << a[i];
            return 0;
        }
    }
    cout << a[0];
}