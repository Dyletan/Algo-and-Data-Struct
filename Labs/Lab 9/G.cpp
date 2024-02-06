#include <iostream>
#include <vector>
using namespace std;

int kmp(string s)
{
    int n = s.size();
    vector<int> p(n, 0);
    for (int i = 1; i < n; i++)
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
    return p[n-1];
}

int main() {
    string s;
    cin >> s;
    cout << s.size() - kmp(s) << endl;
}