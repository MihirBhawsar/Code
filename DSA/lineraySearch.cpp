#include <iostream>
#include <array>
#include <vector>
using namespace std;
int linearSearch(vector<int> &linear ,int data);
int main()
{
    int n = 0;
    cout << "enter arr size:-"<<endl;
    cin >> n;
    vector<int> linear(n, 0);
    cout<<"enter array element"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin >> linear[i];
    }

    int f;
    cout << "enter finding number:-" << endl;
    cin >> f;
cout<<"Element present at index:- "<<linearSearch(linear,f);
  
}
//o(n)
int linearSearch(vector<int> &linear ,int data){
  for (int i = 0; i < linear.size(); i++)
    {
        if (linear[i] == data)
        {
            return i;
        }
    }
    return -1;
}