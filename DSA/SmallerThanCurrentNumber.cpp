#include <iostream>
#include <array>
#include <vector>
using namespace std;
 vector<int> smallerNumbersThanCurrent(vector<int>& nums);
int main()
{
    int n = 0;
    cout << "enter arr size:-" << endl;
    cin >> n;
    vector<int> sort(n, 0);
    cout << "enter array element" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> sort[i];
    }
    vector<int> newA=smallerNumbersThanCurrent(sort);
    for (int i = 0; i < n; i++)
    {
        cout << newA[i] << " ";
    }
}

 vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n=nums.size();
        vector<int> newA(n,0);
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                    if(nums[i]>nums[j]){
                        count++;
                    }

            }
            newA[i]=count;
        }
        return newA;
    }