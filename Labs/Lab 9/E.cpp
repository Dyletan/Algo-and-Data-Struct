#include <iostream>
using namespace std;

int kmp(string s)
{
    int m = s.size();
    int p[m] = {0};
    for (int i = 1; i < m; ++i)
    {
        int j = p[i - 1];
        while (j > 0 && s[j] != s[i])
        {
            j = p[j - 1];
        }
        if (s[j] == s[i])
        {
            j++;
        }
        p[i] = j;
    }
    return p[m - 1];
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string s;
        int k;
        cin >> s >> k;
        int m = s.size();
        int overlap = kmp(s);
        cout << m + (m - overlap) * (k - 1) << endl;
    }
}