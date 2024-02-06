#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> a;
    string input;
    string prev = "";

    for(int i = 0; i < n; i++){
        cin >> input;
        if(input != prev){
            a.push_back(input);
        }
        prev = input;
    }

    reverse(a.begin(), a.end());

    cout << "All in all: " << a.size() << endl;
    cout << "Students:" << endl;
    for(string student : a){
        cout << student << endl;
    }
}