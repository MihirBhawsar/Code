#include <iostream>
using namespace std;
int main()
{
    int value;
    cout << "enter a number" << endl;
    cin >> value;

    // if (value > 0)
    // {
    //     cout << "number is positive";
    // }
    // else if (value < 0)
    // {
    //     cout << "number is negative";

    // }
    // else
    // {
    //     cout << "number is 0";
    // }

    if (value != 0)
    {
        if (value > 0)
        {
            cout << "number is positive";
        }
        else
        {
            cout << "number is negative";
        }
    }
    else
    {
        cout << "number is 0";
    }

    return 0;
}