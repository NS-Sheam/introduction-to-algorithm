#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> dp;
vector<vector<int>> grid;
int maxPath(int i, int j)
{
    if (i >= n || j >= m)
        return INT_MAX;
    if (i == n - 1 && j == m - 1)
        return grid[i][j];
    if (dp[i][j] != -1)
        return dp[i][j];

    int opt1 = maxPath(i + 1, j);
    int opt2 = maxPath(i, j + 1);

    return dp[i][j] = grid[i][j] + min(opt1, opt2);
}
int main()
{

    cin >> n >> m;
    grid.resize(n, vector<int>(m));
    dp.resize(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }

    cout << maxPath(0, 0);

    return 0;
}