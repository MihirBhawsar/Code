#include <iostream>
#include <string>
#include<vector>
using namespace std;

string firstPalindrome(vector<string> &words)
{
    string str = "";

    for (int i = 0; i < words.size(); i++)
    {
        bool isP = true;
        str = words[i];
        int si = 0;
        int ei = str.length() - 1;
        while (si < ei)
        {
            if (str[si] != str[ei])
            {
                isP = false;
                break;
            }
            else
            {
                si++;
                ei--;
            }
        }
        if (isP)
        {
            return str;
        }
        else
        {
            str = "";
        }
    }
    return str;
}

int main()
{
//     ["abc","car","ada","racecar","cool"]
// ["notapalindrome","racecar"]
// ["def","ghi"]
}