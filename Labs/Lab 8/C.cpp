#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long long ull;

const int p = 31;
vector<pair<int, int>> occurences;

ull power(int p, int m)
{
    ull result = 1;
    for (int i = 0; i < m; i++)
        result *= p;
    return result;
}

ull my_hash(const string str)
{
    ull h = 0;
    for (char ch : str)
    {
        h = h * p + ch;
    }
    return h;
}

int rabin_karp(string pattern, string text)
{
    int m = pattern.length();
    int n = text.length();

    ull hp = my_hash(pattern);
    ull h = my_hash(text.substr(0, m));
    ull pm = power(p, m);

    for (int i = 0; i <= n - m; i++)
    {
        if (hp == h)
        {
            occurences.push_back({i, i + m});
        }
        if (i < n - m)
        {
            h = h * p + text[i + m] - text[i] * pm;
        }
    }
}

int main()
{
    int input;
    string tape, temp;
    vector<string> patterns;
    
    cin >> tape >> input;
    int n = tape.size();
    bool a[n] = {false};

    for (int i = 0; i < input; i++)
    {
        cin >> temp;
        patterns.push_back(temp);
    }

    for (string pattern : patterns)
    {
        rabin_karp(pattern, tape);
    }

    for (pair<int, int> p : occurences)
    {
        for (int i = p.first; i < p.second; i++)
        {
            a[i] = true;
        }
    }

    for (bool b : a)
    {
        if (b == false)
        {
            cout << "NO";
            return 0;
        }
    
    }
    cout << "YES";
}