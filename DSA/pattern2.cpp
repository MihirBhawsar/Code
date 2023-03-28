#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    cout << "enter Nth number" << endl;
    cin >> n;

    // for (int j = 1; j <= n; j++)
    // {
    //     for (int i = n; i > j; i--)
    //     {
    //         cout << " ";
    //     }
    //     for (int k = 0; k < j; k++)
    //     {
    //     cout << "*" ;
    //     }
    //     cout<<endl;

    // }
    for (int j = 1; j <= n; j++)
    {
        for (int k = 1; k < j; k++)
        {
            cout << " ";
        }
        for (int i = n; i >= j; i--)
        {
            cout << "*";
        }

        cout << endl;
    }
}