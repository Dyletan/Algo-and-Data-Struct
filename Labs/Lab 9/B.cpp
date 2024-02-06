#include <iostream>
#include <vector>
using namespace std;

vector<int> prefix(string s){
    vector<int> p(s.size(), 0);
    int j;
    for(int i = 1; i < s.size(); i++){
        j = p[i-1];
        while(j > 0 && s[j] != s[i]){
            j = p[j-1];
        }
        if(s[i] == s[j]){
            j++;
        }
        p[i] = j;
    }
    return p;
}

bool kmp(string sub, string str, int k){
    int count = 0;
    vector<int> p = prefix(sub+"#"+str);
    for(int i : p){
        if(i == sub.size()) count++;
    }
    return count >= k;
}

int main(){
    string sub, str;
    int k;
    cin >> sub >> k >> str;
    if(kmp(sub, str, k)) cout << "YES";
    else cout << "NO";

}