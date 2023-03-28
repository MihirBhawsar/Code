#include <iostream>
#include <array>
#include <vector>
using namespace std;
void subArray(vector<int> one,
              vector<int> two, int oneEnd, int twoEnd);

void subArrayNew(vector<int> one,
                 vector<int> two);
int main()
{
    vector<int> one = {9, 9, 9};
    vector<int> two = {1, 1, 1};

    // subArray(one, two, one.size() - 1, two.size() - 1);

    subArrayNew(one, two);
}

void subArray(vector<int> one,
              vector<int> two, int oneEnd, int twoEnd)
{
    vector<int> temp;
    int tempEnd;
    if (oneEnd < twoEnd || one[0] < two[0])
    {
        temp = one;
        one = two;
        two = temp;

        tempEnd = oneEnd;
        oneEnd = twoEnd;
        twoEnd = tempEnd;
    }

    int size = max(oneEnd, twoEnd);
    vector<int> sub(size, 0);
    int ep = size;
    while (ep >= 00)
    {
        int valF = 0;
        int valS = 0;
        int newVal = 0;
        if (oneEnd >= 0)
        {
            valF = one[oneEnd];
            oneEnd--;
        }

        if (twoEnd >= 0)
        {
            valS = two[twoEnd];
            twoEnd--;
        }
        if (oneEnd >= 0 && valS > valF)
        {
            valF += 10;
            one[oneEnd] -= 1;
            newVal = valF - valS;
        }
        else
        {
            newVal = valF - valS;
        }

        sub[ep] = newVal;
        ep--;
    }

    for (int i = 0; i < sub.size(); i++)
    {
        cout << sub[i];
    }
}

void subArrayNew(vector<int> one,
                 vector<int> two)
{
    int n = one.size();
    int m = two.size();
    int i = n - 1;
    int j = m - 1;
    vector<int> ans(max(n, m), 0);
    int k = ans.size() - 1;
    int borrow = 0;
    while (k >= 0)
    {
        int diff = borrow;
        if (i >= 0)
        {
            diff += one[i];
            i--;
        }
        if (j >= 0)
        {
            diff -= two[j];
            j--;
        }

        if (diff < 0)
        {
            diff += 10;
            borrow - 1;
        }
        else
        {
            borrow = 0;
        }
        ans[k] = diff;
        k--;
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i];
    }
}