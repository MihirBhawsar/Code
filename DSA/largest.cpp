#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int x, y, z;
    cout << "please enter three number" << endl;
    cin >> x;
    cin >> y;
    cin >> z;
    if (x > y && x > z)
    {
        cout << x << " is larger";
      
    }
    else if (x < y && y > z)
    {
        cout << y << " is larger";
    }
    else
    {
        cout << z << " is larger";
    }
    return 0;
}