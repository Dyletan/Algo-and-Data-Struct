
#include <queue>
#include <iostream>
using namespace std;

deque<int> rotation(deque<int> deck, int n){
    for(int i = 0; i < n; i++){
        deck.push_front(deck.back());
        deck.pop_back();
    }
    return deck;
}

int main(){
    int m;
    cin >> m;
    for(int k = 0; k < m; k++){
        int n;
        cin >> n;
        deque<int> deck;

        // 213 -> 123 -> 23 -> 32 -> 23 -> 3 -> nothing

        for(int i = n; i > 0; i--){
            deck.push_front(i);
            deck = rotation(deck, i);
        }
        for(int i : deck){
            cout << i << " ";
        }
        cout << endl;
    }
}