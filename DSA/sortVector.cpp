#include <iostream>
#include <array>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr={5,6,8,3,9,2,7,5,45,36,15};
// sort(arr.begin(),arr.end());
sort(arr.begin(),arr.end(),greater<int>());
    for(int ele:arr){
        cout<<ele<<" ";
    }
}