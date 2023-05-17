#include <iostream>
#include <vector>

using namespace std;
void merge(vector<int> &arr, int si, int ei)
{
    int mid = (si + ei) / 2;
    int i = si;
    int j = mid + 1;
    int k = 0;
    vector<int> ans(ei - si + 1, 0);
    while (i <= mid && j <= ei)
    {
        if (arr[i] < arr[j])
        {
            ans[k++] = arr[i++];
        }
        else
        {
            ans[k++] = arr[j++];
        }
    }
    while (i <= mid)
    {
        ans[k++] = arr[i++];
    }
    while (j <= ei)
    {
        ans[k++] = arr[j++];
    }
    for (int idx = si; idx <= ei; idx++)
    {
        arr[idx] = ans[idx - si];
    }
}
void mergeSort(vector<int> &arr, int si, int ei)
{
    if (si < ei)
    {

        int mid = (ei + si) / 2;

        mergeSort(arr, si, mid);
        mergeSort(arr, mid + 1, ei);

        merge(arr, si, ei);
    }
}

int main()
{
    vector<int> arr = {5, 6, 9, 8, 2, 4, 7};
    mergeSort(arr, 0, arr.size() - 1);
    for (int idx = 0; idx < arr.size(); idx++)
    {
        cout << arr[idx] << endl;
    }
    return 0;
}
