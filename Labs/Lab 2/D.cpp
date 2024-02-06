#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[1001]{};
    int input;
    
    for(int i = 0; i < n; i++){
        cin >> input;
        a[input]++;
    }

    int max = -1;
    vector<int> b;

    for(int i = 0; i < 1001; i ++){
        if(a[i] > max){
            b.clear();
            max = a[i];
            b.push_back(i);
        }
        else if(a[i] == max){
            b.push_back(i);
        }
    }
    
    sort(b.begin(), b.end(), greater<int>());

    for(int i = 0; i < b.size(); i ++){
        cout << b[i] << " ";
    }

}