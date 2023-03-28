#include <iostream>
#include <array>
#include <vector>
using namespace std;
int lastIndexOfElement(vector<int> &arr, int ele);
int firstIndex(vector<int> &arr, int tar);
int nearIndex(vector<int> &arr, int ele);
int findIndex(vector<int> &arr, int tar);
int main()
{

    vector<int> arr = {1, 3, 12, 14, 23, 34, 55, 65, 75, 78};
    // cout << lastIndexOfElement(arr, 6);
    // cout << firstIndex(arr, 6);
    // cout << nearIndex(arr, 45);
    cout << findIndex(arr, 3);
}

int findIndex(vector<int> &arr, int tar)
{
    int si = 0;
    int ei = arr.size()-1;
    int mid = 0;
    while (si <= ei)
    {
        mid = (si + ei) / 2;
        if (arr[mid] == tar)
        {
            return mid;
        }
        else if (arr[mid] > tar)
        {
            ei = mid - 1;
        }
        else
        {
            si = mid + 1;
        }
    }
    return -1;
}

int firstIndex(vector<int> &arr, int tar)
{
    int si = 0;
    int n = arr.size();
    int ei = n - 1;

    while (si <= ei)
    {
        int mid = (si + ei) / 2;
        if (arr[mid] == tar)
        {
            if (mid - 1 > 0 && arr[mid] == tar)
            {
                ei = mid - 1;
            }
            else
            {
                return mid;
            }
        }
        else if (arr[mid] > tar)
        {
            ei = mid - 1;
        }
        else
        {
            si = mid + 1;
        }
    }
    return -1;
}
int lastIndexOfElement(vector<int> &arr, int ele)
{
    int f = 0;
    int l = arr.size() - 1;
    int m = (f + l) / 2;

    while (f <= l)
    {
        m = (f + l) / 2;
        if (arr[m] == ele)
        {
            if (arr[m] < arr.size() && arr[m + 1] == ele)
            {
                f = m + 1;
            }
            else
            {
                return m;
            }
        }
        else if (arr[m] > ele)
        {
            l = m - 1;
        }
        else
        {
            f = m + 1;
        }
    }
    return -1;
}

int nearIndex(vector<int> &arr, int ele)
{
    int f = 0;
    int l = arr.size() - 1;
    int m;

    while (f <= l)
    {
        m = (f + l) / 2;
        if (arr[m] == ele)
        {
            return m;
        }

        if (arr[m] > ele)
        {
            l = m - 1;
        }
        else
        {
            f = m + 1;
        }
    }
    return ((ele - arr[l]) < (arr[f] - ele) ? l : f);
}