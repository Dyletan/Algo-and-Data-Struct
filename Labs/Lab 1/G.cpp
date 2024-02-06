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
    cout << check_prime(4);

    // 100-th prime is 541, so the prime number
    // that corresponds to index 541 is 3911
    int limit = 3911;
    int cnt_prime = 1;
    int cnt_sprime = 0;
    int sprime;
    vector<bool> a(limit);
    bool b[100];
    for(int i = 3; i <= limit; i+=2){
        if(a[i] != true){
            if(check_prime(i)){
                cnt_prime++;
                if(check_prime(cnt_prime)){
                    cnt_sprime++;
                    if(cnt_sprime == n){
                        sprime = i;
                        break;
                    }
                    for(int j = i; j <= 100; j+= i){
                        b[j] = true;
                    }
                }
                
                for(int j = i; j < limit; j+= i){
                    a[j] = true;
                }
            };
        }
    }
    
    cout << sprime;
}