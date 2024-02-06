#include <iostream>
#include <vector>
#include <map>
using namespace std;

long long p = 31;
map<string, long long> freq;

long long hash_str(string s)
{
    long long h = 0;
    for (long long i = 0; i < s.size(); i++)
        h = h * p + s[i];
    return h;
}

long long power(long long p, long long m)
{
    long long result = 1;
    for (long long i = 0; i < m; i++)
        result *= p;
    return result;
}

void rabin_karp(string pattern, string text){
    if(freq[pattern] != 0) return; // to prevent counting the same patterns twice
    long long n = text.size();
    long long m = pattern.size();
    long long pm = power(p, m-1);
    long long hp = hash_str(pattern);
    long long h = hash_str(text.substr(0, m));
    for(long long i = 0; i + m <= n; i++){
        if(hp == h){
            freq[pattern]++;
        }
        if(i + m < n){
            h = (h-text[i]*pm)*p + text[i+m];
        }
    }


}

int main()
{
    long long input;
    cin >> input;
    while (input != 0)
    {
        string temp;
        vector<string> patterns;

        for (long long i = 0; i < input; i++)
        {
            cin >> temp;
            patterns.push_back(temp);
        }
        // string in which the search is done
        cin >> temp;
        // for every pattern
        for (string pattern : patterns)
        {
            rabin_karp(pattern, temp);
        }
        long long max = -1;
         for (string pattern : patterns)
        {
            if(freq[pattern]> max){
                max = freq[pattern];
            }
        }
        cout << max << endl;
        // to output in order of input
        for (string pattern : patterns)
        {
            if (freq[pattern] == max)
            {
                cout << pattern << endl;
            }
        }
        cin >> input;
    }
}