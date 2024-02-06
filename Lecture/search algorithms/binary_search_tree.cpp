#include <iostream>
using namespace std;

struct node {
    node* left;
    node* right;
    int key;
    // string data;

    node(int _key = 0){
        left = right = 0;
        key = _key;
    }

    node(int key, node* left, node* right)
        : key(key), left(left), right(right){
    }
    void insert(int x){
        node* next = NULL;
        if (x <= key){
            if(left == NULL){
                left = new node(x);
                return;
            }
            next = left;
        }
        else{
            if (right == NULL){
                right = new node(x);
                return;
            }
            next = right;
        }

        next->insert(x);
    }

    node* find(int x){
        node* next = NULL;
        if (x == key){
            return this; // this references current instance
                         // of the struct 
        }
        else if (x < key){
            return left == NULL ? NULL : left->find(x);
        }
    }

    void del(int x){

    }
};

int main(){
    node b;

}