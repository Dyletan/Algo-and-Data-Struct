#include <iostream>
using namespace std;

int p = 11;

int hash_str(string s)
{
    int h = 0;
    for (int i = 0; i < s.size(); i++)
    {
        h = h * p + s[i];
    }
    return h;
}

int main()
{
    // am
    string s1, s2, parasite;
    cin >> s1 >> s2 >> parasite;

    int m = parasite.size();
    int n = max(s1.size(), s2.size());

    int h1 = hash_str(s1.substr(0, m));
    int h2 = hash_str(s2.substr(0, m));
    int p_hash = hash_str(parasite);

    int pm = 1;
    for (int i = 0; i < m - 1; i++)
    {
        pm = pm * p;
    }

    int cnt = 0;
    
    for (int i = 0; i + m <= n; i++)
    {
        if (h1 == p_hash && h2 == p_hash)
        {
            cnt++;
        }
        if (i + m < n){
            h1 = (h1-s1[i] * pm)*p + s1[i+m];
            h2 = (h2-s2[i] * pm)*p + s2[i+m];
        }
    }
    cout << cnt;
}