#include <bits/stdc++.h>
using namespace std;

void checkYounger(deque<int> a){
    stack<int> result;
    while(!a.empty()){
        int limit = a.size()-2;
        for(int i = limit; i >= -1; i--){
            if(i == -1){
                result.push(-1);
                break;
            }
            if(a[i]<=a.back()){
                result.push(a[i]);
                break;
            }
            
        }
        a.pop_back();
    }

    while(!result.empty()){
        cout << result.top() << " ";
        result.pop();
    }
}

int main(){
    int N;
    cin >> N;
    deque<int> a;
    int input;
    for (int i = 0; i < N; i++){
        cin >> input;
        a.push_back(input);
    }
    checkYounger(a);
}
