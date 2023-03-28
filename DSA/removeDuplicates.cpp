#include <iostream>
#include <vector>
#include <array>
using namespace std;

vector<int> searchRange(vector<int> &nums, int t)
{
    vector<int> arr = {-1, -1};
    int n = nums.size();
    int si = 0, ei = n - 1, mid = 0, l , f ;
    while (si <= ei)
    {
        mid = si +((si- ei) / 2);
        
        if (nums[mid] == t)
        {
            f = mid;
            l = mid;
           
            while (f >= 0)
            {
                cout<<"f"<<f;
                if (f != 0 && nums[f - 1] == t)
                {
                    f--;
                }
                else
                {
                    
                    arr[0] = f;
                    break;
                }
            }
            while (l < n)
            {

                if (l != n && nums[l + 1] == t)
                {
                    l++;
                }
                else
                {
                    arr[1] = l;
                    break;
                }
            }
            break;
        }
        else if (nums[mid] < t)
        {
            si = mid + 1;
        }
        else
        {
            ei = mid - 1;
        }
    }
    return arr;
}

int main()
{
    vector<int> nums = {1};
    vector<int> k = searchRange(nums, 1);
    for (int i : k)
    {
        cout << i << " ";
    }
}