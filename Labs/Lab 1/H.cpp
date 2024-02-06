#include <bits/stdc++.h>
using namespace std;

bool check_prime(int i){
    for(int j = 2; j*j <= i; j++){
        if(i%j == 0)
            return false;
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    if(n==1){
        cout << "NO";
        return 0;
    }
    check_prime(n) ? cout << "YES" : cout << "NO";
}

