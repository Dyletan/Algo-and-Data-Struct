#include <bits/stdc++.h>
using namespace std;

struct node{
    node* left;
    node* right;
    int key;
    node(int key){
        this->key = key;
        left = right = NULL;
    }
};

struct BST{
    node* root = NULL;
    void insert(node* &cur, int value){
        if (cur == NULL){
            cur = new node(value);
            return;
        }
        if (value <= cur->key){
            insert(cur->left, value);
        }
        else{
            insert(cur->right, value);
        }
    }

    void insert(int value){
        insert(root, value);
    }

    void print(node *cur, int space = 0)
    {
        // Base case
        if (cur == NULL)
            return;

        // Increase distance between levels
        space += 10;

        // Process right child first
        print(cur->right, space);

        // Print current node after space
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
};

int main(){
    BST tree;
    int n;
    cin >> n;
    int input;
    for (int i=0; i<n; ++i){
        cin >> input;
        tree.insert(input);
    }
    tree.print();
}