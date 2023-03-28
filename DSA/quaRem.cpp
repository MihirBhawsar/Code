#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int x,y;
    cout << "please enter dividend " << endl;
    cin >> x;
    cout << "please enter divisor " << endl;
    cin >> y;
    
        cout << "quotient:-"<<x/y<<endl;
   
        cout << "remainder:-"<<x%y<<endl;
    
    return 0;
}