#include <bits/stdc++.h>
using namespace std;

string remove(string input) {
    string result;
    int length = input.length();

    for (int i = 0; i < length; i++) {
        // If the current character is not equal to the next character (or we're at the end)
        if (i == length - 1 || input[i] != input[i + 1]) {
            result += input[i]; // Append the character to the result
        } 
        else
            i++;
    }

    return result;
}


int main(){
    string input, result;
    getline(cin, input);
    result = remove(input);
    while(!input.empty()){
        if(result == input){
            cout << "NO";
            return 0;
        }
        result = input;
        input = remove(input);
    }
    cout << "YES";
}