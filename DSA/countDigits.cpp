#include <iostream>
using namespace std;
int main()
{
    int x;
    cout << "enter value" << endl;
    cin >> x;
    int count = 0;

    while (x != 0)
    {
        x = x / 10;
        count++;
    }

    cout << "digit length :-" << count << endl;
}