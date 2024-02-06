#include <iostream>
#include <vector>
using namespace std;

vector<int> prefix(string s)
{
    vector<int> p(s.size(), 0);
    for (int i = 1; i < s.size(); i++)
    {
        int j = p[i - 1];
        while (j > 0 && s[j] != s[i])
        {
            j = p[j - 1];
        }
        if (s[i] == s[j])
        {
            j++;
        }
        p[i] = j;
    }
    return p;
}

bool kmp(string s, string pattern)
{
    s = pattern + '#' + s;
    vector<int> p = prefix(s);
    for (int i = 0; i < s.size(); i++)
    {
        if (p[i] == pattern.size())
            return true;
    }
    return false;
}

int main()
{
    string s, pattern;
    cin >> s >> pattern;

    int cnt = 1;

    string tmp = s;
    while (s.size() < pattern.size())
    {
        s += tmp;
        cnt++;
    }
    if (kmp(s, pattern))
    {
        cout << cnt;
    }
    else if (kmp(s + tmp, pattern))
    {
        cout << cnt + 1;
    }
    else
        cout << -1;
    return 0;
}