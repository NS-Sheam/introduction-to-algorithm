#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> grid(1005, vector<int>(1005));
vector<vector<bool>> vis(1005, vector<bool>(1005, false));

vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m;
bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}
int cnt;
void dfs(int si, int sj, int &inCount)
{
    inCount++;
    vis[si][sj] = true;
    // cout << grid[si][sj] << " ";

    for (auto pair : dir)
    {
        int ci = si + pair.first;
        int cj = sj + pair.second;

        // cout << "ci -> " << ci << " cj -> " << cj << endl;
        // cout << grid[]

        if (isValid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == 1)
        {
            dfs(ci, cj, inCount);
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

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << grid[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // memset(vis, false, sizeof(vis));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && grid[i][j] == 1 && isValid(i, j))
            {
                int inCount = 0;
                dfs(i, j, inCount);
                cnt = max(cnt, inCount);
            }
        }
    }
    cout << " count ->" << cnt << endl;
    return 0;
}