#include <iostream>
#include <vector>
using namespace std;

const int N = (int)1e5 + 7;

int partition(char *a, int l, int r)
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

void qsort(char *a, int l, int r)
{
    if (l >= r)
        return;
    int piv = partition(a, l, r);
    qsort(a, l, piv - 1);
    qsort(a, piv + 1, r);
}

int main()
{
    string str;
    getline(cin, str);
    char a[str.size()];
    for(int i = 0; i < str.size(); i++){
        a[i] = str[i];
    }

    qsort(a, 0, str.size()-1);
    for(int i = 0; i < str.size(); i++){
        cout << a[i];
    }
    cout << endl;
}
