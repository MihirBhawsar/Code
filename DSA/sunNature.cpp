#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int count;
    cout << "please enter number" << endl;
    cin >> count;
    int sum = 0;
    for (size_t i = 0; i < count; i++)
    {
        sum += i;
    }

    cout << sum << endl;

    return 0;
}