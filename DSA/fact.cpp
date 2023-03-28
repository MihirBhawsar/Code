#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int count;
    cout << "please enter number" << endl;
    cin >> count;
    long sum = 1;
    if (count != 0 && count > 0)
    {
        for (size_t i = 0; i < count; i++)
        {
            sum *= (i + 1);
        }

        cout << sum << endl;
    }
    return 0;
}