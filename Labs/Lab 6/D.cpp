#include <iostream>
#include <iomanip>
using namespace std;

int partition(long long *a, int l, int r)
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

void quicksort(long long *a, int l, int r)
{
    if (l >= r)
        return;
    int piv = partition(a, l, r);
    quicksort(a, l, piv - 1);
    quicksort(a, piv + 1, r);
}

int main()
{
    int n;
    string str;
    cin >> n;
    int a[n][3];
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        string day;
        string month;
        string year;

        day += str[0];
        day += str[1];

        month += str[3];
        month += str[4];

        year += str[6];
        year += str[7];
        year += str[8];
        year += str[9];

        a[i][0] = stoi(day);
        a[i][1] = stoi(month);
        a[i][2] = stoi(year);
    }
    long long b[n];
    for(int i = 0; i < n; i++){
        b[i]=a[i][2]*10000+a[i][1]*100+a[i][0];
    }
    quicksort(b, 0, n-1);
    for (int i = 0; i < n; i++)
    {
        cout << setfill('0') <<  setw(2) << b[i]%100 << "-" << setw(2) << b[i]%10000/100 << "-" <<  b[i]/10000<< endl ;
    }
}