#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    vector<vector<int>> color;
    int R, C;

    int X[4] = {1, -1, 0, 0};
    int Y[4] = {0, 0, 1, -1};

    void dfs(vector<vector<char>> &grid, int x, int y)
    {
        color[x][y] = 1;

        for (int i = 0; i < 4; ++i)
        {
            int nx = x + X[i];
            int ny = y + Y[i];

            if ((nx >= 0 && nx < R && ny >= 0 && ny < C) && !color[nx][ny] && grid[nx][ny] == '1')
                dfs(grid, nx, ny);
        }
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        R = grid.size();
        if (R == 0)
            return 0;
        C = grid[0].size();
        color = vector<vector<int>>(R, vector<int>(C, 0));

        int numberOfIslands = 0;

        for (int i = 0; i < R; ++i)
        {
            for (int j = 0; j < C; ++j)
            {
                if (grid[i][j] == '1' && !color[i][j])
                {
                    numberOfIslands++;
                    dfs(grid, i, j);
                }
            }
        }
        return numberOfIslands;
    }
};

int main(int argv, const char *argc)
{
    return 0;
}