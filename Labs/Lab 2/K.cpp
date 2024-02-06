# include <bits/stdc++.h> 
using namespace std;
 
struct Node {
  char val;
  Node *next;
  bool has_pair;

  Node(char val, bool has_pair){
    this->val = val;
    this->has_pair = has_pair;
    this->next = NULL;
  }

};

struct LinkedList{
    Node *head = NULL;

    bool find_occurence(char val){
        Node* cur = head;
        while(cur != NULL){
            if(cur->val == val){
                cur->has_pair = true;
                return true;
            }
            cur = cur->next;
        }
        return false;
    }

    char find_false(){
        Node* cur = head;
        while(cur != NULL && cur->has_pair != false){
            cur = cur->next;
        }
        if(cur == NULL || cur->has_pair){
            return '\0';
        }
        return cur->val;
    }

    Node* get_tail(){
        if(head == NULL)
            return NULL;
        Node* cur = head;
        while(cur->next != 0){
            cur = cur->next;
        }
        return cur;
    }

    void insert_tail(char val){
        bool has_pair = find_occurence(val);
        Node* new_Node = new Node(val, has_pair);

        Node* tail = get_tail();
        if(tail == NULL){
            head = new_Node;
        } else {
            tail->next = new_Node;
        }
    }
};
 
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int m;
        cin >> m;
        LinkedList* a = new LinkedList();
        for(int j = 0; j < m; j++) {
            char x;
            cin >> x;
            a->insert_tail(x);
            char res = a->find_false();
            res == '\0' ? cout << "-1" << " "
            : cout << res << " ";

        }
        cout << endl;
    } 
    return 0;
}