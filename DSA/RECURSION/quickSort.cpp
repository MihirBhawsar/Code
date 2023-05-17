#include <iostream>
#include <vector>
using namespace std;

int partitions(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int si = low;
    int ei = high;
    while (si < ei)
    {
        while (si <= high && arr[si] <= pivot)
        {
            si++;
        }
        while (ei >= low && arr[ei] > pivot)
        {
            ei--;
        }
        if (si < ei)
        {
            int t = arr[si];
            arr[si] = arr[ei];
            arr[ei] = t;
        }
    }

    arr[low] = arr[ei];
    arr[ei] = pivot;

    return ei;
}

void quickSort(vector<int> &arr, int si, int ei)
{
    if (si < ei)
    {
        int p = partitions(arr, si, ei);
        quickSort(arr, si, p - 1);
        quickSort(arr, p + 1, ei);
    }
}

int main()
{
    vector<int> arr = {5, 2, 4, 6, 8, 9, 7, 3};
    quickSort(arr, 0, arr.size() - 1);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}