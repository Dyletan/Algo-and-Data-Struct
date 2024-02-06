#include <iostream>
#include <vector>
using namespace std;

vector<int> prefix(string s){
    vector<int> p(s.size(), 0);
    for(int i = 1; i < s.size(); i++){
        int j = p[i-1];
        while(j > 0 && s[j] != s[i]){
            j = p[j-1];
        }
        if(s[j] == s[i])
        {
            j++;
        }
        p[i] = j;
    }
    return p;
}

int main(){
    string str, shifted;
    cin >> str >> shifted;
    vector<int> p = prefix(str+"#"+shifted+shifted);
    for(int i = str.size()+1; i < p.size(); i++){
        if(p[i] == str.size()){
            cout << i - str.size() - str.size();
            return 0;
        }
    }
    cout << -1;
}