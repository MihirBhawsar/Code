#include <iostream>
#include <vector>
using namespace std;

int fib(int x)
{
    if ((x == 1) || (x == 0))
    {
        return (x);
    }
    else
    {
        return (fib(x - 1) + fib(x - 2));
    }
}
int call(int n)
{
    if (n <= 1)
    {
        cout << "Base" << n<<endl;
        return n+1;
    }

    int count = 0;
    cout << "Pre-" << n << endl;
    count += call(n - 1);
    cout << "IN-" << n << endl;
    count += call(n - 2);
    cout << "Post-" << n << endl;

    return count + 3;
}

int main()
{
    // cout << fib(15);
    cout << call(5);
    return 0;
}