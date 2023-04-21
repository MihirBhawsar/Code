#include <iostream>
#include <vector>
using namespace std;

class arrayStack
{
private:
    /* data */
    int n = 10000;
    int tos = -1;
    int sz = 0;
    int *arr;

public:
    arrayStack()
    {
        this->arr = new int[n];
    }
    arrayStack(int size)
    {
        this->arr = new int[size];
        this->n = size;
    }

    int size()
    {
        return this->sz;
    }

    bool empty()
    {
        return sz == 0;
    }

    void push(int val)
    {
        if (sz == n)
        {
            return;
        }
        tos++;
        sz++;
        arr[tos] = val;
    }

    void pop()
    {
        if (sz == 0)
        {
            return;
        }
        int rv = arr[tos];
        tos--;
        sz--;
    }

    int top()
    {
        if (sz == 0)
        {
            return -1;
        }
        return arr[tos];
    }
};

void solve()
{
    arrayStack st(5);

    for (int i = 1; i <= 10; i++)
    {
        st.push(10 * i);
    }

    while (st.size() != 0)
    {
        cout << st.top() << " ";
        st.pop();
    }
}

int main()
{
    solve();
    return 0;
}
