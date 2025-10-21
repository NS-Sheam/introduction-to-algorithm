#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> grid(1005, vector<int>(1005));
vector<vector<int>> vis(1005, vector<int>(1005, false));

vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m;
int mx = 0;
int cnt;
bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void dfs(int si, int sj)
{
    // cout << grid[si][sj] << " ";
    cnt += grid[si][sj];
    // cout << "cnt -> " << cnt << " grid-> " << grid[si][sj] << endl;
    vis[si][sj] = true;
    for (auto d : dir)
    {
        int ci = si + d.first;
        int cj = sj + d.second;
        if (isValid(ci, cj) && !vis[ci][cj] && grid[ci][cj] != 0)
        {
            dfs(ci, cj);
        }
    }
    mx = max(mx, cnt);
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
            if (!vis[i][j] && grid[i][j] != 0)
            {
                cnt = 0;
                dfs(i, j);
            }
        }
        // cout << endl;
    }

    cout << "Total fish-> " << mx;
    return 0;
}