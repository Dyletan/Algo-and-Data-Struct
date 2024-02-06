#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    Node *left;
    Node *right;
    int key;
    Node(int x)
    {
        key = x;
        left = right = NULL;
    }
};

vector<int> v;
int sum = 0;
int i = 0;

struct BST
{
    Node *root = NULL;

    void insert(Node *&cur, int x)
    {
        if (cur == NULL)
        {
            cur = new Node(x);
            return;
        }
        if (x <= cur->key)
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

    void postsum(Node* cur){
        if(!cur) return;
        postsum(cur->right);
        sum += cur->key;
        v.push_back(sum);
        postsum(cur->left);
    }

    void postsum(){
        postsum(root);
    }

    void update(Node* cur){
        if(!cur) return;
        update(cur->right);
        cur->key = v[i++];
        update(cur->left);
    }

    void update(){
        update(root);
    }

    void postorder(Node* cur){
        if(!cur) return;
        postorder(cur->right);
        cout << cur->key << " ";
        postorder(cur->left);
    }

    void postorder(){
        postorder(root);
    }
};

int main(){
    int n;
    cin >> n;
    BST bst;
    int input;
    for(int i = 0; i< n; i++){
        cin >> input;
        bst.insert(input);
    }

    bst.postsum();
    bst.update();
    bst.postorder();
}