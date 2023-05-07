#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int queenSpaceCombination(int box, int idx, int pqsf, int tnq, string ans)
{
    if (pqsf == tnq)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    for (int i = idx; i < box; i++)
    {
        count += queenSpaceCombination(box, i + 1, pqsf + 1, tnq, ans + " b" + to_string(i) + " q" + to_string(pqsf));
    }
    return count;
}
int queenSpacePermutation(int box, int pqsf, int tnq, string ans, vector<bool> vis)
{
    if (pqsf == tnq)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    for (int i = 0; i < box; i++)
    {
        if (!vis[i])
        {
            vis[i] = true;
            count += queenSpacePermutation(box, pqsf + 1, tnq, ans + " b" + to_string(i) + " q" + to_string(pqsf), vis);
            vis[i] = false;
        }
    }
    return count;
}
int queenMatrixCombination(vector<vector<bool>> &box, int idx, int pqsf, int tnq, string ans)
{
    if (pqsf == tnq)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    for (int i = idx; i < box.size() * box[0].size(); i++)
    {
        int row = i / box[0].size();
        int col = i % box[0].size();
        count += queenMatrixCombination(box, i + 1, pqsf + 1, tnq, ans + " (" + to_string(row) + " ," + to_string(col) + ")");
    }
    return count;
}
int queenMatrixPermutation(vector<vector<bool>> &box, int pqsf, int tnq, string ans)
{
    if (pqsf == tnq)
    {
        // cout << a
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    for (int i = 0; i < box.size() * box[0].size(); i++)
    {

        int row = i / box[0].size();
        int col = i % box[0].size();
        if (!box[row][col])
        {
            box[row][col] = true;
            count += queenMatrixPermutation(box, pqsf + 1, tnq, ans + " (" + to_string(row) + " ," + to_string(col) + ")");
            box[row][col] = false;
        }
    }
    return count;
}

bool isSafePlaceToQueen(vector<vector<bool>> &box, int r, int c)
{
    vector<vector<int>> dirA = {{0, -1}, {-1, 0}, {-1, -1}, {1, -1}};

    for (int d = 0; d < dirA.size(); d++)
    {
        for (int rad = 1; rad <= box.size(); rad++)
        {
            int x = r + rad * dirA[d][0];
            int y = c + rad * dirA[d][1];

            if (x >= 0 && y >= 0 && x < box.size() && y < box[0].size())
            {
                if (box[x][y])
                {
                    return false;
                }
            }
            else
            {
                break;
            }
        }
    }
    return true;
}

int NQueen(vector<vector<bool>> &box, int idx, int pqsf, int tnq, string ans)
{
    if (pqsf == tnq)
    {
        // cout << a
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    int n = box[0].size();
    for (int i = idx; i < n * n; i++)
    {

        int row = i / n;
        int col = i % n;
        if (isSafePlaceToQueen(box, row, col))
        {
            box[row][col] = true;
            count += NQueen(box, i + 1, pqsf + 1, tnq, ans + " (" + to_string(row) + " ," + to_string(col) + ")");
            box[row][col] = false;
        }
    }
    return count;
}
int main()
{
    // vector<bool> vis(16, false);
    vector<vector<bool>> box(4, vector<bool>(4, false));
    // cout << queenSpaceCombination(5,0,0,3,"");
    // cout << queenSpacePermutation(5, 0, 3, "", vis);
    // cout << queenMatrixCombination(box, 0, 0, 3, "");
    // cout << queenMatrixPermutation(box, 0, 4, "");
    cout << NQueen(box, 0, 0, 4, "");
    return 0;
}