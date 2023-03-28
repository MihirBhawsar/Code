#include <iostream>
#include <array>
#include <vector>
using namespace std;
int main()
{
    vector<int> arr = {1, 2, 3, 4};
    int size = arr.size();
    int n = (size * (size + 1)) / 2;
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            for (int k = i; k <=j; k++)
            {
                cout << arr[k];
            }
            cout<<endl;
        }
        // cout<<endl;
    }
}