#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> grid(1005, vector<char>(1005));
vector<vector<int>> vis(1005, vector<int>(1005, false));

vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m;

bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void dfs(int si, int sj)
{
    // cout << grid[si][sj] << " ";
    vis[si][sj] = true;
    for (auto d : dir)
    {
        int ci = si + d.first;
        int cj = sj + d.second;
        if (isValid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == '.')
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
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && grid[i][j] == '.')
            {
                cnt++;
                dfs(i, j);
            }
        }
        // cout << endl;
    }

    cout << "Total room-> " << cnt;
    return 0;
}