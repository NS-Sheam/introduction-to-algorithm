#include <bits/stdc++.h>
using namespace std;
string a, b;
int dp[1005][1005];
int lcs(int i, int j)
{
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return 0;
    if (a[i] == b[j])
    {
        return dp[i][j] = lcs(i - 1, j - 1) + 1;
    }
    else
    {
        int opt1 = lcs(i - 1, j);
        int opt2 = lcs(i, j - 1);
        return dp[i][j] = max(opt1, opt2);
    }
}
int main()
{
    cin >> a >> b;
    int n = a.size();
    int m = b.size();
    memset(dp, -1, sizeof(dp));

    cout << lcs(n - 1, m - 1);
    return 0;
}