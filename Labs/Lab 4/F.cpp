#include <iostream>
using namespace std;

struct Node
{
    Node *left;
    Node *right;
    int key;
    Node(int _key)
    {
        key = _key;
        left = right = nullptr;
    }
    Node(int _key, Node *_left, Node *_right)
    {
        key = _key;
        left = _left;
        right = _right;
    }
};

int cnt = 0;

struct BST
{
    Node *root = nullptr;

    void insert(Node *&cur, int x)
    {
        if (!cur)
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

    void triangles(Node* cur){
        if(!cur)return;
        if(cur->left && cur->right)cnt++;
        triangles(cur->left);
        triangles(cur->right);
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
    // cout << 132;
    // bst.print();
    bst.triangles(bst.root);
    cout << cnt;
}