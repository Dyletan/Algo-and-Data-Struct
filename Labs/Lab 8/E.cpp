#include <iostream>
using namespace std;

long long pow_of_2 = 1;
long long previ = 0;

char unhash(unsigned long long i){
    char result = (i-previ)/pow_of_2 + 97;;
    previ = i;
    return result;
}

int main(){
    unsigned long long n;
    cin >> n;
    unsigned long long input;
    string result = "";
    for(unsigned long long i = 0; i < n; i++){
        cin >> input;
        result += unhash(input);
        pow_of_2 *= 2;
    }
    cout << result;
}