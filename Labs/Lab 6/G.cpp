#include <iostream>
#include <vector>
using namespace std;

int partition(vector<pair<string, string>> &v, int l, int r)
{
    int j = l;
    pair<string, string> piv = v[r];
    for (int i = l; i < r; i++)
    {   
        if (v[i].first < piv.first)
        {
            swap(v[i], v[j]);
            j++;
        }
    }
    swap(v[j], v[r]);
    return j;
}

void qsort(vector<pair<string, string>> &v, int l, int r)
{
    if (l >= r) return;
    int piv = partition(v, l, r);
    qsort(v, l, piv - 1);
    qsort(v, piv + 1, r);
}

int main()
{
    int n;
    cin >> n;
    vector<pair<string, string>> v;
    while (n--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        bool connect = false;
        for (int i = 0; i < v.size(); i++)
        {
            // Aslan Nurbol
            // Nurbol HackMachine
            if (s1 == v[i].second)
            {
                v[i].second = s2;
                connect = true;
            }
        }
        if (!connect)
        {
            v.push_back(make_pair(s1, s2));
        }
    }

    qsort(v, 0, v.size() - 1);
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].first << ' ' << v[i].second << endl;
    }
}