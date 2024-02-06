#include <iostream>
#include <vector>
using namespace std;

vector<int> kmp(string s){
    vector<int> p(s.size(), 0);
    for(int i = 1; i < s.size(); i++){
        int j = p[i-1];
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

int main(){
    string w = "aba";
    string s = "abacaba";
    vector<int> p = kmp(w+"#"+s);
    for(int i : p){
        cout << i << " ";
    }
}