#include <bits/stdc++.h>
using namespace std;
vector<vector<char>> grid(10005, vector<char>(10005));
vector<vector<bool>> vis(10005, vector<bool>(10005, false));
int n, m;

vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}
void dfs(int si, int sj)
{

    // cout << grid[si][sj] << " ";
    vis[si][sj] = true;
    for (pair<int, int> d : dir)
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
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << grid[i][j];
    //     }
    //     cout << endl;
    // }

    int si, sj, di, dj;
    cin >> si >> sj >> di >> dj;
    dfs(si, sj);
    cout << (vis[di][dj] ? "YES" : "NO");

    return 0;
}