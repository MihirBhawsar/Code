#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack<string> st;

    st.push("Mihir");
    st.push("bhawsar");
    st.push("rahul");
    st.push("manish");

    // cout << st.top() << endl;

    // st.pop();
    // cout << st.top() << endl;
    // cout << st.size() << endl;
    // cout << st.empty() << endl;


    while (!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
   
    
}