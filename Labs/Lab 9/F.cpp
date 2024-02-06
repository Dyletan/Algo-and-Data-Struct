#include <iostream>
#include <vector>
using namespace std;

vector<int> kmp(string s2, string s1)
{
    string s = s2 + "#" + s1;
    int m = s.size();
    int p[m] = {0};
    int max = s2.size();
    vector<int> occurences;
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
        if(j == max){
            occurences.push_back(i-2*max+1);
        }
        p[i] = j;
    }
    return occurences;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int m = s1.size()+s2.size()+1;
    vector<int> occurences = kmp(s2, s1);
    cout << occurences.size() << endl;
    for(int i  : occurences){
        cout << i << " ";
    }

}