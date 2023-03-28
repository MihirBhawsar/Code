#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "enter number" << endl;
    cin >> n;

    int space = n - 2;

    for (int i = 1; i <= (n / 2) + 1; i++)
    {
        for (int k = 1; k <= n; k++)
        {
            for (int i = 1; i <= i; i++)
            {
                cout << "1";
            }
            
        }

        cout << endl;
    }
    // ---------------------------------pattern 2----------------

    // int space=n-2;

    // for (int i = 1; i <= (n/2)+1; i++)
    // {
    //     for (int k = 1; k <=i; k++)
    //     {
    //        cout<<k;
    //     }

    //    for (int j = 1; j <=space; j++)
    //    {
    //         cout<<"-";
    //    }
    //    for (int l = i; l <=i; l++)
    //    {
    //     cout<<l;
    //    }
    //    space-=2;

    //     cout<<endl;

    // }
    // --------------------------pattern 3-----------------
    // if (n % 2 == 0)
    // {
    //     n++;
    // }
    // int star = n;
    // int rSpace = 0;
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int space = 1; space <= rSpace; space++)
    //     {
    //         cout << "-";
    //     }

    //     for (int j = 1; j <= star; j++)
    //     {
    //         cout << "*";
    //     }
    //     if (i < (n / 2) + 1)
    //     {
    //         star -= 2;
    //         rSpace++;
    //     }
    //     else
    //     {
    //         star += 2;
    //         rSpace--;
    //     }
    //     cout << endl;
    // }
}