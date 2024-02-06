#include <iostream>
#include <vector>
using namespace std;

int prefix(string s)
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
    return p[s.size() - 1];
}

string to_lower_first_charachter(string s)
{
    string temp = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (i == 0)
            temp += s[i] + 32;
        else
            temp += s[i];
    }
    return temp;
}

int main()
{
    string str, temp;
    int n;
    vector<string> s;
    cin >> str >> n;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        s.push_back(temp);
        a[i] = prefix(to_lower_first_charachter(temp) + "#" + to_lower_first_charachter(str));
    }

    int max = 1;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
            count = 1;
        }
        else if (a[i] == max)
        {
            count++;
        }
    }

    cout << count << endl;
    if(count == 0){
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] == max)
        {
            cout << s[i] << endl;
        }
    }
}