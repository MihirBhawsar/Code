#include <iostream>
// #include <array>
// #include <vector>
// #include <cmath>
// #include <stdint.h>
// #include <limits>
using namespace std;

int findElement(int arr[], int n)
{
    int lMax[n];
    int rMin[n];
    lMax[0] = -1;
    rMin[n - 1] = -1;
    int leftMax = arr[0];
    for (int i = 1; i < n; i++)
    {
        lMax[i] = leftMax;
        leftMax = max(leftMax, arr[i]);
    }
    int rightMin = arr[n - 1];
    for (int j = n - 2; j >= 0; j--)
    {
        rMin[j] = rightMin;
        rightMin = min(rightMin, arr[j]);
    }
      for (auto &&i : lMax)
    {
        cout<<i<<" ";
    }
    cout<<endl;
      for (auto &&i : rMin)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    
    for (int k = 1; k < n -1; k++)
    {
        if ((arr[k] >= lMax[k]) && (arr[k] <= rMin[k]))
        {
            return arr[k];
        }
    }
    return -1;
}

int main()
{
    int arr[] = {10, 6 ,3, 1, 5, 11, 6, 1, 11 ,12};
    cout << findElement(arr, 10);
}