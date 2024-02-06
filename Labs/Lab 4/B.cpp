#include <iostream>
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

int cnt = 0;

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

    Node *find(Node *cur, int x)
    {
        if (!cur)
            return NULL;
        if (cur->key == x)
        {
            return cur;
        }
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

    void count(Node *cur)
    {
        if (!cur)
            return;
        cnt++;
        count(cur->right);
        count(cur->left);
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
    int x;
    cin >> x;
    Node *new_root = bst.find(x);
    bst.count(new_root);
    cout << cnt;
    // bst.print();
}