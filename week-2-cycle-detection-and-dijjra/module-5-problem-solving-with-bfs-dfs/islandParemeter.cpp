#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> grid(1005, vector<int>(1005));
// left, right, up, down
vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<vector<bool>> vis(1005, vector<bool>(1005, false));
int n, m;

int cnt = 0;

int isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}
int counter(int i, int j)
{
    int left = 0, right = 0, up = 0, down = 0;
    if (!isValid(i, j - 1) || grid[i][j - 1] == 0)
        left = 1;
    if (!isValid(i, j + 1) || grid[i][j + 1] == 0)
        right = 1;
    if (!isValid(i - 1, j) || grid[i - 1][j] == 0)
        up = 1;
    if (!isValid(i + 1, j) || grid[i + 1][j] == 0)
        down = 1;
    return left + right + up + down;
}

void dfs(int si, int sj)
{
    cout << grid[si][sj] << " ";
    cnt += counter(si, sj);
    vis[si][sj] = true;
    for (int i = 0; i < dir.size(); i++)
    {
        int ci = si + dir[i].first;
        int cj = sj + dir[i].second;
        if (isValid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == 1)
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
    int si, sj;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                si = i;
                sj = j;
                break;
            }
        }
    }
    dfs(si, sj);

    cout << " Counter -> " << cnt << endl;

    return 0;
}

class Solution
{
public:
    int n, m;
    int cnt;
    bool vis[105][105];
    vector<pair<int, int>> d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int isValid(int i, int j) { return (i >= 0 && i < n && j >= 0 && j < m); }
    void dfs(int si, int sj, vector<vector<int>> &grid)
    {
        cout << si << " " << sj << endl;
        vis[si][sj] = true;
        for (int i = 0; i < 4; i++)
        {
            int ci = si + d[i].first;
            int cj = sj + d[i].second;
            if (!isValid(ci, cj))
                cnt++;
            else if (isValid(ci, cj) && grid[ci][cj] == 0)
                cnt++;
            else if (isValid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == 1)
            {
                dfs(ci, cj, grid);
            }
        }
    }
    int islandPerimeter(vector<vector<int>> &grid)
    {
        cnt = 0;
        n = grid.size();
        m = grid[0].size();
        memset(vis, false, sizeof(vis));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && grid[i][j])
                    dfs(i, j, grid);
            }
        }
        return cnt;
    }
};