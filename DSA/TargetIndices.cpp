#include <iostream>
#include <array>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

int lowerBond(vector<int> &nums, int target)
{
    int si = 0, ei = nums.size() - 1, mid;
    while (si <= ei)
    {
        mid = ((si + ei) / 2);
        if (nums[mid] == target)
        {
            if (mid > 0 && nums[mid - 1] == target)
            {
                ei = mid - 1;
            }
            else
            {
                return mid;
            }
        }
        else if (nums[mid] > target)
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
int upperBond(vector<int> &nums, int target)
{
    int si = 0, ei = nums.size() - 1, mid;
    while (si <= ei)
    {
        mid = ((si + ei) / 2);
        if (nums[mid] == target)
        {
            if (mid < nums.size() && nums[mid + 1] == target)
            {
                si = mid + 1;
            }
            else
            {
                return mid;
            }
        }
        else if (nums[mid] > target)
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
vector<int> targetIndices(vector<int> &nums, int target)
{
    vector<int> arr;
    sort(nums.begin(), nums.end());
    int si = lowerBond(nums, target);
    // cout<<"Si"<<si;
    int ei = upperBond(nums, target);
        // cout<<"ei"<<ei;

    if (si == -1)
    {
        return arr;
    }

    for (int i = si; i <= ei; i++)
    {
        arr.push_back(i);
    }
    return arr;
}

int main()
{
    vector<int> arr={1,1,2,5,2,3,2};
    vector<int> target=targetIndices(arr,2);
    for (int i = 0; i < target.size(); i++)
    {
    cout<<target[i]<<" ";
    }
    
}