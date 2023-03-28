#include<iostream>
using namespace std;
int main(){
    int n = 0;
    cout << "enter Nth number" << endl;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
       for (int j = 1; j <= i; j++)
       {
        cout<<j;
       }
       cout<<endl;
       
    }

// -----------------------pattern 2-------------------
// int count=1;
//     for (int i = 1; i <= n; i++)
//     {
//        for (int j = 1; j <= i; j++)
//        {
//         cout<<count++<<" ";
//        }
//        cout<<endl;
       
//     }
    
}