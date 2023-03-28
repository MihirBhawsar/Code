 #include <iostream>
#include <array>
#include <vector>
using namespace std;
 
 void reverseInGroups(vector<long long>& arr, int n, int k){
    vector<long long> arrNew;
        // code here
        if(k>=n){
            k=n;
        }
        int si=0;
        int ei=k-1;
        int loop=n/k;
        int i;
         for( i=1;i<=loop;i++){
           if(i==1){
               si=0;
           }else{
               si=k*(i-1);
           }
           ei=(k*i)-1;
            while(si<ei){
                int temp=arr[si];
                arr[si]=arr[ei];
                arr[ei]=temp;
                si++;
                ei--;
            }
      
       }
       
      si=k*(i-1);
      ei=n-1;
      cout<<si<<" "<<ei<<endl;
      while(si<ei){
                int temp=arr[si];
                arr[si]=arr[ei];
                arr[ei]=temp;              
                si++;
                ei--;
            }
        
    }

    int main(){
        vector<long long> arr={1,2,3,4,5};

        reverseInGroups(arr,5,3);
        for (int i = 0; i < arr.size(); i++)
        {
           cout<<arr[i]<<" ";
        }
        return 0;
    }