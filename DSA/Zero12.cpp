#include <iostream>
#include <array>
#include <vector>
using namespace std;
void zero12(vector<int> &arr);
void swapTwoNumber(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{

    vector<int> sort = {0, 0, 1, 2, 1, 1, 2, 2, 0, 0, 1, 0, 1, 2, 2};

    zero12(sort);
    for (int i = 0; i < sort.size(); i++)
    {
        cout << sort[i] << " ";
    }
}

void zero12(vector<int> &arr)
{
    if (arr.size() == 0)
    {
        return;
    }

    int p = -1;
    int idx = 0;
    int n = arr.size();
    int las = n - 1;
    while (idx <= las)
    {
        if (arr[idx] == 0)
        {
            p++;
            swapTwoNumber(&arr[p], &arr[idx]);
            idx++;
        }
        else if (arr[idx] == 2)
        {
            swapTwoNumber(&arr[idx], &arr[las]);
            las--;
        }
        else
        {
            idx++;
        }
    }
    return;
}
