#include <iostream>
using namespace std;

struct Node {

    int data;
    Node* next;
    Node* prev;
    Node(int x){
        data = x;
        next = prev = nullptr;
    }
};

struct DoublyLinkedList {
    Node* head = nullptr;
    Node* tail = nullptr;

    void append(int new_data) {
        Node* new_node = new Node(new_data);
        if (!head) {
            head = new_node;
            return;
        }
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }

    void printList() {
        Node* node = head;
        while (node != nullptr) {
            
            cout << node->data << " ";
            node = node->next;
        }
    }
};

int main() {
    DoublyLinkedList dll;
    dll.append(1);
    dll.append(2);
    dll.append(3);
    dll.append(4);
    dll.append(5);
    dll.printList();
    return 0;
}
