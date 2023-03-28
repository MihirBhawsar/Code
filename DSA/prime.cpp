#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int x = 0;
    bool prime = true;
    cout << "please enter number " << endl;
    cin >> x;

    if (x == 0 || x == 1 || x==2)
    {
        cout << "number is  prime" << endl;
        return 0;
    }
    {
        /* code */
    }

    for (int i = 2; i <= (x / 2); i++)
    {
        if (x % i == 0)
        {
            prime = false;
            break;
        }
    }
    if (prime)
    {
        cout << "number is  prime" << endl;
    }
    else
    {
        cout << "number is not prime" << endl;
    }

    return 0;
}