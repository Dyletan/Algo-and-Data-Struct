#include <bits/stdc++.h>
using namespace std;


int main(){
    queue<int> a, b;
    int cnt = 0;
    int input;

    for(int i = 0; i < 5; i++){
        cin >> input;
        a.push(input);
    }

    for(int i = 0; i < 5; i++){
        cin >> input;
        b.push(input);
    }
    

    while(!a.empty() && !b.empty()){
        int first = a.front();
        int second = b.front();
        a.pop();
        b.pop();
        if(first == 0 && second == 9 || first > second){
            a.push(first);
            a.push(second);
        }
        else if(first == 9&&second == 0){
            b.push(first);
            b.push(second);
        }
        else if(cnt >= 10e6){
            cout << "blin nichya";
        }
        else{
            b.push(first);
            b.push(second);
        }
        cnt++;
    }

    if(!b.empty())
        cout << "Nursik " << cnt;
    else
        cout << "Boris " << cnt;
    return 0;

}