// C.cpp: Your C++ code here
#include <iostream>
#include <cmath>
using namespace std;

struct node
{
    int data;

    node* nxt;
    node(int _data){
        data = _data;
    }

    node(int _data, node* _nxt){
        data = _data;
        nxt = _nxt;
    }
};

struct llist
{
    node* head = 0;

    node* get_tail(){
        node* cur = head;
        while(cur->nxt != 0){
            cur = cur->nxt;
        } 
        return cur;
    }

    void push_back(int data){
        node* A = new node(data, 0);
        if(head == 0){
            head = A;
            return;
        }
        node * tail = get_tail();
        tail->nxt = A;
    }

    void output(){
        node* cur = head;
        while (cur != 0){
            cout << cur->data << " ";
            cur = cur->nxt;
        }
        cout << endl;
    }

    void del(int n){

        if(head == 0)
            return;

        if(n == 0){
            node* old_head = head;
            head = head->nxt;
            delete old_head;
            return;
        }

        node* cur = head;

        for(int i = 0; i < n - 1; i++){
            cur = cur->nxt;
        }

        node* old_node = cur->nxt;
        cur->nxt = cur->nxt->nxt;
        delete old_node;
        return;
    }
};

int main(){
    llist l;
    int n, input;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> input;
        l.push_back(input);
    }

    for(int i = 1; i <= n/2; i++){
        l.del(i);
    }

    l.output();
    return 0;
}
