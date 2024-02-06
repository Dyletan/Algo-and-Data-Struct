#include <iostream>
#include <vector>
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

int max = -1;
int a[100]  {};
struct BST
{
    Node *root = NULL;

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

    Node *insert(Node *node, int x, int y, int z)
    {
        if (!node)
            return NULL;
        if (node->key == x)
        {
            if (z == 0)
            {
                node->left = new Node(y);
            }
            else
                node->right = new Node(y);
            return node;
        }
        insert(node->left, x, y, z);
        insert(node->right, x, y, z);
        return node;
    }

    void width(Node* cur, int level, int a[]){
        if(!cur) return;
        a[level]++;
        // cout << level << endl;
        width(cur->left, level+1, a);
        width(cur->right, level + 1, a);
    }

    void width(){
        width(root, 0, a);
    }
};

int main()
{
    int n;
    cin >> n;
    int x, y, z;
    BST bst;
    bst.root = new Node(1);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> x >> y >> z;
        bst.insert(bst.root, x, y, z);
    }

    bst.width();
    int max = -1;
    for(int i : a){
        if(i > max) max = i;
    }
    cout << max;
}
