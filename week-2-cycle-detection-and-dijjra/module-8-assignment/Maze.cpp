#include <bits/stdc++.h>
using namespace std;
vector<vector<char>> grid;
vector<vector<bool>> vis;
vector<vector<pair<int, int>>> parent;
int n, m;

vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}
void bfs(int si, int sj)
{

    queue<pair<int, int>> q;
    q.push({si, sj});

    vis[si][sj] = true;
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
            if (isValid(ci, cj) && !vis[ci][cj] && (grid[ci][cj] == '.' || grid[ci][cj] == 'D'))
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                parent[ci][cj] = {par_i, par_j};
                if (grid[ci][cj] == 'D')
                {
                    int x = par_i, y = par_j;
                    while (grid[x][y] != 'R')
                    {
                        grid[x][y] = 'X';
                        pair<int, int> p = parent[x][y];
                        x = p.first;
                        y = p.second;
                    }
                    return;
                }
            }
        }
    }
}

int main()
{

    cin >> n >> m;
    grid.assign(n, vector<char>(m));
    vis.assign(n, vector<bool>(m, false));
    parent.assign(n, vector<pair<int, int>>(m, {-1, -1}));
    int si = -1, sj = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'R')
            {
                si = i;
                sj = j;
            }
        }
    }
    if (si != -1 && sj != -1)
        bfs(si, sj);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << grid[i][j];
        }
        cout << endl;
    }

    return 0;
}