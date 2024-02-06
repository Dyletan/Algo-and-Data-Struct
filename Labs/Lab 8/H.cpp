#include <iostream>
#include <vector>
#include <string>

using namespace std;

string find_longest(vector<string> &strings) {
    int K = strings.size();
    int min_len = 99999;
    for (string str : strings) {
        min_len = min(min_len, (int)str.size());
    }

    string longest = "";
    
    for (int len = 1; len <= min_len; len++) {
        for (int i = 0; i + len <= min_len; i++) {
            string candidate = strings[0].substr(i, len);
            bool found = true;
            
            for (int j = 1; j < K; j++) {
                if (strings[j].find(candidate) == string::npos) {
                    found = false;
                    break;
                }
            }
            
            if (found && len > longest.length()) {
                longest = candidate;
            }
        }
    }

    return longest;
}

int main() {
    int K;
    cin >> K;
    vector<string> strings(K);

    for (int i = 0; i < K; i++) {
        cin >> strings[i];
    }

    string longest = find_longest(strings);

    cout << longest << endl;

    return 0;
}