#include <bits/stdc++.h>
using namespace std;
vector<vector<char>> grid(1005, vector<char>(1005));
vector<vector<bool>> vis(1005, vector<bool>(1005, false));

vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m;

bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void bfs(int si, int sj, vector<int> &apartments)
{
    queue<pair<int, int>> q;
    // cout << grid[si][sj] << " ";
    vis[si][sj] = true;
    q.push({si, sj});
    int cnt = 1;

    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();

        int par_i = par.first;
        int par_j = par.second;
        // cout << grid[par_i][par_j] << " ";

        for (int i = 0; i < 4; i++)
        {
            int ci = par_i + dir[i].first;
            int cj = par_j + dir[i].second;
            // cout << " valid => " << isValid(ci, cj) << " vis=> " << vis[ci][cj] << " grid => " << grid[ci][cj] << endl;
            if (isValid(ci, cj) && !vis[ci][cj] && grid[ci][cj] != '#')
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                cnt++;
                // cout << " count -> " << cnt << endl;
            }
        }
    }
    apartments.push_back(cnt);
}

int main()
{

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            // cout << grid[i][j];
        }
    }
    vector<int> apartments;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && grid[i][j] != '#')
            {
                bfs(i, j, apartments);
            }
        }
    }

    sort(apartments.begin(), apartments.end());

    if (apartments.empty())
    {
        cout << 0;
    }
    else
    {
        for (int i = 0; i < apartments.size(); i++)
        {
            cout << apartments[i] << " ";
        }
    }

    return 0;
}