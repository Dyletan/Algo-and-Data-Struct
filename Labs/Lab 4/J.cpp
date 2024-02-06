#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

void shuffle(vector<int>& arr, vector<int>& result, int start, int end) {
    if (start > end) {
        return;
    }

    int mid = start + (end - start) / 2;
    result.push_back(arr[mid]);

    shuffle(arr, result, start, mid - 1);
    shuffle(arr, result, mid + 1, end);
}

vector<int> shuffle(vector<int>& arr) {
    vector<int> result;
    shuffle(arr, result, 0, arr.size() - 1);
    return result;
}

int main(){
    int n;
    cin >> n;
    int size = pow(2, n)-1;
    vector<int> a;
    int input;
    for(int i = 0; i < size; i++){
        cin >> input;
        a.push_back(input);
    }
    sort(a.begin(), a.end());
    vector<int> b = shuffle(a);
    for(int i : b){
        cout << i << " ";
    }
}