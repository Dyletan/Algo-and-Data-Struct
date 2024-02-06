#include <iostream>
using namespace std;

struct heap
{
    int n = 0;
    int a[100000];
    void heapify_down(int v)
    {
        int min = v;
        if (2 * v <= n && a[2 * v] < a[min])
        {
            min = 2 * v;
        }
        if (2 * v + 1 <= n && a[2 * v + 1] < a[min])
        {
            min = 2 * v + 1;
        }
        if (min == v)
            return;
        swap(a[min], a[v]);
        heapify_down(min);
    }
    void heapify_up(int v)
    {
        while (v != 1 && a[v / 2] > a[v])
        {
            swap(a[v / 2], a[v]);
            v = v / 2;
        }
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
};
