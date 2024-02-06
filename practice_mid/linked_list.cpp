struct Node{
    Node *next;
    Node *prev;
    int val;
    Node(int x){
        val = x;
        next = prev = nullptr;
    }
};

struct linked_list{
    Node* head = nullptr;
    Node* tail = nullptr;
    void push(int x){
        Node* new_node = new Node(x);
        if(!head){
            head = new_node;
            tail = new_node;
            return;
        }
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }
};