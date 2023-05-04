#include <iostream>
#include <array>
#include <bits/stdc++.h>
using namespace std;
void printN(int n)
{
    if (n == 0)
    {
        return;
    }
    cout << n << endl;
    printN(n - 1);
}

void printRange(int n)
{
    if (n == 0)
    {
        return;
    }
    printRange(n - 1);
    cout << n << " ";
}
void printIncDec(int n)
{
    if (n == 0)
    {
        return;
    }
    cout << n << " ";
    printIncDec(n - 1);
    cout << n << " ";
}

int fact(int n)
{
    if (n == 1)
    {
        return 1;
    }

    return n * fact(n - 1);
}

void evenOdd(int n, int r)
{
    if (n == r + 1)
    {
        return;
    }
    if (n % 2 == 0)
        cout << n << " ";
    evenOdd(n + 1, r);
    if (n % 2 == 1)
        cout << n << " ";
}
int power(int a, int b)
{
    if (b == 1)
    {
        return a;
    }

    return a * power(a, b - 1);
}

void printArr(int arr[], int n)
{
    if (n == -1)
    {
        return;
    }
    printArr(arr, n - 1);
    cout << arr[n] << " ";
}
int maxArr(vector<int> &arr, int i)
{
    if (i == arr.size())
    {
        return INT_MIN;
    }

    return max(maxArr(arr, i + 1), arr[i]);
}
int minArr(vector<int> &arr, int i)
{
    if (i == arr.size())
    {
        return INT_MAX;
    }

    return min(minArr(arr, i + 1), arr[i]);
}

bool find(vector<int> &arr, int idx, int val)
{
    if (idx == arr.size())
    {
        return false;
    }

    if (arr[idx] == val)
    {
        return true;
    }

    find(arr, idx + 1, val);
}

void firstInx(vector<int> &arr, int idx, int val)
{
    if (idx == arr.size())
    {
        cout << "element not found";
        return;
    }

    if (arr[idx] == val)
    {
        cout << idx << endl;
        return;
    }

    firstInx(arr, idx + 1, val);
}
void lastInx(vector<int> &arr, int size, int val)
{
    if (size == 0)
    {
        return;
    }
    if (arr[size] == val)
    {
        cout << size << endl;
        return;
    }
    lastInx(arr, size - 1, val);
}
int lastInxRe(vector<int> &arr, int idx, int val){
if (idx == arr.size())
    {
        return -1;
    }
   int ans= lastInxRe(arr, idx + 1, val);
    if(ans!=-1){
        return ans;
    }
   return arr[idx]==val?idx:-1;

}

void allInx(vector<int> &arr, int idx, int val)
{
    if (idx == arr.size())
    {
        return;
    }
    if (arr[idx] == val)
    {
        cout << idx << endl;
    }
    allInx(arr, idx + 1, val);
}

void subSequence(string &str,string output,int idx){
if(idx==str.size()){
    cout<<output<<" ";
    return;
}
subSequence(str,output,idx+1);
output+=str[idx];
subSequence(str,output,idx+1);


}
int subSequenceLength(string que,string ans){
    if(que.length()==0){
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
    count+=subSequenceLength(que.substr(1),ans+que[0]);//include char
    count+=subSequenceLength(que.substr(1),ans);//exclude char
    return count;
}

int main()
{
    // printN(5);
    // printRange(5);
    // printIncDec(5);
    // cout<< fact(5);
    // evenOdd(1, 10);
    // cout<< power(2, 4);
    // int arr[] = {54, 5, 8, 69, 52, 21, 57};
    // printArr(arr, 6);
    // vector<int> arr = {-52, 21, 8, 69, 52, 21, 52};
    // cout<<maxArr(arr,0);
    // cout<<minArr(arr,0);

    // cout<<find(arr,0,52);
    // firstInx(arr,0,52);
    // lastInx(arr, arr.size(), 21);
    // allInx(arr,0,52);
// cout<<lastInxRe(arr,0,21);

string name="abc";
// subSequence(name,"",0);
cout<<subSequenceLength(name,"");
    return 0;
}