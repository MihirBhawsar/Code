#include <iostream>
#include <array>
#include <vector>
using namespace std;

vector<int> runningSum(vector<int> &array)
{
    vector<int> newArray(array.size(), 0);
    for (int j = 0; j < array.size(); j++)
    {
        int sum = 0;

        for (int i = 0; i <=j; i++)
        {
            sum += array[i];
        }

        newArray[j] = sum;
    }
    return newArray;
}
int main()
{

    vector<int> sort = {1, 2, 3, 4};

    vector<int> runningSumArray = runningSum(sort);
    for (int i = 0; i < runningSumArray.size(); i++)
    {
        cout << runningSumArray[i] << " ";
    }
}


