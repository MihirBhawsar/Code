#include <iostream>
#include <unordered_map>
using namespace std;

void printCommonElements(int mat[4][5], int M, int N)
{
    unordered_map<int, int> map;
    unordered_map<int, int> visited;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int val = mat[i][j];
            if (visited.find(val) == visited.end())
            {
                visited[val]++;
                map[val]++;
            }
        }
                    visited.clear();

    }

    for (auto kv : map)
    {
        if (kv.second == M )
        {
            cout << kv.first << " ";
        }
    }
}

int main()
{
    // code Common elements in all rows of a given matrix

    int mat[4][5] =
        {
            {1, 2, 1, 4, 8},
            {3, 7, 8, 5, 1},
            {8, 7, 7, 3, 1},
            {8, 1, 2, 7, 9},
        };

    printCommonElements(mat, 4, 5);
    return 0;
}