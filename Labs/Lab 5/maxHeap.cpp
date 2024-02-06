#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;

const int N = 1e5 + 7;

struct Heap
{
    int n = 0;
    int a[N];

    // Heap()
    // {
    //     n = 0;
    // }

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

    void heapify_down(int v)
    {
        int mx = v;
        int lchld = lchild(v);
        int rchld = rchild(v);
        if (lchld <= n && a[mx] < a[lchld])
            mx = lchld;
        if (rchld <= n && a[mx] < a[rchld])
            mx = rchld;
        if (mx == v)
            return;
        swap(a[mx], a[v]);
        heapify_down(mx);
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

    void push(int x)
    {
        n++;
        a[n] = x;
        heapify_up(n);
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
    int x, input;
    cin >> x;
    for (int i = 0; i < x; i++)
    {
        cin >> input;
        h.push(input);
    }

    while (h.n)
    {
        cout << h.top() << endl;
        h.pop();
    }
    return 0;
}