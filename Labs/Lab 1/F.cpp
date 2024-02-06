#include <bits/stdc++.h>
using namespace std;

// bool check_prime(int i){
//     for(int j = 2; j*j < i; j++){
//         if(i%j == 0)
//             return false;
//     }
//     return true;
// }

bool check_prime(int i){
    if(i == 2)
        return true;
    for(int j = 3; j*j < i; j+=2){
        if(i%j == 0)
            return false;
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    if(n == 1){
        cout << 2;
        return 0;
    }
    int limit = n*n;
    int cnt = 1;
    int prime;
    vector<bool> a(limit);
    for(int i = 3; i < limit; i+=2){
        if(a[i] != true){
            if(check_prime(i)){
                cnt++;
                if(cnt == n){
                    prime = i;
                    break;
                }
                for(int j = i; j < limit; j+= i){
                    a[j] = true;
                }
            };
        }
    }
    
    cout << prime;
}