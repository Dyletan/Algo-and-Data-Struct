#include <bits\stdc++.h>
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

    void push_back(int i){
        if(head == 0){
            node* new_node = new node(i, 0);
            head = new_node;
            return;
        }
        node* cur = get_tail();
        node* new_node = new node(i, 0);
        cur->nxt = new_node;
    }

    void insert (int x, int i){
        node* cur = head;
        if(x == 0){
            node* old_node = cur;
            node* new_node = new node(i, old_node);
            head = new_node;
        }
        for(int i = 0; i < x-1; i++){
            cur = cur->nxt;
        }
        node* new_node = new node(i, cur->nxt);
        cur->nxt= new_node;
    }
};

int main(){
    int n, data, pos, input;
    llist A;
    cin >> n;
    //fill up a linked list
    for(int i = 0; i < n; i++){
        cin >> input;
        A.push_back(input);
    }

    cin >> data >> pos;
    A.insert(pos, data);
    
    node* cur = A.head;

    while(cur->nxt != 0){
        cout << cur->data << " ";
        cur = cur->nxt;
    }
    cout << cur->data;  
}