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
        return 1 + max(height(cur->left), height(cur->right));
    }

    int height(){
        return height(root);
    }

    void sumLevels(vector<int> &v, int level, Node *cur){
        if(!cur)return;
        v[level] += cur->key;
        sumLevels(v, level + 1, cur->left);
        // cout << cur->key << ' ' << level << endl;
        sumLevels(v, level + 1, cur->right);
    }

    void sumLevels(vector<int> &v){
        sumLevels(v, 0, this->root);
    } 
};

int main() {
    
    int n, value;
    cin >> n;
    BST bst;
    while(n--){
        cin >> value;
        bst.insert(value);
    }
    int h = bst.height();
    cout << h << endl;
    vector<int> res(h);

    bst.sumLevels(res);

    for(int i : res){
        cout << i << " ";
    }
    return 0;
}
    
    