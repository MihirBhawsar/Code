#include <iostream>
#include <unordered_map>
using namespace std;

void findTwoElement(int *arr, int n) {
        // code here
        int freq[n+1] = { 0 };
        int ans[2] = { 0 };
        for(int i=0;i<n;i++){
            freq[arr[i]]++;
        }
        // for(int k=0;k<=n;k++){
        //     cout<<k<<"-"<<freq[k]<<endl;
        // }
        for(int i=n;i>0;i--){
            if(freq[i]==0){
                ans[1]=i;
            }
            if(freq[i]>1){
                ans[0]=i;
            }
        }
       
       cout<<ans[0]<<" "<<ans[1]; 
       
    }

int main()
{
    // code Common elements in all rows of a given matrix

    int mat[]={2,2};

    findTwoElement(mat, 2);
    return 0;
}