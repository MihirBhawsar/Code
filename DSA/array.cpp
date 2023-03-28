#include <iostream>
#include<array>
#include<vector>
using namespace std;
int main()
{
    // int arr[] = {1, 2, 3, 4, 5, 6};

    // cin >> arr[1];
    // cout << arr[1] << endl;

    // for (int i = 0; i < 6; i++)
    // {
    //     cout << arr[i] << endl;
    // }
    // arr[5] = 50;
    // int arrSize = sizeof(arr) / sizeof(arr[0]);

    // for (int j = 0; j < arrSize; j++)
    // {
    //     cout << arr[j] << endl;
    // }

    // int gra[10];
    // for (size_t i = 0; i < 10; i++)
    // {
    //     cout << gra[i] << endl;
    // }

    // array<int,10> myArray{10,12,52,2,3,5};

    // for (int i = 0; i < myArray.size(); i++)
    // {
    //    cout<<myArray[i]<<endl;
    // }

    vector<int> vecArr(5,0);
    vecArr.push_back(10);
    vecArr.push_back(23);
    vecArr.push_back(45);
    vecArr[2]=10;
    for (int i = 0; i < vecArr.size(); i++)
    {
        cout<<vecArr[i]<<" ";
    }
    
    
}