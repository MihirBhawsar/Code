#include <iostream>
#include <array>
#include <vector>
using namespace std;
    void positiveNegative(vector<int> & arr);
void swapTwoNumber(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
 
    vector<int> sort={4,-3,6,7,2,-8,-9,10,11,12,-19};
  
    positiveNegative(sort);
    for (int i = 0; i < sort.size(); i++)
    {
        cout << sort[i] << " ";
    }
}


    void positiveNegative(vector<int> & arr)
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
            if (arr[idx] < 0)
            {
                p++;
                swapTwoNumber(&arr[p], &arr[idx]);
            }
            idx++;
        }
        return;
    }
