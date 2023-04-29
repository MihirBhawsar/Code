#include <iostream>
#include<array>
#include<vector>
#include<queue>
using namespace std;
int main()
{
    queue<int>ue;
    ue.push(25);
    ue.push(63);
    ue.push(87);
    ue.pop();
    ue.push(65);
    ue.push(99);
    ue.pop();
    ue.push(152);

    cout<<ue.empty()<<endl;
    cout<<ue.size()<<endl;

    while(!ue.empty()){
        cout<<ue.front()<<endl;
        ue.pop();
    }
}