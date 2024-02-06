#include <iostream>
#include <vector>
using namespace std;

vector<int> kmp(string s)
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
    return p;
}
int main() {
    string s;
    cin >> s;
    vector<int> p = kmp(s);
    int cnt = 0;

    // For each i, it calculates sz (the size of the current substring)
    // and k (the size of the period of the substring).
    // The period of a string is the smallest non-zero length k
    // for which the string can be written as one or more repetitions of another string of length k.

    // It then checks if the period k divides evenly
    // into the size of the substring sz. If it does,
    // and the substring has a non-zero prefix that is a proper suffix
    // (checked by p[i] != 0), the substring is a repeated pattern.

    // The period is then divided by sz to get the number of repetitions of the pattern in the substring.

    // If the number of repetitions is even (period % 2 == 0),
    // it increments the count cnt. This is because an even number
    // of repetitions allows us to split the substring into two equal parts a and c.

    // Finally, the loop continues to the next i until it has checked all possible substrings of s.

    // so this loop checks whether you can divide string s into two identitcal strings a and b
    // and the condition i < s.size() - 1 makes sure that string c is not empty

    for(int i = 1; i < s.size() - 1; i+=2) {
        int cur_size = i + 1;
        int pattern_len = cur_size - p[i];
        if(p[i] != 0 && cur_size % pattern_len == 0){
            int repetitions = cur_size / pattern_len;
            if(repetitions % 2 == 0)cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}