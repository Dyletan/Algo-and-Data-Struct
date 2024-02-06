#include <iostream>
#include <unordered_set>
using namespace std;

typedef unsigned long long ull;

const int p = 31;

int main()
{
    string str;
    cin >> str;

    unordered_set<ull> found;
    for(int i = 0; i < str.size(); i++){
        ull h = 0;
        for(int j = i; j < str.size(); j++){
            h = h*p + str[j];
            found.insert(h);
        }
    }
    cout << found.size();
    return 0;
}
