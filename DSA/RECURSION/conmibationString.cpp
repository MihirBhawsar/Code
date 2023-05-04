#include <iostream>
#include <array>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;
vector<string> dial = {".;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};
vector<string> combinationOfDialString(string str)
{
    if (str.length() == 0)
    {
        vector<string> base;
        base.push_back("");
        return base;
    }
    char ch = str[0];
    string rstr = str.substr(1);

    string word = dial[ch - '0'];
    vector<string> smallAns = combinationOfDialString(rstr);
    vector<string> ans;
    for (string s : smallAns)
    {
        for (int i = 0; i < word.length(); i++)
        {
            ans.push_back(word[i] + s);
        }
    }
    return ans;
}

void permutation(string str, int si, int ei)
{
    if (si == ei)
    {
        cout << str << endl;
    }
    else
    {
        for (int i = si; i <= ei; i++)
        {
            swap(str[si], str[i]);
            permutation(str, si + 1, ei);
            swap(str[si], str[i]);
        }
    }
}

int permutationCount(string que, string ans)
{
    if (que.size() == 0)
    {
        cout << ans << " ";
        return 1;
    }
    int count = 0;
    for (int i = 0; i < que.size(); i++)
    {
        char ch = que[i];
        string rstr = que.substr(0, i) + que.substr(i + 1);
        count += permutationCount(rstr, ans + ch);
    }
    return count;
}
int permutationCountNotDuplicate(string que, string ans)
{
    vector<bool> visited(26, 0);
    if (que.size() == 0)
    {
        cout << ans << " ";
        return 1;
    }
    int count = 0;
    for (int i = 0; i < que.size(); i++)
    {
        char ch = que[i];
        if (!visited[ch - 'a'])
        {
            visited[ch - 'a']=true;
            string rstr = que.substr(0, i) + que.substr(i + 1);
            count += permutationCount(rstr, ans + ch);
        }
    }
    return count;
}

                         

int main()
{
    string str = "abc";
    // combinationOfDialString(str);
    // permutation(str,0,str.size()-1);
    // cout<<permutationCount(str,"");
    cout << permutationCountNotDuplicate(str, "");
    return 0;
}                               