#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> grid(505, vector<int>(505));
vector<vector<bool>> vis = vector<vector<bool>>(505, vector<bool>(505, false));
int n, m, cnt = 0;
vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void dfs(int si, int sj, int &localCnt, bool &isTouch)
{
    if (si <= 0 || si >= n - 1 || sj <= 0 || sj >= m - 1)
        isTouch = true;
    vis[si][sj] = true;
    localCnt++;
    // cout << grid[si][sj] << " ";
    for (auto d : dir)
    {
        int ci = si + d.first;
        int cj = sj + d.second;

        if (isValid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == 1)
        {

            dfs(ci, cj, localCnt, isTouch);
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
            int tmpCnt = 0;
            bool isTouch = false;
            if (!vis[i][j] && grid[i][j] == 1)
            {
                dfs(i, j, tmpCnt, isTouch);
                // cout << tmpCnt << " isT -> " << isTouch << endl;
                cnt += !isTouch ? tmpCnt : 0;
            }
        }
    }
    cout << cnt;

    return 0;
}