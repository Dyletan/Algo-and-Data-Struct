#include <iostream>
using namespace std;

int partition(int *a, int l, int r){
    int p = rand() % (r-l+1)+l;
    swap(a[p],a[r]);
    int piv = a[r];
    int j = l;
    for(int i = l; i < r; i++){
        if(a[i]<=piv){
            swap(a[j], a[i]);
            j++;
        }
    }
    swap(a[j], a[r]);
    return j;
}

void qsort(int *a, int l, int r){
    if(l>=r) return;
    int piv = partition(a, l, r);
    qsort(a, l, piv-1);
    qsort(a, piv+1, r);
}