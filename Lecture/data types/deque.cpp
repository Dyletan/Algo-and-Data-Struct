#include <iostream>
using namespace std;

struct deque {
    int a[100];
    int st, en;

    deque() {
        st = en = 50;
    }

    void push_front(int x) {
        a[--st] = x;
    }

    void push_back(int x) {
        a[en++] = x;
    }

    int front() {
        return a[st];
    }

    int back() {
        return a[en];
    }

    int pop_back() {
        return a[--en];
    }

    int  pop_front() {
        return a[st++];
    }

    int size() {
        return en - st;
    }

    void show_all() {
        for(int i = st; i < en; i++){
            cout << a[i] << endl;
        }
    }

};

int main() {
    deque d;
    d.push_front(1);
    d.push_back(2);
    d.push_front(3);
    d.push_front(22);
    d.push_back(12);
    cout << "size: " << d.size() << endl;
    d.show_all();
    cout << "Pop back: " << d.pop_back() << endl;
    cout << "Pop front: " << d.pop_front() << endl;
    cout << "size: " << d.size() << endl;
    d.show_all();

}