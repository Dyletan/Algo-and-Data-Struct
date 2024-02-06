#include <iostream>
using namespace std;

const int N = 1e5+1; 

struct Heap{
    int n = 0;
    int a[N];

    void heapify_up(int v){
        while(v != 1 && a[v] > a[v/2]){
            swap(a[v], a[v/2]);
            v = v/2;
        }
    }

    void heapify_down(int v){
        while(true){
            int max = v;
            if(2*v <= n && a[2*v] > a[max]){
                max = 2*v;
            }
            if(2*v+1 <= n && a[2*v+1] > a[max]){
                max = 2*v+1;
            }
            if(max == v) break;
            swap(a[v], a[max]);
            v = max;
        }
        
    }

    void push(int x){
        n++;
        a[n] = x;
        heapify_up(n);
    }

    void pop(){
        swap(a[1], a[n]);
        n--;
        heapify_down(1);
    }

    int top(){
        return a[1];
    }

    void print(){
        while(n){
            cout << top() << endl;
            pop();
        }
    }

    int smash_stones(){
        while(n>1){
            int max1 = top();
            pop();
            int max2 = top();
            pop();
            // if(max1 - max2 != 0)
            push(max1 - max2);
        }
        return top();
    }
};

int main(){
    int n; cin >> n;
    int input;
    Heap h;
    for(int i = 0; i < n; i++){
        cin >> input;
        h.push(input);
    }
    cout << h.smash_stones();
}