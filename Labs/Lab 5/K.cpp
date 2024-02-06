#include <iostream>
using namespace std;

const int N = 5e5 + 1;

struct Heap
{
    int n = 0;
    int k;
    int a[N];

    void heapify_down(int v)
    {
        while (true)
        {
            int mx = v;
            int lchld = lchild(v);
            int rchld = rchild(v);
            if (lchld <= n && a[mx] < a[lchld])
                mx = lchld;
            if (rchld <= n && a[mx] < a[rchld])
                mx = rchld;
            if (mx == v)
                break;
            swap(a[mx], a[v]);
            v = mx;
        }
    }

    void heapify_up(int v)
    {
        while (v != 1 && a[v] > a[parent(v)])
        {
            swap(a[v], a[parent(v)]);
            v = parent(v);
        }
    }

    int parent(int v)
    {
        return v / 2;
    }

    int lchild(int v)
    {
        return 2 * v;
    }

    int rchild(int v)
    {
        return 2 * v + 1;
    }

    int sum(){
        int sum = 0;
        for(int i = 1; i <= n; i++){
            sum += a[i];
        }
        return sum;
    }

    void push(int x)
    {
        if (n < k)
        {
            n++;
            a[n] = x;
            heapify_up(n);
            return;
        }
        for (int i = 1; i <= k; i++)
        {
            if (a[i] < x)
            {
                a[i] = x;
                swap(a[i], a[n]);
                heapify_up(n);
                return;
            }
        }
    }

    void pop()
    {
        swap(a[1], a[n]);
        n--;
        heapify_down(1);
    }

    int top()
    {
        return a[1];
    }
};

int main()
{
    Heap h;
    int x, k, input;
    cin >> x >> k;
    h.k = k;
    string str;
    for (int i = 0; i < x; i++)
    {
        cin >> str;
        if(str == "print"){
            cout << h.sum() << endl;
        }else{
            cin >> input;
            h.push(input);
        }
        
    }
}