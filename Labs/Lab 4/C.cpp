#include <iostream>
using namespace std;

struct Node
{
    int key;
    Node *right;
    Node *left;
    Node(int x)
    {
        key = x;
        right = left = NULL;
    }
};

struct BST
{
    Node *root = nullptr;

    void insert(Node *&cur, int x)
    {
        if (cur == NULL)
        {
            cur = new Node(x);
            return;
        }
        if(x == cur->key){
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

    Node *find(Node *cur, int x)
    {
        if (!cur)
            return NULL;
        if (cur->key == x)
            return cur;
        if (x <= cur->key)
        {
            return find(cur->left, x);
        }
        else
        {
            return find(cur->right, x);
        }
        return NULL;
    }

    Node *find(int x)
    {
        return find(root, x);
    }

    void preorder(Node *cur)
    {
        if (!cur)
            return;
        cout << cur->key << " ";
        preorder(cur->left);
        preorder(cur->right);
    }
};

int main()
{
    int n;
    cin >> n;
    int input;
    BST bst;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        bst.insert(input);
    }
    int k;
    cin >> k;
    Node *new_root = bst.find(k);
    bst.preorder(new_root);
}