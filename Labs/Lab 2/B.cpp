#include <iostream>
using namespace std;


struct node{
    string data;
    node* nxt = 0;

    node(string _data, node* _nxt){
        data = _data;
        nxt = _nxt;
    }
};

struct llist{
    node* head = 0;
    node* tail = 0;

    void insert_tail(string data){
        node* new_node = new node(data, 0);

        if(head == NULL){
            head = new_node;
            tail = new_node;
        } else {
            tail->nxt = new_node;
            tail = new_node;
        }
    }

     void del_begin(){
        if (head == 0){
            return;
        }
        if (head->nxt == 0){
            delete head;
            head = 0;
            return;
        }
        node* old_head = head;
        head = head->nxt;
        delete old_head; // to free up the memory
    }

    void output(){
        node* cur = head;
        while (cur != 0){
            cout << cur->data << " ";
            cur = cur->nxt;
        }
        cout << endl;
    }
};

int main(){
    llist l;
    int n, k;
    cin >> n >> k;
    string input;
    for(int i = 0; i < n; i++){
        cin >> input;
        l.insert_tail(input);
    }

    for(int i = 0; i < k; i++){
        l.insert_tail(l.head->data);
        l.del_begin();
    }
    
    l.output();
}