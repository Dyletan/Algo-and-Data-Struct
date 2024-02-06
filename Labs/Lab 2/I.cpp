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

bool empty(){
	return !head && !tail;
}

void add_back(string s){
	Node* new_node = new Node(s);
	if(empty()){
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
	if(empty()){
		head = new_node;
		tail = new_node;
	}
	new_node->next = head;
	head->prev = new_node;
	head = new_node;
	cnt++;
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
	delete old_head;
	cnt--;
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
string front(){
	return head->val;
}
string back(){
	return tail->val;
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

  
int main()
{
	string s;
   	while(cin >> s){
   		if(s == "add_front"){
   			string t;
   			cin >> t;
   			add_front(t);
   			cout << "ok" << endl;
   		}
   		if(s == "add_back"){
   			string t;
   			cin >> t;
   			add_back(t);
   			cout << "ok" << endl;
   		}
   		if(s == "erase_front"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else
   			{
   				cout << front() << endl;
   				erase_front();
   			}
   		}
   		if(s == "erase_back"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else{
   				cout << back() << endl;
   				erase_back();
   			}
   		}
   		if(s == "front"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else{
   				cout << front() << endl;
   			}
   		}
   		if(s == "back"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else{
   				cout << back() << endl;
   			}
   		}
   		if(s == "clear"){
   			clear();
   			cout << "ok" << endl;
   		}
   		if(s == "exit"){
   			cout << "goodbye" << endl;
   			break;
   		}
   		// cout << "hi" << endl;
   	}
    return 0;
}