#include <bits/stdc++.h>
using namespace std;

int main(){
    char input;
    string s;

    while(cin>>input){
        if(input == '#')
            s.pop_back();
        else{
            s += input;
        }
    }
    
    if(s.size() % 2 != 0){
        cout << "No";
        return 0;
    }

    int mid = s.size()/2;

    for(int i = 0; i < mid; i++){
        if(s[i] != s[mid + i]){
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
}