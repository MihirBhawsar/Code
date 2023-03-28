#include <iostream>
#include <array>
#include <vector>
using namespace std;
void swapArray(vector<int> &vecArr, int sp, int ep);
void reverse(vector<int> &vecArr, int sp, int ep);

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    int k = 6;
    int n = arr.size();
    k = k % n;

    reverse(arr, 0, n - 1);
    reverse(arr, 0, k - 1);
    reverse(arr, k, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
void swapArray(vector<int> &vecArr, int sp, int ep)
{
    int temp = vecArr[sp];
    vecArr[sp] = vecArr[ep];
    vecArr[ep] = temp;
}
void reverse(vector<int> &vecArr, int sp, int ep)
{
    while (sp < ep)
    {
        swapArray(vecArr, sp, ep);
        sp++;
        ep--;
    }
}