#include <iostream>
#include <vector>
using namespace std;

int find_longest(vector<int> p)
{
    int longest = -1;
    for (int i : p)
    {
        if (i > longest)
        {
            longest = i;
        }
    }
    return longest;
}

int kmp(string s)
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
    return find_longest(p);
}

int main()
{
    string duplicate, sub, str;
    cin >> duplicate >> sub;
    int count = 1;
    while (str.size() <= sub.size()) {
        str += duplicate;
        count++;
    }
    string test = sub + '#' + duplicate;
    if(kmp(test) == sub.size()){
        return count;
    }
    if(kmp(test+duplicate) == sub.size()){
        return count+1;
    }
    cout << -1;
}