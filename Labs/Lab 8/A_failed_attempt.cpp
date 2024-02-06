#include <iostream>
#include <vector>
using namespace std;

int p = 11;
int mod = 1e9 + 7;

long long hash_str(string s)
{
    long long h = 0;
    long long p_pow = 1;
    for (int i = 0; i < s.size(); i++)
    {
        h += (s[i] - 47) * p_pow % mod;
        h = h%mod;
        p_pow = p_pow * p % mod; // p^i
    }
    return h;
}

int main()
{
    int n;
    cin >> n;
    vector<string> v;
    vector<bool> skip(2*n);
    for (int i = 0; i < n * 2; i++)
    {
        string s;
        cin >> s;
        v.push_back(s);
    }
    int count = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (!skip[i])
        {
            if(count == n){
                break;
            }
            string h = to_string(hash_str(v[i]));
            for (int j = 0; j < v.size(); j++)
            {
                if (!skip[j])
                {
                    if (v[j] == h && j != i)
                    {
                        skip[j] = true;
                        cout << "Hash of string \"" << v[i] << "\" is " << h << endl;
                        count++;
                        break;
                    }
                }
            }
        }
    }
}