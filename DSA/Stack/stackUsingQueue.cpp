#include <iostream>
#include <array>
#include <bits/stdc++.h>
using namespace std;

class myStack
{
    queue<int> q1, q2;

public:
    void push(int x)
    {
        q2.push(x);

        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        queue<int> q = q1;
        q1 = q2;
        q2 = q;
    }

    void pop()
    {
        if (q1.empty())
        {
            return;
        }

        q1.pop();
    }

    int top()
    {
        if (q1.empty())
        {
            return -1;
        }
        return q1.front();
    }
};

int main()
{

    myStack st;

    st.push(25);
    st.push(63);
    st.push(87);
    st.push(65);
    st.push(99);
    st.push(152);

    // cout << st.isEmpty() << endl;
    // cout << st.size() << endl;
    // st.display();
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    return 0;
}