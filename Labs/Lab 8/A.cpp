#include <iostream>
#include <vector>
#include <map>

using namespace std;
int mod = 1e9 + 7;
int p = 11;

string hash_str(string s)
{
    long long hash = 0;
    long long cur_p = 1;
    for (int i = 0; i < s.size(); i++)
    {
        hash += (s[i] - 47) * cur_p % mod;
        hash = hash % mod;
        cur_p = (cur_p * p) % mod;
    }
    return to_string(hash);
}

int main()
{
    int n;
    cin >> n;
    string s;
    map<string, bool> m;
    vector<pair<string, string>> v;

    for (int i = 0; i < n * 2; i++)
    {
        cin >> s;
        m[s] = true;
        v.push_back({s, hash_str(s)});
    }

    int cnt = 0;

    for (int i = 0; i < v.size(); i++)
    {
        if (m[v[i].second])
        {
            cout << "Hash of string \"" << v[i].first << "\" is " << v[i].second << endl;
            cnt++;
        }
        if (cnt == n)
            return 0;
    }
}