#include <bits/stdc++.h>
using namespace std;
vector<vector<char>> grid(1005, vector<char>(1005));
int n, m;
vector<vector<bool>> vis(1005, vector<bool>(1005, false));

vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool canGo = false;
int isValid(int si, int sj)
{
    return (si >= 0 && si < n && sj >= 0 && sj < m);
}

void dfs(int si, int sj)
{
    // cout << grid[si][sj];
    vis[si][sj] = true;
    for (int i = 0; i < 4; i++)
    {
        int ci = si + dir[i].first;
        int cj = sj + dir[i].second;
        if (isValid(ci, cj) && !vis[ci][cj] && grid[ci][cj] != '#')
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

    int cntAprt = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && grid[i][j] != '#')
            {
                cntAprt++;
                dfs(i, j);
            }
        }
    }

    cout << cntAprt << endl;

    return 0;
}