#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int x=0, y = 0;
    cout << "please enter number " << endl;
    cin >> x;
    while (x !=0)
    {
        y = (y*10)+(x % 10);
        //  y = y * 10;
        x = x / 10;
       
    }

    cout << "reverse number " << y << endl;

    return 0;
}