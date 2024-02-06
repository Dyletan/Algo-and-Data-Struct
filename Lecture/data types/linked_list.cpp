#include <iostream>
using namespace std;

struct node{
    int data;
    // null pointer
    node* nxt = 0;
    // three different node constructors
    node() {
        data = 0;
    }
    
    node(int _data){
        data = _data;
    }

    node(int _data, node* _nxt){
        data = _data;
        nxt = _nxt;
    }
};

struct llist{
    node* head = 0;

    node* get_tail(){
        if(head == 0)
            return 0;
        node* cur = head;
        while(head->nxt != 0){
            head = head->nxt;
        }
        return cur;
    }

    node* get(int i){
        node* cur = head;
        for(int j = 0; j < i; j++){
            if(cur == 0)
                return 0;
            cur = cur->nxt;
        }
        return cur;
    }

    void insert_begin(int data){
        node* new_node = new node(data, head);
        head = new_node;
    }

    void insert_tail(int data){
        node* tail = get_tail();
        node* new_node = new node(data, 0);
        tail->nxt = new_node;
    }

    void insert(int i, int data){
        if (i == 0){
            insert_begin(data);
            return;
        }
        node* A = get(i-1);
        if (A == 0){
            insert_tail(data);
            return;
        }
        node* B = A->nxt;
        node* new_node = new node(data, B);
        A->nxt = new_node;
    }

    void output(){
        cout << "[";
        node* cur = head;
        while (cur != 0){
            cout << cur->data;
            cur = cur->nxt;
            if (cur == 0)
                cout << "]";
            else
                cout << ", ";
        }
        cout << endl;
    }

    void del_begin(){
        if (head == 0){
            return;
        }
        node* old_head = head;
        head = head->nxt;
        delete old_head; // to free up the memory
    }

    void del_end() {
        if (head == 0)
            return;
        else if (head->nxt == 0){
            delete head;
            head = 0;
            return;
        }
        node* cur = head;
        while(cur->nxt->nxt != 0){
            cur = cur->nxt;
        }
        delete cur->nxt;
        cur->nxt = 0;
    }

    void del(int i) {
        node* cur = head;
        if(i <= 0){
            if (head == 0)
                return;
            node* old_head = head;
            head = head->nxt;
            delete old_head;
        }
        for(int j = 0; j < i-1; j++){
            if(cur->nxt->nxt == 0){
                cerr << "Index out of range";
                exit(0);
            }
            cur = cur->nxt;
        }
        delete cur->nxt;
        cur->nxt = cur->nxt->nxt;
    }
};

int main() {
    llist L;
	L.insert(0, 10); // [10]
	L.insert(1, 20); // [10, 20]
	L.insert(2, 30); // [10, 20, 30]
	L.insert(3, 40); // [10, 20, 30, 40]

	L.insert(2, 50); // [10, 20, 50, 30, 40]
	L.output();
    
    L.del_begin();
	L.output();


	L.del_end();
	L.output();

    L.del(2);
    L.output();


	return 0;
}