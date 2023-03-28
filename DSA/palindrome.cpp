#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int x = 0, y = 0,z=0;
    cout << "please enter number " << endl;
    cin >> x;
    z=x;
    while (x != 0)
    {
        y = (y * 10) + (x % 10);
        x = x / 10;
    }
    if (z == y)
    {
        cout << " number is palindrome  " << y << endl;
    }
    else
    {
        cout << " number is not  palindrome  " << y << endl;
    }

    return 0;
}