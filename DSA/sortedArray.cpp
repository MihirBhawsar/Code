#include <iostream>
#include <array>
#include <vector>
using namespace std;
void bubbleSort(vector<int> &array);
void insertionSort(vector<int> &array);
void selectionSort(vector<int> &array);
void swapTwoNumber(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
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
    // bubbleSort(sort);
    // selectionSort(sort);
    insertionSort(sort);
    for (int i = 0; i < n; i++)
    {
        cout << sort[i] << " ";
    }
}
// B-o(n),A-o(n2),W-o(n2)
void bubbleSort(vector<int> &array)
{
    for (int i = 0; i < array.size() - 1; i++)
    {
        int swapped = 0;
        for (int j = 0; j < array.size() - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;

                swapped = 1;
            }
        }
        if (swapped == 0)
        {
            break;
        }
    }
}

void selectionSort(vector<int> &array)
{
    int n = array.size();
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (array[min_index] > array[j])
            {
                min_index = j;
            }
        }
        swapTwoNumber(&array[min_index], &array[i]);
    }
}
void insertionSort(vector<int> &array)
{
    int n = array.size();
    for (int i = 1; i < n; i++)
    {
        int min = array[i];
        int j = i - 1;
        while (min < array[j] && j >= 0)
        {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = min;
    }
}
