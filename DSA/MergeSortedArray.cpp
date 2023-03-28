#include <iostream>
#include <array>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
vector<int> merge(vector<int> &nums1, int m, vector<int> &nums2, int n);
int main()
{
    vector<int> arr = {1, 2, 5, 6, 8, 10, 12, 18};
    vector<int> arr2 = {2, 3, 4, 7, 8, 9};

    vector<int> mergeArr = merge(arr, arr.size(), arr2, arr2.size());

    for (int i : mergeArr)
    {
        cout << i << " ";
    }
}
vector<int> merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int length = m + n ;
    vector<int> newArr(length, 0);
    int p = 0, q = 0, i = 0;
    while (p < m || q < n)
    {
        if (nums1[p] <= nums2[q])
        {
            newArr[i] = nums1[p];
            p++;
        }
        else
        {
            newArr[i] = nums2[q];
            q++;
        }
        i++;
    }
    while (p < m)
    {
        newArr[i] = nums1[p];
        p++;
        i++;
    }
    while (q < n)
    {
        newArr[i] = nums2[q];
        q++;
        i++;
    }
    return newArr;
}