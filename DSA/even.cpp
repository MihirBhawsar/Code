#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int x;
    cout << "please enter number" << endl;
    cin >> x;
    if (x % 2 == 0)
    {
        cout << "Number is even";
    }
    else
    {
        cout << "Number is odd";
    }
    return 0;
}
