#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int key;
    int cnt;
    Node *right;
    Node *left;

    Node(int x)
    {
        key = x;
        right = left = NULL;
        cnt = 1;
    }
};

struct BST{
    Node *root = NULL;

    void insert(Node *&cur, int x)
    {
        if (cur == NULL)
        {
            cur = new Node(x);
            return;
        }
        if(x == cur->key){
            cur->cnt++;
            return;
        }
        if (x < cur->key)
        {
            insert(cur->left, x);
        }
        else
        {
            insert(cur->right, x);
        }
    }

    void insert(int x)
    {
        insert(root, x);
    }

    void del(Node* cur, int x){
        if(!cur) return;
        if(x == cur->key){
            cur->cnt--;
            return;
        }
        if(x < cur->key){
            del(cur->left, x);
        }
        else{
            del(cur->right, x);
        }
    }

    void del(int x){
        del(root, x);
    }

    int count(Node* cur, int x){
        if(!cur) return 0;
        if(x == cur->key){
            return cur->cnt;
        }
        if(x < cur->key){
            return count(cur->left, x);
        }
        else{
            return count(cur->right, x);
        }
    }

    int count(int x){
        return count(root, x);
    }
};

int main(){
    int n;
    cin >> n;
    int input;
    string str;
    BST bst;
    for(int i = 0; i < n; i++){
        cin >> str >> input;
        if(str == "insert"){
            bst.insert(input);
        } else if(str == "delete"){
            bst.del(input);
        }
        else{
            cout << bst.count(input) << endl;
        }
    }
}