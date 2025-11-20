#include <bits/stdc++.h>
using namespace std;
int n, m;
int di, dj;
vector<vector<int>> grid;
vector<vector<bool>> vis;
vector<vector<int>> level;
queue<pair<int, int>> q;

vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void dfs(int si, int sj)
{

    if (!isValid(si, sj) || vis[si][sj] || grid[si][sj] != 1)
        return;

    vis[si][sj] = true;
    level[si][sj] = 0;
    q.push({si, sj});
    for (auto d : dir)
    {
        int ci = si + d.first;
        int cj = sj + d.second;
        dfs(ci, cj);
    }
}

int bfs()
{
    // cout << "si-> " << si << " -sj-> " << sj << endl;

    // q.push({si, sj});
    // vis[si][sj] = true;
    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        int par_i = par.first;
        int par_j = par.second;

        for (pair<int, int> p : dir)
        {
            int ci = par_i + p.first;
            int cj = par_j + p.second;
            if (isValid(ci, cj) && !vis[ci][cj])
            {
                if (grid[ci][cj] == 1)
                {
                    return level[par_i][par_j];
                }

                if (grid[ci][cj] == 0)
                {
                    vis[ci][cj] = true;
                    level[ci][cj] = level[par_i][par_j] + 1;
                    q.push({ci, cj});
                }
            }
        }
    }
    return -1;
}

int main()
{
    cin >> n >> m;
    grid.resize(n, vector<int>(m));
    vis.assign(n, vector<bool>(m, false));
    level.assign(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    bool found = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            if (isValid(i, j) && !vis[i][j] && grid[i][j] == 1 && !found)
            {
                dfs(i, j);
                found = true;
            }
        }
    }
    int sortest_path = bfs();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            cout << level[i][j] << " ";
        }
        cout << endl;
    }
    cout << "di-> " << di << " -dj-> " << dj << " path-> " << sortest_path << endl;
    cout << level[di][dj] << endl;

    return 0;
}