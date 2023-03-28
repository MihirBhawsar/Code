#include <iostream>
#include <array>
#include <vector>
// #include <cmath>
// #include <stdint.h>
// #include <limits>
using namespace std;

vector<int> subarraySum(vector<int> arr, int n, long long s)
{

    vector<int> subArr;

    int i, si = 0, currentSum = arr[0];

    for (i = 1; i < n; i++)
    {

        if (currentSum > s )
        {
            currentSum -= arr[si];
            si++;
        }
        cout<<currentSum<<endl;
        if (currentSum == s)
        {
            subArr.push_back(si + 1);
            subArr.push_back(i + 1);
            return subArr;
        }
        currentSum += arr[i];
    }
    subArr.push_back(-1);
    return subArr;
}
int main()
{
    vector<int> arr = {135, 101, 170, 125, 79, 159, 163, 65,
                       106, 146, 82, 28, 162, 92, 196, 143, 28, 37, 192, 5, 103, 154, 93,
                       183, 22, 117, 119, 96, 48, 127, 172, 139, 70, 113, 68, 100, 36, 95, 104, 12, 123, 134};

    vector<int> arr2 = subarraySum(arr, 42, 468);
    for (int i = 0; i < arr2.size(); i++)
    {
        cout << arr2[i] << " ";
    }
    return 0;
}