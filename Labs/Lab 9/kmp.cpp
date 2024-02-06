#include <iostream>
#include <vector>
using namespace std;

vector<int> kmp(string s){
    vector<int> p(s.size(), 0);
    
    for(int i = 1; i < s.size(); i++){
        // j is a variable used to keep track of the length of the 
        // longest proper prefix which is also a proper suffix of 
        // the current substring.
        int j = p[i - 1];
        // access the prefix function of previous iteration

        while(j>0 && s[j] != s[i]){ // decrement j until it is 0 or we have that charachters on positions i and j are the same
        // This is done to find the proper prefix that is also a proper suffix.
            j = p[j-1];
        }

        if(s[i] == s[j]){ // increase j because we found another mathcing character
        //so we've found a longer common prefix and suffix.
            j++;
        }
        p[i] = j; // update the prefix function vector for the current character
    }
    return p;
}

int main(){
    string s;
    cin >> s;
    vector<int> p = kmp(s);
    for(int i = 0; i < p.size(); i++){
        cout << p[i] << " ";
    }
    // abacaba   
    // 0 0 1 0 1 2 3 
    // abaababaaba
    // 0 0 1 1 2 3 2 3 4 5 6 
   
}