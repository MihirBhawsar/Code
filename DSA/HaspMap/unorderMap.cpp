#include <iostream>
#include <unordered_map>
#include <vector>
#include <array>
using namespace std;

void indexMap(string str){
      unordered_map<char, vector<int>> index;
    for (int i = 0; i < str.size(); i++)
    {
        index[str[i]].push_back(i);
    }

    for (auto keyvalue : index)
    {
        cout<< keyvalue.first<<"->";
       for(int ele:keyvalue.second){
        cout<<ele<<" ";
       }
       cout<<endl;
    }

}

void freqMap(string str)
{
    unordered_map<char,int> freq;
    for (int i = 0; i < str.size(); i++)
    {
        freq[str[i]]++;
    }
    for (auto keyvalue : freq)
    {
        char key = keyvalue.first;
        int value = keyvalue.second;
        cout << key << " " << value << endl;
    }
}
int main()
{
    //     unordered_map<string, int> map;
    //     //first way insert
    //     map.insert({"M", 1});
    //     map.insert({"I", 2});
    //     map.insert({"H", 1});
    //     map.insert({"R", 1});
    //     //second way
    //     map["B"]=1;
    //     map["W"]=2;

    // //return value for the specific key
    //     cout<<map["B"]<<endl;
    //     cout<<map.at("W")<<endl;

    //     //remove element
    //     map.erase("W");

    //     for (auto keyvalue : map)
    //     {
    //         string key = keyvalue.first;
    //         int value = keyvalue.second;
    //         cout << key << " " << value << endl;
    //     }

    string name = "chcsijsfsdncfjsnfsofsf";
    indexMap(name);

}

