#include <iostream>
#include <array>
#include <vector>
using namespace std;
void ZeroSort(vector<int> &array);
void segregateZeroesAndOnes(vector<int> &arr);
void swapTwoNumber(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int n = 0;
    cout << "enter arr size:-" << endl;
    cin >> n;
    vector<int> sort(n, 0);
    cout << "enter array element" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> sort[i];
    }
    ZeroSort(sort);
    for (int i = 0; i < n; i++)
    {
        cout << sort[i] << " ";
    }
}

void ZeroSort(vector<int> &array)
{
    int i = 0;
    int j = array.size() - 1;

    while (i <= j)
    {

        if (array[i] == 1 && array[j] == 0)
        {
            swapTwoNumber(&array[i], &array[j]);
            // i++;
            // j--;
        }

        if (array[i] == 0)
        {
            i++;
        }
        if (array[j] == 1)
        {
            j--;
        }
    }

    void segregateZeroesAndOnes(vector<int> & arr)
    {
        if (arr.size() == 0)
        {
            return;
        }

        int p = -1;
        int idx = 0;
        int n = arr.size();

        while (idx < n)
        {
            if (arr[idx] == 0)
            {
                p++;
                swap(arr, p, idx);
            }
            idx++;
        }
        return;
    }
}