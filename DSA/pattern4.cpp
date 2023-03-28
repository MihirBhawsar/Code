#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    cout << "enter Nth number" << endl;
    cin >> n;
    //----------------pattern 1--------------

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = n; j >i; j--)
    //     {
    //        cout<<"-";
    //     }
    //    cout<<"*"<<endl;

    // }
    //----------------pattern 1--------------

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         if (i + j == 6)
    //         {
    //             cout << "*" ;
    //         }
    //         else
    //         {
    //             cout << " ";
    //         }
    //     }
    //     cout << endl;
    // }
    //----------------pattern 2--------------
    //  for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         if (i == j )
    //         {
    //             cout << "*" ;
    //         }
    //         else
    //         {
    //             cout << "#";
    //         }
    //     }
    //     cout << endl;
    // }

    //----------------pattern 2--------------

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         if ((i == j) || ((i+j) == 6))
    //         {
    //             cout << "*";
    //         }
    //         else
    //         {
    //             cout << " ";
    //         }
    //     }
    //     cout << endl;
    // }
    //----------------pattern 3--------------

    // int i, j, mid;

    // if (n % 2 == 0)
    // {
    //     n++;
    // }
    // mid = (n / 2);
    // int outerSpace = n / 2;
    // int innerSpace = -1;
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= outerSpace; j++)
    //     {
    //         cout << " ";
    //     }
    //     cout << "*";
    //     for (int j = 1; j <= innerSpace; j++)
    //     {
    //         cout << " ";
    //     }
    //     if (i > 1 && i < n)
    //     {
    //         cout << "*";
    //     }
    //     if (i <= n / 2)
    //     {
    //         outerSpace--;
    //         innerSpace += 2;
    //     }
    //     else
    //     {
    //         outerSpace++;
    //         innerSpace -= 2;
    //     }

    //     cout << endl;
    // }

    //----------------pattern 4--------------
    int mid;
     if (n % 2 == 0)
    {
        n++;
    }
    mid = (n / 2);
    int outerSpace = n / 2;
    int innerSpace = -1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= outerSpace; j++)
        {
            cout << " ";
        }
        cout << "*";
        for (int j = 1; j <= innerSpace; j++)
        {
            cout << "*";
        }
        if (i > 1 && i < n)
        {
            cout << "*";
        }
        if (i <= n / 2)
        {
            outerSpace--;
            innerSpace += 2;
        }
        else
        {
            outerSpace++;
            innerSpace -= 2;
        }

        cout << endl;
    }

    //----------------pattern 5--------------
    // if (n % 2 == 0)
    // {
    //     n++;
    // }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         if (j == 1 || j == n)
    //         {
    //             cout << "*";
    //         }
    //         else if (i > n / 2 && (i == j || (i + j == n + 1)))
    //         {
    //             cout << "*";
    //         }
    //         else
    //         {
    //             cout << "-";
    //         }
    //     }
    //     cout << endl;
    // }
}