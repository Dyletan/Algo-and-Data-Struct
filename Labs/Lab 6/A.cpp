#include <iostream>
#include <vector>
using namespace std;

const int N = (int)1e5 + 7;

bool check(char ch){
    if(ch == 'a' || ch == 'e' ||ch == 'o' ||ch == 'u' ||ch == 'i') return true;
    return false;
}

int partition(char *a, int l, int r)
{
    int p = rand() % (r - l + 1) + l;
    swap(a[p], a[r]);
    int pivot = a[r];

    int i = l;
    for (int j = l; j < r; j++)
    {
        if (a[j] <= pivot)
        {
            swap(a[i], a[j]);
            i++;
        }
    }
    swap(a[i], a[r]);
    return i;
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
    string vow;
    string cons;
    int n; cin >> n;
    char input;
    for(int i = 0; i < n; i++){
        cin >> input;
        if(check(input)){
            vow+=input;
        }else{
            cons += input;
        }
    }
    char a[vow.size()];
    char b[cons.size()];
    for(int i = 0; i < vow.size(); i++){
        a[i] = vow[i];
    }
    for(int i = 0; i < cons.size(); i++){
        b[i] = cons[i];
    }

    qsort(a, 0, vow.size()-1);
    qsort(b, 0, cons.size()-1);
    for(int i = 0; i < vow.size(); i++){
        cout << a[i];
    }
    for(int i = 0; i < cons.size(); i++){
        cout << b[i];
    }
    cout << endl;
}
