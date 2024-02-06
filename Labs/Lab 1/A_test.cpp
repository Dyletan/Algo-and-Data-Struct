#include <bits/stdc++.h>
using namespace std;
// start from the end of the algorithm using hint
// go from top of description to the top
// the last card is the n
// so the algorithm goes add a number n
// then add another - n-1
// then perform permutation and do this until solved 

void rotation(int n){
    vector<int> ans(n);
    queue<int> q;

    for(int i = 0; i<n ; i++){
        q.push(i);
    }

    for(int i = 1; i<=n ; i++){
        // this for loop decides the position for current i
        //moves the front element of the queue to its back for i % q.size() times.
        for(int j = 0; j < (i%q.size()) ; j++){
            q.push(q.front());
            q.pop();
        }

        ans[q.front()] = i;
        q.pop();
    }
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    int m, n;
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> n;
        rotation(n);
    }
}