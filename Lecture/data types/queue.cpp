#include <iostream>
using namespace std;

struct queue
{
    int a[100];
    int st, en;

    queue() {
        st = en = 0;
    }

    int size(){
        return en - st;
    }

    bool empty() {
        return en == st;
    }

    int front() {
        return a[st];
    }

    void push(int x){
        a[en++] = x;
    }

    int pop() {
        if(empty()) {
            cerr << "Popping of empty queue" << endl;
            exit(0);
        }
        return a[st++];
    }

};

int main() {
    queue q;
    q.push(1);
    cout << "Front: " << q.front() << endl;
    q.push(2);
    cout << "Pop: " << q.pop() << endl;
    cout << "Pop: " << q.pop() << endl;
    cout <<  "Bool: " << q.empty() << endl;
    q.push(3);
    cout << q.size() << "   " << q.front() << endl;
}
