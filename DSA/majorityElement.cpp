#include <iostream>
#include <vector>
#include <array>
using namespace std;
int majorityElement(vector<int> &arr);

int main()
{
    vector<int> arr = {1, 1,1,1,2,2,6,4,5,3};
    cout <<"majorityElement"<< majorityElement(arr) << endl;
}
int majorityElement(vector<int> &arr)
{
    int ele = arr[0];
    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (count == 0)
        {
            ele = arr[i];

            cout<<ele<<endl;
        }
        count += (ele == arr[i]) ? 1 : -1;
    }
    return ele;
}