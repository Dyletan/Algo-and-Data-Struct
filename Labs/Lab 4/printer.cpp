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

struct BST
{
    Node *root = nullptr;

    void print(Node *cur, int space = 0)
    {
        // Base case
        if (cur == NULL)
            return;

        // Increase distance between levels
        space += 10;

        // Process right child first
        print(cur->right, space);

        // Print current Node after space
        // count
        cout << endl;
        for (int i = 10; i < space; i++)
            cout << " ";
        cout << cur->key << "\n";

        // Process left child
        print(cur->left, space);
    }

    void print()
    {
        print(root);
    }

    void insert(Node *&cur, int x)
    {
        if (cur == nullptr)
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
    bst.print();
}