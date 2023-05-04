#include <iostream>
#include <array>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;
int sourceToDestinationPath(int sr, int sc, int er, int ec, string ans)
{
    if (sr == er && sc == ec)
    {
        cout << ans << endl;
        return 1;
    }
    int count = 0;
    if (sr + 1 <= er)
    {
        count += sourceToDestinationPath(sr + 1, sc, er, ec, ans + "V");
    }
    if (sc + 1 <= ec)
    {
        count += sourceToDestinationPath(sr, sc + 1, er, ec, ans + "H");
    }
    if (sr + 1 <= er && sc + 1 <= ec)
    {
        count += sourceToDestinationPath(sr + 1, sc + 1, er, ec, ans + "D");
    }
    return count;
}

int mazePathWithJump(int sr, int sc, int er, int ec, string ans)
{
    if (sr == er && sc == ec)
    {
        cout << ans << endl;
        return 1;
    }
    int count = 0;
    for (int jump = 1; sc + jump <= ec; jump++)
    {
        count += mazePathWithJump(sr, sc + jump, er, ec, ans + "H" + to_string(jump));
    }
    for (int jump = 1; sr + jump <= er; jump++)
    {
        count += mazePathWithJump(sr + jump, sc, er, ec, ans + "V" + to_string(jump));
    }
    for (int jump = 1; sr + jump <= er && sc + jump <= ec; jump++)
    {
        count += mazePathWithJump(sr + jump, sc + jump, er, ec, ans + "D" + to_string(jump));
    }
}

void floodfill(vector<vector<int>> maze, int sr, int sc, string ans, vector<vector<bool>> visited)
{

    if (sr == maze.size() - 1 && sc == maze[0].size() - 1)
    {
        cout << ans << endl;
        return;
    }

    if (sr < 0 || sc < 0 || sr >= maze.size() || sc >= maze[0].size() || visited[sr][sc] == true)
    {
        return;
    }
    visited[sr][sc] = true;
    floodfill(maze, sr - 1, sc, ans + "T", visited);
    floodfill(maze, sr, sc - 1, ans + "L", visited);
    floodfill(maze, sr + 1, sc, ans + "B", visited);
    floodfill(maze, sr, sc + 1, ans + "R", visited);
    visited[sr][sc] = false;
}
void floodFillBlock(vector<vector<int>> maze, int sr, int sc, string ans, vector<vector<bool>> visited)
{

    if (sr == maze.size() - 1 && sc == maze[0].size() - 1)
    {
        cout << ans << endl;
        return;
    }

    if (sr < 0 || sc < 0 || sr >= maze.size() || sc >= maze[0].size() || visited[sr][sc] == true || maze[sr][sc] == 1)
    {
        return;
    }
    visited[sr][sc] = true;
    floodFillBlock(maze, sr - 1, sc, ans + "T", visited);
    floodFillBlock(maze, sr, sc - 1, ans + "L", visited);
    floodFillBlock(maze, sr + 1, sc, ans + "B", visited);
    floodFillBlock(maze, sr, sc + 1, ans + "R", visited);
    visited[sr][sc] = false;
}

int main()
{
    // cout << sourceToDestinationPath(0, 0, 2, 2, "");
    //    cout<< mazePathWithJump(0,0,2,2,"");

    // int n = 3, m = 3;
    // vector<vector<int>> maze(n, (vector<int>(m)));
    // vector<vector<bool>> visited(n, (vector<bool>(m)));
    // floodfill(maze, 0, 0, "", visited);

    int n = 4, m = 4;
    vector<vector<int>> maze = {
        {0, 0, 1, 0},
        {0, 1, 0, 0},
        {0, 0, 0, 0}};
    vector<vector<bool>> visited(n, (vector<bool>(m)));
    floodFillBlock(maze, 0, 0, "", visited);
    return 0;
}