#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;

struct Node
{
    Node *left;
    Node *right;
    int key;
    // string data;

    Node(int _key = 0)
    {
        left = right = NULL;
        key = _key;
    }

    Node(int key, Node *left, Node *right)
        : key(key), left(left), right(right)
    {
    }
};

struct BST
{
    Node *root = NULL;

    // void insert(Node *cur, int x)
    // {
    //     if(root == nullptr) {
    //         root = new Node(x);
    //         return;
    //     }
    //     Node **next = x <= cur->key ? &cur->left : &cur->right;

    //     if (*next == nullptr)
    //     {
    //         *next = new Node(x);
    //         return;
    //     }
    //     insert(*next, x);
    // }

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

    Node *find(Node *cur, int x)
    {
        if (x == cur->key)
            return cur;
        if (x < cur->key)
            return cur->left == NULL
                       ? NULL
                       : find(cur->left, x);
        // x > key
        return cur->right == NULL
                   ? NULL
                   : find(cur->right, x);
    }

    Node *find(int x)
    {
        return find(root, x);
    }

    void print(Node *root, int space = 0)
    {
        // Base case
        if (root == NULL)
            return;

        // Increase distance between levels
        space += 10;

        // Process right child first
        print(root->right, space);

        // Print current Node after space
        // count
        cout << endl;
        for (int i = 10; i < space; i++)
            cout << " ";
        cout << root->key << "\n";

        // Process left child
        print(root->left, space);
    }

    void print()
    {
        print(root);
    }

    Node *del(Node *cur, int x)
    {
        if (cur == NULL)
            return NULL;

        if (x < cur->key)
        {

            cur->left = del(cur->left, x);
        }
        else if (cur->key < x)
        {

            cur->right = del(cur->right, x);
        }
        else
        { // cur->key == x

            /* case cur is leaf */
            if (cur->left == NULL && cur->right == NULL)
            {
                delete cur;
                return NULL;
            }

            /* case cur has 1 child */
            if (cur->left == NULL || cur->right == NULL)
            {
                Node *next = cur->left != NULL
                                 ? cur->left
                                 : cur->right;
                delete cur;
                return next;
            }

            /* case cur have 2 children */
            Node *next = cur->right;
            while (next->left != NULL)
                next = next->left;

            /* copy the content */
            cur->key = next->key;
            // cur->data = next->data; // in case data is used
            cur->right = del(cur->right, next->key);
        }
        return cur;
    }

    void del(int x)
    {
        root = del(root, x);
    }

} bst;

int main()
{

    BST bst;
    bst.insert(6);
    bst.insert(4);
    bst.insert(1);
    bst.insert(5);
    bst.insert(7);
    bst.insert(9);
    bst.print();

    bst.del(4);
    // bst.print();

    return 0;
}
