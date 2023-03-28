#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int count;
    cout << "please enter number" << endl;
    cin >> count;
    if (count != 0 && count > 0)
    {
        // for (size_t i = 0; i < count; i++)
        // {
        //     if (i == 5)
        //     {
        //         // break;
        //         continue;
        //     }
        // cout << i << endl;
        // }
        int i=0;
        while (i < count)
        {
             i++;
            if (i == 5)
            {
                // break;
                continue;
            }
            cout << i << endl;
           
        }
    }
    return 0;
}