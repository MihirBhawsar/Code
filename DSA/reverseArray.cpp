#include <iostream>
#include <array>
#include <vector>
using namespace std;
void swapArray(vector<int> vecArr,int sp,int ep);
void reverse(vector<int> vecArr,int sp,int ep);
void swap(int &a, int &b)
{
    int temp = 0;
    temp = a;
    a = b;
    b = temp;
}

int main()
{
    vector<int> vecArr = {1, 2, 3, 4, 5};
    int n = vecArr.size();
    // for (int i = 0; i < n; i++)
    // {
    //     cout << vecArr[i] << endl;
    // }

    // for (int i = 0; i < (n / 2); i++)
    // {
    //     swap(vecArr[i], vecArr[n - 1 - i]);
    // }
     reverse(vecArr,0,n-1);
    cout << "after reverse"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout << vecArr[i] << endl;
    }

    reverse(vecArr,0,n-1);
}

void reverse(vector<int> vecArr,int sp,int ep)
{
    while(sp<ep){
        swapArray(vecArr,sp,ep);
        sp++;
        ep--;
    }
}

void swapArray(vector<int> vecArr,int sp,int ep){
    int temp=vecArr[sp];
    vecArr[sp]=vecArr[ep];
    vecArr[ep]=temp;
}
