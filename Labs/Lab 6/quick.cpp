#include <iostream>
#include <cassert>
#include <algorithm>
#include <vector>
using namespace std;

const int N = (int)1e5 + 7;

// rand() < 2^16
int partition(int *a, int l, int r)
{
    int p = rand() % (r - l + 1) + l;
    swap(a[p], a[r]);
    int pivot = a[r];

    int i = l - 1;
    for (int j = l; j < r; j++)
    {
        if (a[j] <= pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[r]);
    return i + 1;
}

void qsort(int *a, int l, int r)
{
    if (l >= r)
        return;
    int piv = partition(a, l, r);
    qsort(a, l, piv - 1);
    qsort(a, piv + 1, r);
}

int main()
{

    int n = 9;
    int a[n] = {4, 8, 2, 1, 9, 0, 7, 6, 5};

    qsort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';
    cout << "\n";

    return 0;
}
