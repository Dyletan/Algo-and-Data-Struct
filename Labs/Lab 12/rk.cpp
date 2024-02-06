#include <iostream>
using namespace std;

int p = 31;

int my_hash(string str){
    int h = 0;
    for(int i = 0; i < str.size(); i++){
        h = h*p + str[i];
    }
    return h;
}

int main(){
    string substr = "aba";
    string str = "abacaba";
    int n = str.size();
    int m = substr.size();
    int hp = my_hash(substr);
    int h = my_hash(str.substr(0, m));
    int pm = 1;
    for(int i = 0; i < m-1; i++){
        pm *= p;
    }
    for(int i = 0; i + m <= n; i++){
        if(h == hp){
            cout << i << " ";
        }
        if(i + m < n){
            hp = (hp-str[i]*pm)*p+str[i+m];
        }
    }
}