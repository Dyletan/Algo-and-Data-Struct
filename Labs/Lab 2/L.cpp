# include <iostream>
# include <algorithm>
# include <cassert>

using namespace std;

struct Node {
  int val;
  Node *next;

  Node() {
    val = 0;
    next = NULL;
  }

};

int findMaxSum(int n, Node *head) {
	int absolute_max = head->val;
  int temp_max = head->val;
  Node* cur = head->next;

  while(cur){
    if(cur->val > temp_max+cur->val){
      temp_max = cur->val;
    }
    else{
      temp_max += cur->val;
    }
    if(temp_max > absolute_max){
      absolute_max = temp_max;
    }
    cur = cur->next;
  }

  return absolute_max;
	
}

int main() {
  int n;
  cin >> n;

  Node *head, *tail;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    Node* cur = new Node();
    cur -> val = x;

    if (i == 1) {
      head = tail = cur;
    } else {
      tail -> next = cur;
      tail = cur;
    }
  }

  cout << findMaxSum(n, head) << "\n";
  return 0;
}
