#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<char>> grid;
vector<vector<bool>> vis;
vector<vector<int>> level;

vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}
bool isExit(int i, int j, int si, int sj)
{
    return ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && (i != si || j != sj));
}

int bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    level[si][sj] = 0;
    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        int par_i = par.first;
        int par_j = par.second;
        for (pair<int, int> d : dir)
        {
            int ci = par_i + d.first;
            int cj = par_j + d.second;
            if (isValid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == '.')
            {
                if (isExit(ci, cj, si, sj))
                {
                    // cout << " ci cj -> " << ci << " " << cj << endl;
                    return level[par_i][par_j] + 1;
                }
                if (!vis[ci][cj])
                {
                    q.push({ci, cj});
                    vis[ci][cj] = true;
                    level[ci][cj] = level[par_i][par_j] + 1;
                }
            }
        }
    }
    return -1;
}

int main()
{

    cin >> n >> m;
    grid.resize(n, vector<char>(m));
    vis.assign(n, vector<bool>(m, false));
    level.assign(n, vector<int>(m, -1));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    vector<int> entrance = {1, 0};

    int nearest_exit = bfs(entrance[0], entrance[1]);
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << level[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << nearest_exit << endl;
    return 0;
}