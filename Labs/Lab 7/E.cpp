#include <bits/stdc++.h>
using namespace std;

int sum(vector<int> &v)
{
    int sum = 0;
    for (int i = 0; i < v.size(); i++)
        sum += v[i];
    return sum;
}

bool comp(vector<int> &v, vector<int> &v1)
{
    int s1 = sum(v);
    int s2 = sum(v1);
    if (s1 == s2)
    {
        for (int i = 0; i < v1.size(); i++)
        {
            if (v[i] > v1[i])
                return true;
            else if (v[i] < v1[i])
                return false;
        }
    }
    return s1 < s2;
}

vector<vector<int>> merge(vector<vector<int>> l, int n, vector<vector<int>> r, int m)
{
    vector<vector<int>> c;
    int i = 0, j = 0;
    while (i < n && j < m)
    {   
        if (comp(r[j], l[i]))
        {
            c.push_back(l[i++]);
        }
        else
        {
            c.push_back(r[j++]);
        }
    }
    while(i < n){
        c.push_back(l[i++]);
    }
    while(j < m){
        c.push_back(r[j++]);
    }
    return c;
}

vector<vector<int>> msort(vector<vector<int>> &a, int n)
{
    if (n == 1)
        return a;
    vector<vector<int>> al, ar;
    for (int i = 0; i < n / 2; i++)
    {
        al.push_back(a[i]);
    }
    for (int i = n / 2; i < n; i++)
    {
        ar.push_back(a[i]);
    }
    al = msort(al, al.size());
    ar = msort(ar, ar.size());
    return merge(al, al.size(), ar, ar.size());
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v;
    for (int i = 0; i < n; i++)
    {
        vector<int> tmp(m);
        for (int j = 0; j < m; j++)
            cin >> tmp[j];
        v.push_back(tmp);
    }

    v = msort(v, v.size());
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << v[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}