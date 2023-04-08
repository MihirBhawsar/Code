#include <iostream>
#include <string>
using namespace std;

string reverseString(string str){
    // string reverse;
    // for(int i=str.length()-1;i>=0;i--){
    //     reverse+=str[i];
    // }
    // return reverse;

    int n=str.length();
    int si=0;
    int ei=n-1;
    while(si<ei){
        char temp=str[si];
        str[si]=str[ei];
        str[ei]=temp;
    }
}
int main()
{
    string name = "hey, i am mihir";
    cout << name << endl;

    string fullname;
    // cin >> fullname;
    // cout << fullname << endl;
    getline(cin, fullname);
    cout << reverseString(fullname) << endl;
}