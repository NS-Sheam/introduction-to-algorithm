#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> grid(105, vector<int>(105));
vector<vector<bool>> vis = vector<vector<bool>>(105, vector<bool>(105, false));
vector<vector<int>> level = vector<vector<int>>(105, vector<int>(105, -1));
vector<pair<int, int>> dir = {
    {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
bool isValid(int i, int j) { return (i >= 0 && i < n && j >= 0 && j < m); }

void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    level[si][sj] = 1;
    while (!q.empty())
    {
        pair<int, int> parent = q.front();
        q.pop();
        int pi = parent.first;
        int pj = parent.second;
        // cout << grid[pi][pj] << " ";
        for (auto d : dir)
        {
            int ci = pi + d.first;
            int cj = pj + d.second;
            if (isValid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == 0)
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                level[ci][cj] = level[pi][pj] + 1;
            }
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
    if (grid[0][0] != 0 || grid[n - 1][m - 1] != 0)
        return -1;
    bfs(0, 0);
    cout << level[n - 1][m - 1];
    return 0;
}