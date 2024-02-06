#include <iostream>
using namespace std;

int cnt = 0;
 
struct Node{
    int val;
    Node* next;
    Node(): val(0), next(nullptr) {}
    Node(int x): val(x), next(nullptr) {}
    Node(Node* next): val(0), next(next) {}
    Node(int x, Node* next): val(x), next(next) {}
};

Node* insert(Node* head, Node* node, int p){
    Node* cur = head;
    if(p == 0){
        node->next = head;
        head = node;
    }
    else{
        for(int i = 0; i < p - 1; i++){
            cur = cur->next;
        }
        node->next = cur->next;
        cur->next = node;
    }
    cnt++;
    return head;
}

Node* remove(Node* head, int p){
    if(p == 0){
        Node* old_head = head;
        head = head->next;
        old_head->next = nullptr;
        delete old_head;
    }
    else{
        Node* cur = head;
        for(int i = 0; i < p - 1; i++){
            cur = cur->next;
        }
        Node* old_node = cur->next;
        cur->next = cur->next->next;
        delete old_node;
    }
    cnt--;
    return head;
}

Node* replace(Node* head, int p1, int p2){
    Node* cur = head;
    for(int i = 0; i < p1; i++){
        cur = cur->next;
    }
    Node* new_node = new Node(cur->val, nullptr);
    head = remove(head, p1);
    head = insert(head, new_node, p2);
    return head;
} 
 
void print(Node* head){
    if(!head){
        cout << "-1" << endl;
        return;
    }
    Node* cur = head;
    while(cur){
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
}

Node* reverse(Node* head) {
    Node* cur = head;  
    Node* prev = nullptr;
    Node* next = nullptr;

    while (cur != nullptr) {
        next = cur->next;  // сохрнаить след ноуд, чтобы перейти к нему в конце итерации
        cur->next = prev;  // реверснуть направление следующего поинтера
        prev = cur;  // перейти на след ноуд
        cur = next;
    }
    head = prev;

    return head;
}

Node* cyclic_right(Node* head, int x) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    x = x % cnt;  // handle case when x is greater than cnt
    if (x == 0) {
        return head;
    }

    Node* cur = head;
    for(int i = 1; i < cnt - x; i++){
        cur = cur->next;
    }
    Node* newHead = cur->next;
    cur->next = nullptr;

    Node* tail = newHead;
    while (tail->next != nullptr) {
        tail = tail->next;
    }
    tail->next = head;

    return newHead;
}

Node* cyclic_left(Node* head, int x) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    x = x % cnt;  // handle case when x is greater than cnt
    if (x == 0) {
        return head;
    }

    Node* cur = head;
    for(int i = 1; i < x; i++){
        cur = cur->next;
    }
    Node* newHead = cur->next;
    cur->next = nullptr;

    Node* tail = newHead;
    while (tail->next != nullptr) {
        tail = tail->next;
    }
    tail->next = head;

    return newHead;
}

int main(){
    Node* head = nullptr;
    while (true)
    {
        int command; cin >> command;
        if (command == 0){
            break;
        }else if(command == 1){
            int x, p; cin >> x >> p;
            head = insert(head, new Node(x), p);
        }else if (command == 2){
            int p; cin >> p;
            head = remove(head, p);
        }else if (command == 3){
            print(head);
        }else if (command == 4){
            int p1, p2; cin >> p1 >> p2;
            head = replace(head, p1, p2);
        }else if (command == 5){
            head = reverse(head);
        }else if (command == 6){
            int x; cin >> x;
            head = cyclic_left(head, x);
        }else if (command == 7){
            int x; cin >> x;
            head = cyclic_right(head, x);
        }   
    }
    return 0;
}