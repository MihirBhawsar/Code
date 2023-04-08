#include <iostream>
#include <array>
#include <vector>
using namespace std;
void input(vector<vector<int>> &arr, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
}

void displayArray(vector<vector<int>> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            cout << arr[i][j];
        }
        cout << endl;
    }
}

int maxElement(vector<vector<int>> &arr)
{
    int max = INT16_MIN;

    for (vector<int> row : arr)
    {
        for (int col : row)
        {
            if (max < col)
            {
                max = col;
            }
        }
    }
    return max;
}
int minElement(vector<vector<int>> &arr)
{
    int min = INT16_MAX;

    for (vector<int> row : arr)
    {
        for (int col : row)
        {
            if (min > col)
            {
                min = col;
            }
        }
    }
    return min;
}

bool findData(vector<vector<int>> &arr, int data)
{
    for (vector<int> row : arr)
    {
        for (int col : row)
        {
            if (data == col)
            {
                return true;
            }
        }
    }
    return false;
}
void displayZigZag(vector<vector<int>> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < arr[0].size(); j++)
            {
                cout << arr[i][j];
            }
        }
        else
        {
            for (int j = arr[0].size() - 1; j >= 0; j--)
            {
                cout << arr[i][j];
            }
        }
        cout << endl;
    }
}
void displayUpDown(vector<vector<int>> &arr)
{
    for (int i = 0; i < arr[0].size(); i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < arr.size(); j++)
            {
                cout << arr[j][i];
            }
        }
        else
        {
            for (int j = arr.size() - 1; j >= 0; j--)
            {
                cout << arr[j][i];
            }
        }
        cout << endl;
    }
}
vector<vector<int>> transpose(vector<vector<int>> &matrix)
{
    vector<vector<int>> transpose(matrix[0].size(), vector<int>(matrix.size(), 0));
    ;
    for (int i = 0; i < matrix[0].size(); i++)
    {
        for (int j = 0; j < matrix.size(); j++)
        {
            transpose[i][j] = matrix[j][i];
        }
    }
    return transpose;
}
vector<int> findDiagonalOrder(vector<vector<int>> &mat)
{    vector<int> diagonalArr;
    for (int k = 0; k < (mat.size()*2)-1; k++)
    {        if (k % 2 == 1)
        {            for (int i = 0; i < mat.size(); i++)
            {
                for (int j = 0; j < mat[0].size(); j++)
                {
                    if (k == i + j)
                    {
                        diagonalArr.push_back(mat[i][j]);
                    }
                }
            }
        }
        else {
            for (int i = mat.size() - 1; i >= 0; i--)
            {
                for (int j = mat[0].size() - 1; j >= 0; j--)
                {
                    if (k == i + j)
                    {
                        diagonalArr.push_back(mat[i][j]);
                    }
                }
            }
        }
    }    return diagonalArr;
}
int main()
{
    int m = 3;
    int n = 3;
    // vector<vector<int>> arr(m, vector<int>(n, 0));
    vector<vector<int>> arr{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    // cout << "enter element" << endl;
    // input(arr, m, n);
    // displayArray(arr);
    // cout << "max element " << maxElement(arr) << endl;
    // cout << "min element" << minElement(arr) << endl;
    // cout << "data present " << boolalpha << findData(arr, 5) << endl;

    // displayZigZag(arr);
    // displayUpDown(arr);
    // vector<vector<int>> newArr = transpose(arr);
    // displayArray(newArr);

    vector<int> arr1=findDiagonalOrder(arr);
    for (int i = 0; i < arr1.size(); i++)
    {
       cout<<arr1[i];
    }
    
    return 0;
}
