#include <iostream>
#include <array>
#include <bits/stdc++.h>
using namespace std;

class myQueue
{
    int totalSize, f, b;
    int element;
    int *arr;

protected:
    void init(int x)
    {
        this->arr = new int[x];
        this->totalSize = x;
        this->element = 0;
        this->f = 0;
        this->b = 0;
    }

public:
    myQueue()
    {
        init(10000);
    }
    myQueue(int x)
    {
        init(x);
    }

    bool isEmpty()
    {
        return this->element == 0;
    }

    int size()
    {
        return this->element;
    }

    void push(int val)
    {
        if (this->element == this->totalSize)
        {
            return;
        }
        this->arr[this->b] = val;
        this->b++;
        this->element++;
    }

    int front()
    {
        if (this->element == 0)
        {
            return -1;
        }
        return this->arr[this->f];
    }

    void pop()
    {
        if (this->element == 0 && this->f == this->totalSize)
        {
            /* code */
            return;
        }
        int ele = arr[this->f];
        this->arr[this->f] = 0;
        this->f++;
        this->element--;
    }

    int back()
    {
        if (this->element == 0 && this->element == this->totalSize)
        {
            /* code */
            return -1;
        }
        return this->arr[this->b];
    }

    void display()
    {
        if (this->element == 0)
        {
            return;
        }
        for (int i = this->f; i < this->b; i++)
        {
            cout << this->arr[i] << endl;
        }
    }

};

int main()
{

    myQueue ue;

    ue.push(25);
    ue.push(63);
    ue.push(87);
    ue.pop();
    ue.push(65);
    ue.push(99);
    ue.pop();
    ue.push(152);

    cout << ue.isEmpty() << endl;
    cout << ue.size() << endl;
    ue.display();
    return 0;
}