#include <iostream>
using namespace std;

void greet();
void palindrome(int num);
bool oddEven(int num);
int fact(int num);
void rang(int num, int start, int end);
void greeting()
{
    cout << "hello mihir" << endl;
    return;
}
int main()
{
    int num;
    // greet();
    // greeting();
    // cout << "num is even " << oddEven(10);
    cout << "enter a number";
    cin >> num;
    // palindrome(num);
    // rang(num, 5, 15);
cout<<"fact is your number "<<fact( num);

    return 0;
}

void greet()
{
    cout << "Hello Greet" << endl;
    return;
}

bool oddEven(int num)
{
    if (num % 2 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void palindrome(int num)
{
    int newNum = 0;
    int oldNUm = num;
    while (num != 0)
    {
        newNum = (newNum * 10) + (num % 10);
        num = num / 10;
    }

    if (newNum == oldNUm)
    {
        cout << "Number is Palindrome" << newNum;
    }
    else
    {
        cout << "Number is not Palindrome" << newNum;
    }
}

void rang(int num, int start, int end)
{
    if (num > start && num < end)
    {
        cout << "number in ranged" << endl;
    }
    else
    {
        cout << "number is not in ranged" << endl;
    }
}

int fact(int num){
    int fact=1;
    for (int i = 1; i <= num; i++)
    {
        fact*=i;
    }
    return fact;
}