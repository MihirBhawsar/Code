#include <iostream>
#include <stack>
#include<vector>
using namespace std;

vector<int>ngor(vector<int> &arr){
    stack<int>st;
    st.push(-1);
    
    int n = arr.size();
    vector<int>ans(n,-1);
    
    for(int i=0;i<n;i++){
        while(st.top() != -1 && arr[st.top()] < arr[i]){
            ans[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    return ans;
}
int main()
{
   
int arr[] = { 11, 13, 21, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);
   vector<int> newArr= ngor(arr);
    return 0; 
}