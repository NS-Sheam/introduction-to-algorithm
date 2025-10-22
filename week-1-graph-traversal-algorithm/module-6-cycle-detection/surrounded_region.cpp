#include <bits/stdc++.h>
using namespace std;
vector<vector<char>> grid(205, vector<char>(205));
vector<vector<bool>> vis = vector<vector<bool>>(205, vector<bool>(205, false));

int n, m;
vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

bool isTouch(int i, int j)
{
    return (i <= 0 || i >= n - 1 || j <= 0 || j >= m - 1);
}

void dfs(int si, int sj)
{
    // if (!isTouch(si, sj))
    // {
    //     grid[si][sj] = 'X';
    // }
    // cout << grid[si][sj] << " ";
    vis[si][sj] = true;
    for (auto d : dir)
    {
        int ci = si + d.first;
        int cj = sj + d.second;
        if (isValid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == 'O')
        {
            dfs(ci, cj);
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && grid[i][j] == 'O' && isTouch(i, j))
            {
                dfs(i, j);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'O' && !vis[i][j])
                grid[i][j] = 'X';
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}