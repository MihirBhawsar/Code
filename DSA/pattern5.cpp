#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "enter number" << endl;
    cin >> n;

    // for (int i = 1; i <= n; i++)
    // {
    //     int printNum = i;
    //     for (int space = 1; space <= n - i; space++)
    //     {
    //         cout << "  ";
    //     }
    //     for (int num = 1; num <= (i * 2) - 1; num++)
    //     {
    //         cout << printNum << " ";
    //         if (num < i)
    //         {
    //             ++printNum;
    //         }
    //         else
    //         {
    //             --printNum;
    //         }
    //     }
    //     cout << endl;
    // }
    // for (int i = n - 1; i >= 1; i--)
    // {
    //     int printNum = i;
    //     for (int space = 1; space <= n - i; space++)
    //     {
    //         cout << "  ";
    //     }
    //     for (int num = 1; num <= (i * 2) - 1; num++)
    //     {
    //         cout << printNum << " ";
    //         if (num < i)
    //         {
    //             ++printNum;
    //         }
    //         else
    //         {
    //             --printNum;
    //         }
    //     }
    //     cout << endl;
    // }

    int sp = n / 2;
    int st = 1;
    int val = 1;

    for (int row = 1; row <= n; row++)
    {
        for (int col = 1; col <= sp; col++)
        {
            cout << "-";
        }
        int temp = val;
        for (int col = 1; col <= st; col++)
        {
            cout << temp;
            if (col <= st / 2)
            {
                temp++;
            }
            else
            {
                temp--;
            }
        }
        if (row <= n / 2)
        {
            st += 2;
            sp--;
            val++;
        }
        else
        {
            sp++;
            st -= 2;
            val--;
        }
        cout << endl;
    }
}