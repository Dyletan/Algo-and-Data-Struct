#include <bits/stdc++.h>
  
using namespace std;

struct Node{
	Node * prev;
	Node * next;
	string val;
	Node(string _val){
		prev = NULL;
		next = NULL;
		val = _val;
	}	
};

Node * head = NULL;
Node * tail = NULL;
int cnt;

void add_back(string s){
	Node* new_node = new Node(s);
	if(!head){
		head = new_node;
		tail = new_node;
	}
	else{
		tail->next = new_node;
		new_node->prev = tail;
		tail = new_node;
	}
    cnt++;
}
void add_front(string s){
	Node* new_node = new Node(s);
    if(!head){
		head = new_node;
		tail = new_node;
	}
	new_node->next = head;
	head->prev = new_node;
	head = new_node;
    cnt++;
}
bool empty(){
	return !head ? true : false;
}
void erase_front(){
    if (head == tail) {
            head = NULL;
            tail = NULL;
            return;
    }
	Node* old_head = head;
	head->next->prev = nullptr;
	head = head->next;
	old_head->next = nullptr;
	delete old_head;
	cnt--;
}
string front(){
	return head->val;
}
string back(){
	return tail->val;
}
void print(){
    Node* cur = head;
    while(cur){
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
}
void erase_back(){
	Node* old_tail = tail;
    if (head == tail) {
            head = NULL;
            tail = NULL;
            return;
    }
	tail->prev->next = nullptr;
	tail = tail->prev;
	delete old_tail;
	cnt--;
}

void clear() {
    Node *cur = head;
    while(cur) {
        Node *next_node = cur->next;
        delete cur;
        cur = next_node;
    }
    head = NULL;
    tail = NULL;
}

int main(){
    // cout << empty();
    add_front("You");
    add_back("Piece");
    cout << front() << endl;
    erase_front();
    cout << back() << endl;
    erase_back();
    // add_back("Fucking");
    // add_back("Cunt");
    // add_back("Void");
    // add_front("Well,");
    // erase_front();
    // erase_back();
    // clear();
    // add_back("AFAS");
    print();
}