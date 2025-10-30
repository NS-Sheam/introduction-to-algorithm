#include <bits/stdc++.h>
using namespace std;
vector<vector<bool>> vis;
vector<vector<int>> level;
int n, m;

vector<pair<int, int>> dir = {
    {-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {1, -2}, {-1, 2}, {1, 2}};
bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}
void bfs(int si, int sj)
{

    queue<pair<int, int>> q;
    q.push({si, sj});
    level[si][sj] = 0;
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
            if (isValid(ci, cj) && !vis[ci][cj])
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
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        vis.assign(n, vector<bool>(m, false));
        level.assign(n, vector<int>(m, -1));

        int si, sj, di, dj;
        cin >> si >> sj >> di >> dj;
        bfs(si, sj);

        cout << level[di][dj] << endl;
    }

    return 0;
}