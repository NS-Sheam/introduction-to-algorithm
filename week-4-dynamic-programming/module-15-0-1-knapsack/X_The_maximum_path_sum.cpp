#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> dp;
vector<vector<int>> mat;
int maxPath(int i, int j)
{
    if (i >= n || j >= m)
        return 0;
    if (i == n - 1 && j == m - 1)
        return mat[i][j];
    if (dp[i][j] != -1)
        return dp[i][j];

    int opt1 = maxPath(i + 1, j);
    int opt2 = maxPath(i, j + 1);

    return dp[i][j] = mat[i][j] + max(opt1, opt2);
}
int main()
{

    cin >> n >> m;
    mat.resize(n, vector<int>(m));
    dp.resize(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];

    cout << maxPath(0, 0);

    return 0;
}