#include <iostream>
#include <vector>
#include <array>
using namespace std;
int findElement(vector<int> &arr, int num);
int maxValue(vector<int> &arr);
int minValue(vector<int> &arr);
int occurring(vector<int> &arr);
int repeating(vector<int> &arr);
int main()
{
    vector<int> myArr(5, 0);
    int n = 0;
    // cout << "enter size of array" << endl;
    // cin>>n;5

    cout << "enter array value"<<endl;
    for (int i = 0; i < myArr.size(); i++)
    {
        cin >> myArr[i];
    }
    // int num = 0;
    // cout << "find number in array";
    // cin >> num;
    // cout << "number found at index" << findElement(myArr, num)<<endl;
    // cout << "max number in array" << maxValue(myArr) << endl;
    // cout << "min number in array" << minValue(myArr) << endl;

    cout<<"Max occurring element in Array:-"<<occurring(myArr)<<endl;

    repeating(myArr);
}

int findElement(vector<int> &arr, int num)
{

    for (int i = 0; i < arr.size(); i++)
    {
        if (num == arr[i])
        {
            return i;
        }
    }
    return -1;
}

int maxValue(vector<int> &arr)
{
    int max = INT8_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}
int minValue(vector<int> &arr)
{
    int min = INT8_MAX;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}

int occurring(vector<int> &arr)
{
    int max = 1;
    int element = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < arr.size(); j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
        if (max < count)
        {
            max = count;
            element = arr[i];
        }
    }
    return element;
}
int repeating(vector<int> &arr)
{
   vector<bool>visited(arr.size(),false);

    for (int i = 0; i < arr.size(); i++)
    {
        if (visited[i]==true){
            continue;
        }
       
        int count = 1;
        for (int j = i+1; j < arr.size(); j++)
        {
            if (arr[i] == arr[j])
            {
                visited[j]=true;
                count++;
            }
        }
      cout<<arr[i]<<":-repeating times :-" <<count<<endl;
    }
    return 0;
}