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

int max_height = - 1;

struct BST{
    Node* root = NULL;

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

    int height(Node *cur){
        if(!cur)return 0;
        return 1 + max(height(cur->right), height(cur->left));
    }

    int diameter(Node* cur){
        if(!cur) return 0;
        int lheight = height(cur->left);
        int rheight = height(cur->right);

        int ldiameter = diameter(cur->left);
        int rdiameter = diameter(cur->right);

        return max(lheight + rheight + 1, max(ldiameter, rdiameter));
    }

    int diameter(){
        return diameter(root);
    }

    // void _height(Node* cur){
    //     int cur_len = 1 + height(cur->right) + height(cur->left);
    //     if(cur_len > max_height){
    //         max_height = cur_len;
    //     }
    // }

    // int height(){
    //     _height(root);
    //     return max_height;
    // }
};

int main(){
    int n, value;
    cin >> n;
    BST bst;
    while(n--){
        cin >> value;
        bst.insert(value);
    }
    // cout << bst.height(bst.root->right) <<  " " << bst.height(bst.root->left) << endl;
    cout << bst.diameter();
}