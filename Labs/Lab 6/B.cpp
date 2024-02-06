#include <iostream>
using namespace std;

int partition(int *a, int l, int r)
{
    int p = rand() % (r - l + 1) + l;
    swap(a[p], a[r]);
    int pivot = a[r];
    int i = l - 1;
    for (int k = l; k < r; k++)
    {
        if (a[k] <= pivot)
        {
            i++;
            swap(a[i], a[k]);
        }
    }
    swap(a[i + 1], a[r]);
    return i + 1;
}

void print(int *a, int n){
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

void quicksort(int *a, int l, int r)
{
    if (l >= r)
        return;
    int piv = partition(a, l, r);
    quicksort(a, l, piv - 1);
    quicksort(a, piv + 1, r);
}

int main()
{
    int n, m;
    cin >> n >> m;
    if(n == 0 || m == 0)return 0;
    int a[n];
    int b[m];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    quicksort(a, 0, n - 1);
    quicksort(b, 0, m - 1);
    int i = 0, j = 0;
    // 1 1 2 2
    // 2 2 
    while(i < n && j < m){
        if(a[i] == b[j]){
            cout << a[i] << ' ';
            i++;
            j++;
        }
        else if(a[i] < b[j])i++;
        else j++;
    }
}
