#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> grid;
vector<vector<bool>> vis;
vector<pair<int, int>> dir;
vector<vector<int>> level;
int n;
int cnt;
bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < n);
}

void bfs(int si, int sj)
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

        for (int i = 0; i < 4; i++)
        {
            int ci = par_i + dir[i].first;
            int cj = par_j + dir[i].second;
            if (isValid(ci, cj) && !vis[ci][cj] && grid[ci][cj] != 'T')
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                level[ci][cj] = level[par_i][par_j] + 1;
            }
        }
    }
}

int main()
{
    dir.push_back({-1, 0});
    dir.push_back({1, 0});
    dir.push_back({0, -1});
    dir.push_back({0, 1});
    while (cin >> n)
    {
        grid.resize(n, vector<char>(n));
        vis.assign(n, vector<bool>(n, false));
        level.assign(n, vector<int>(n, -1));
        int si, sj, di, dj;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> grid[i][j];
                if (grid[i][j] == 'S')
                {
                    si = i;
                    sj = j;
                }
                else if (grid[i][j] == 'E')
                {
                    di = i;
                    dj = j;
                }
            }
        }

        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         cin >> grid[i][j];
        //         if (grid[i][j] == 'S')
        //         {
        //             si = i;
        //             sj = j;
        //         }
        //     }
        // }
        bfs(si, sj);
        cout << level[di][dj] << endl;
    }

    return 0;
}