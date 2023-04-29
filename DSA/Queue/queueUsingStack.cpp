#include <iostream>
#include <array>
#include <bits/stdc++.h>
using namespace std;

class myQueue
{
    stack<int> s1, s2;

public:
    void push(int x)
    {
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        
    }

    int pop()
    {
        if(s1.empty()){
            return -1;
        }
        int ele=s1.top();
        s1.pop();
        return ele;
    }
};

int main()
{

    myQueue ue;

    ue.push(25);
    ue.push(63);
    ue.push(87);
    ue.push(65);
    ue.push(99);
    ue.push(152);

    // cout << ue.isEmpty() << endl;
    // cout << ue.size() << endl;
    // ue.display();
    cout<<ue.pop()<<endl;
    cout<<ue.pop()<<endl;
    cout<<ue.pop()<<endl;
    return 0;
}