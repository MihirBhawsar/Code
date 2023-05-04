#include <iostream>
#include <vector>

using namespace std;

int coinsPermutation(vector<int> arr, int tar, string ans)
{
    if (tar == 0)
    {
        cout << ans << endl;
        return 1;
    }
    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (tar - arr[i] >= 0)
        {
            count += coinsPermutation(arr, tar - arr[i], ans + to_string(arr[i]));
        }
    }
    return count;
}
int coinsPermutationWithRepeat(vector<int> arr, int tar, string ans,vector<bool>vis)
{   
    if (tar == 0)
    {
        cout << ans << endl;
        return 1;
    }
    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        // if(vis[i]==true){
        //     continue;
        // }
       
        if (tar - arr[i] >= 0&&vis[i]==false)
        {
            vis[i]=true;
            count += coinsPermutationWithRepeat(arr, tar - arr[i], ans + to_string(arr[i]),vis);
            vis[i]=false;
        }
    }
    return count;
}
int coinsCombination(vector<int> arr, int tar, string ans, int index)
{
    if (tar == 0)
    {
        cout << ans << endl;
        return 1;
    }
    if (tar < 0)
    {
        return 0;
    }
    int count = 0;
    for (int i = index; i < arr.size(); i++)
    {
        if (tar - arr[i] >= 0)
        {
            count += coinsCombination(arr, tar - arr[i], ans + to_string(arr[i]), i);
        }
    }
    return count;
}
int coinsCombinationWithRepeat(vector<int> arr, int tar, string ans, int index)
{
    if (tar == 0)
    {
        cout << ans << endl;
        return 1;
    }
    if (tar < 0)
    {
        return 0;
    }
    int count = 0;
    for (int i = index; i < arr.size(); i++)
    {
        if (tar - arr[i] >= 0)
        {
            count += coinsCombinationWithRepeat(arr, tar - arr[i], ans + to_string(arr[i]), i+1);
        }
    }
    return count;
}
int main()
{
    vector<int> arr = {2, 3, 5, 7};
    int tar = 10;
    // cout<<coinsPermutation(arr,tar,"");
    // cout << coinsCombination(arr, tar, "", 0);
    // cout << coinsCombinationWithRepeat(arr, tar, "", 0);
    vector<bool> vis(arr.size(),false);
    cout << coinsPermutationWithRepeat(arr, tar, "",vis);
}