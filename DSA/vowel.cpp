#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    char x;
    cout << "please enter char" << endl;
    cin >> x;
    if (x == 'a' || x == 'e' ||x == 'i' ||x == 'o' ||x == 'u')
    {
        cout << "Number is vowel";
    }
    else
    {
        cout << "Number is const";
    }
    return 0;
}