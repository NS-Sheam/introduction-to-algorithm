#include <bits/stdc++.h>
using namespace std;
int n, mx_weight;
int val[1005], weight[1005];
vector<vector<int>> dp;

int knapsack(int i, int mx_weight)
{
    // cout << mx_weight << endl;
    if (i < 0 || mx_weight <= 0)
        return 0;
    if (dp[i][mx_weight] != -1)
        return dp[i][mx_weight];
    if (weight[i] <= mx_weight)
    {
        int opt1 = knapsack(i - 1, mx_weight - weight[i]) + val[i];
        int opt2 = knapsack(i - 1, mx_weight);
        dp[i][mx_weight] = max(opt1, opt2);
    }
    else
    {

        dp[i][mx_weight] = knapsack(i - 1, mx_weight);
    }
    return dp[i][mx_weight];
    return 0;
}
int main()
{
    cin >> n >> mx_weight;
    dp.assign(n + 1, vector<int>(mx_weight + 1, -1));
    // for (int i = 0; i <= n; i++)
    //     for (int j = 0; j <= mx_weight; j++)
    //         cout << dp[i][j];
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i] >> val[i];
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << " " << weight[i] << " " << val[i];
    // }

    cout << knapsack(n - 1, mx_weight);

    return 0;
}