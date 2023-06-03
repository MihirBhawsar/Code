#include <iostream>
#include <vector>
#include <utility>
using namespace std;
bool compareTo(vector<int> &arr, bool isIncreasing, int i, int j)
{
    if (isIncreasing)
    {
        return arr[i] > arr[j];
    }
    else
    {
        return arr[j] > arr[i];
    }
}
void downHeapify(vector<int> &arr, bool isIncreasing, int pi, int ei)
{ // o(logn)
    int maxIdx = pi;
    int lci = 2 * pi + 1;
    int rci = 2 * pi + 2;

    if (lci <= ei && compareTo(arr, isIncreasing, lci, maxIdx))
    {
        maxIdx = lci;
    }

    if (rci <= ei && compareTo(arr, isIncreasing, rci, maxIdx))
    {
        maxIdx = rci;
    }

    if (maxIdx != pi)
    {
        swap(arr[maxIdx], arr[pi]);
        downHeapify(arr, isIncreasing, maxIdx,ei);
    }
}
void heapSort(vector<int> &arr, bool isIncreasing)
{
    int ei = arr.size()-1;
    for (int i = ei; i >= 0; i--)
    {
        downHeapify(arr, isIncreasing, i, ei);
    }
    while (ei >= 0)
    {
        swap(arr[0], arr[ei--]);
        downHeapify(arr, isIncreasing, 0, ei);
    }
}

int main()
{
    vector<int> arr = {10, 20, 30, -2, -3, -4, 5, 6, 7, 8, 9, 22, 11, 13, 14};
    heapSort(arr,true);
    for(int ele:arr){
        cout<<ele<<" ";
    }
    return 0;
}