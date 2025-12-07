#include <bits/stdc++.h>
using namespace std;
vector<int> val;
vector<int> weight;
vector<vector<int>> dp;
int knapsack(int i, int mx_weight)
{
    if (i < 0 || mx_weight <= 0)
        return 0;
    if (dp[i][mx_weight] != -1)
        return dp[i][mx_weight];
    if (weight[i] <= mx_weight)
    {
        int opt1 = knapsack(i - 1, mx_weight - weight[i]) + val[i];
        int opt2 = knapsack(i - 1, mx_weight);
        return dp[i][mx_weight] = max(opt1, opt2);
    }
    else
    {
        return dp[i][mx_weight] = knapsack(i - 1, mx_weight);
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;
        // cout << n << w;
        val.resize(n + 1);
        weight.resize(n + 1);
        for (int i = 0; i < n; i++)
            cin >> weight[i];
        for (int i = 0; i < n; i++)
            cin >> val[i];
        dp.assign(n + 1, vector<int>(w + 1, -1));

        cout << knapsack(n - 1, w) << endl;
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         cout << dp[i][j] << " ";
        //     }
        // }
    }
    return 0;
}