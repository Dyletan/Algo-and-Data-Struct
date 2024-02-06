#include <iostream>
using namespace std;

const int N = 2e5 + 1;

struct Heap
{
    int n = 0;
    int a[N];
    int k;

    void heapify_down(int v)
    {
        while (true)
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
            if (v == min)
            {
                break;
            }
            swap(a[min], a[v]);
            v = min;
        }
    }

    void heapify_up(int v)
    {
        while (v != 1 && a[v] < a[v / 2])
        {
            swap(a[v], a[v / 2]);
            v = v / 2;
        }
    }

    void push(int v)
    {   
        if(n<k){
            n++;
            a[n] = v;
            heapify_up(n);
        } 
        else{
            if(v>top()){
                a[1] = v;
                heapify_down(1);
            }
        } 
    }

    long long sum()
    {
        long long sum = 0;
        for (int i = 1; i <= n; i++)
        {
            sum += a[i];
        }
        return sum;
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
        if (str == "print")
        {
            cout << h.sum() << endl;
        }
        else
        {
            cin >> input;
            h.push(input);
        }
    }
}