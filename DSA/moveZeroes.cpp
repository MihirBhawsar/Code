

#include <iostream>
#include <array>
#include <vector>
using namespace std;
void moveZeroes(vector<int> &nums);
void swapTwoNumber(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    vector<int> nums = {0, 1, 0, 3, 12};
    moveZeroes(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
}
void moveZeroes(vector<int> &nums)
{
    int n = nums.size();
        int nextZeros = 0;
        for(int i=0; i<n; i++){
            if(nums[i] != 0){
                int temp = nums[i];
                nums[i] = nums[nextZeros];
                nums[nextZeros] = temp;
                nextZeros++;
            }
        }
    }

