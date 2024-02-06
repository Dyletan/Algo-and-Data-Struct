#include <bits/stdc++.h>
using namespace std;
// Max is the max number of children
// Min is 1

int maxx(int a[], int n)
{
    int max = -999;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    return max;
}

bool possibleToDeliever(int a[], int n, int mid, int k)
{
    int numOfFlights = 0;
    for (int i = 0; i < n; i++)
    {
        numOfFlights += ceil(double(a[i]) / mid);
    }
    return numOfFlights <= k;
}

int bin_iterataion(int a[], int n, int k)
{
    int max = maxx(a, n);
    int min = 1;
    int mid;
    while (min < max)
    {
        mid = (max + min) / 2;
        if (possibleToDeliever(a, n, mid, k))
        {
            max = mid;
        }
        else
        {
            min = mid + 1;
        }
        // cout << "max: " << max << " min: " << min << endl;
    }
    return max;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << bin_iterataion(a, n, k);
}
