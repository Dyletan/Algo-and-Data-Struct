#include <bits/stdc++.h>
using namespace std;

int main(){
    char ch;
    int input;
    deque<int> a;
    cin >> ch;
    while(ch != '!'){
        if(ch == '+'){
            cin >> input;
            a.push_front(input);
        }
        else if(ch == '-'){
            cin >> input;
            a.push_back(input);
        }
        else if(ch == '*'){
            if(a.empty() || a.size() == 0){
                cout << "error" << endl;
            }
            else{
                int sum = a.front() + a.back();
                // cout << "front: " << a.front() << " back: " << a.back() << endl;
                a.pop_back();
                if(!a.empty())
                    a.pop_front();
                cout << sum << endl; 
            }
        }
        cin >> ch;
    }
}