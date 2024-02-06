#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* nxt = 0;

    node(int _data, node* _nxt){
        data = _data;
        nxt = _nxt;
    }
};

struct llist{
    node* head = 0;
    node* tail = 0;

    void insert(node* b){
        if(!head){
            head = b;
            tail = b;
        }
        else{
            tail->nxt = b;
            tail = b;
        }
    }
    
    int minDiff(int k){
        int cnt = 0;
        int result;
        int min = 999999999;
        node* cur = head;
        while(cur){
            int dif = abs(k-cur->data);
            if(dif<min){
                min = dif;
                result = cnt;
            }
            cnt++;
            cur = cur->nxt;
        }
        return result;
    }
};

int main(){
    int n;
    cin >> n;
    int input;
    llist a;
    for(int i = 0; i < n; i++){
        cin >> input;
        node* new_node = new node(input, 0);
        a.insert(new_node);
    }
    int k;
    cin >> k;
    cout << a.minDiff(k);
}



