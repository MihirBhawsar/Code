#include <iostream>
#include <vector>
#include <array>
#include <bits/stdc++.h>
using namespace std;
int maxRepeating(vector<int> &arr, int n, int k);
int main()
{

    vector<int> array = {1, 2, 10, 10, 25, 2, 5, 2, 10,10};
    //  int count,max=0,ele;

    //  for (int i = 0; i < array.size(); i++)
    //  {
    //     int count=0;
    //     for (int j = 0; j < array.size(); j++)
    //     {
    //         if(array[i]==array[j]){
    //             count++;
    //         }
    //     }
    //     if(max<count){
    //         max=count;
    //         ele=array[i];
    //     }

    //  }

    // cout<<ele<<endl;
    // sort(array.begin(), array.end());
    // for (int i = 0; i < array.size(); i++)
    // {
    //     for (int j = i + 1; j < array.size(); j++)
    //     {
    //         if (array[i] == array[j])
    //         {
    //             cout << array[i] << endl;
    //             break;
    //         }
    //     }
    // }
    // int count = 0;
    // while (count < array.size()-1)
    // {
    //     if (array[count] == array[count + 1])
    //     {
    //         cout << array[count]<<endl;
    //     }
    //     count++;
    // }

    cout << maxRepeating(array, array.size(), array.size());
}

int maxRepeating(vector<int> &arr, int n, int k)
{
    // Iterate though input array, for every element
    // arr[i], increment arr[arr[i]%k] by k
    for (int i = 0; i < n; i++)
    {
        arr[arr[i] % k] += k;
        cout << arr[i] << endl;
    }

    // Find index of the maximum repeating element
    int max = arr[0], result = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            result = i;
        }
    }

    /* Uncomment this code to get the original array back
       for (int i = 0; i< n; i++)
          arr[i] = arr[i]%k; */

    // Return index of the maximum element
    return result;
}

