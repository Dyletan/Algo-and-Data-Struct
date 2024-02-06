#include <iostream> 
using namespace std;

const int s = 10e5;

struct stack {
    int a[s]; // capacity of 100
    int n;

    stack() {
        n = 0;
    }

    int size() {
        return n;
    }

    void push(int x) {
        a[n++] = x;
    }

    int pop() {
        if(n == 0) {
            cerr << "Popping of nonexistent element" << endl;
            exit(0);
        }
        return a[--n];
    }

    int top(){
        return a[n-1];
    }
};

int main() {
    stack st;
    st.push(10);
    st.push(20);
    cout << "TOP: " << st.top() << endl;
    cout << "POP: " << st.pop() << endl;
    cout << "TOP: " << st.top() << endl;
    cout << "Size: " << st.size() << endl;
    st.push(212);
    cout << "Size: " << st.size() << endl;
    cout << st.pop() << endl;
    cout << st.pop();
    st.pop();
}