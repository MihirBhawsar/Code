#include <iostream>
using namespace std;
int main()
{
    int x = 0;
    cout << "enter number for prime element" << endl;
    cin >> x;
    bool isPrime=true;

    for (int i = 2; i <= x; i++)
    {
        isPrime=true;
        for (int j = 2; j <= i / 2; j++)
        {
            if (i % j == 0)
            {
                isPrime=false;
                break;
            }

        }
        if(isPrime){
            cout<<i<<"is prime number"<<endl;
        }
    }
}