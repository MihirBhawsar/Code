#include <iostream>
#include <array>
#include <vector>
using namespace std;
int main()
{
}

vector<int> getConcatenation(vector<int> &nums)
{
    int n = nums.size();

    vector<int> array(n * 2, 0);
    for (int i = 0; i < array.size(); i++)
    {
        if (i < n)
        {
            array[i] = nums[i];
        }
        else
        {
            array[i] = nums[i - n];
        }
    }

    return array;
}
