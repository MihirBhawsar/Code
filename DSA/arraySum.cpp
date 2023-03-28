#include <iostream>
#include <array>
#include <vector>
using namespace std;
void sumArray(vector<int> one,
              vector<int> two, int oneEnd, int twoEnd);
int main()
{
    vector<int> one = {9, 5, 4, 9};
    vector<int> two = {2, 1, 4};
    // vector<int> sum(3, 0);

    // for (int i = one.size() - 1; i >= 0; i--)
    // {
    //     sum[i] = one[i] + two[i];
    // }
    // for (int i = 0; i < sum.size(); i++)
    // {
    //     cout << sum[i];
    // }
    sumArray(one, two, one.size() - 1, two.size() - 1);
}

void sumArray(vector<int> one,
              vector<int> two, int oneEnd, int twoEnd)
{
    int size = max(oneEnd, twoEnd);
    vector<int> sum(size + 1, 0);
    int ep = size;
    int carry = 0;
    while (ep >= 00)
    {
        int add = carry;

        if (oneEnd>=0)
        {
           add+=one[oneEnd];
        }

        if (twoEnd>=0)
        {
            add+=two[twoEnd];
        }

        sum[ep] = add % 10;
        carry = add / 10;
        oneEnd--;
        twoEnd--;
        ep--;
    }

    for (int i = 0; i < sum.size(); i++)
    {
        cout << sum[i];
    }
}