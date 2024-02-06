#include <bits/stdc++.h>
using namespace std;


int main(){
    stack<char> word;
    char input;

    while(cin>>input){
        if(word.empty() || word.top() != input){
            word.push(input);
        }
        else{
            word.pop();
        }
    }
    word.empty() ? cout << "YES" : cout << "NO";
}