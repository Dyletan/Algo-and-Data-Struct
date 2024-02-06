#include <iostream>
using namespace std;

const int N = 2e5 + 1;

struct Heap
{
    int n = 0;
    int a[N];

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
        n++;
        a[n] = v;
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

    void print(int index, int level = 0)
    {
        if (index > n)
        {
            return;
        }

        print(2 * index + 1, level + 1);

        for (int i = 0; i < level; i++)
        {
            cout << "    ";
        }

        cout << a[index] << endl;

        print(2 * index, level + 1);
    }
    void print(){
        print(1);
    }
    int find_sum(){
		int first = top();
		pop();
		int second = top();
		pop();
		push(first+second);
		return first + second;
	}
};


int main()
{
    int x;
    cin >> x;
    int input;
    Heap h;
    for (int i = 0; i < x; i++)
    {
        cin >> input;
        h.push(input);
    }
	int sum = 0;
    while (h.n > 1)
    {
		sum += h.find_sum();
    }
	cout << sum;
}