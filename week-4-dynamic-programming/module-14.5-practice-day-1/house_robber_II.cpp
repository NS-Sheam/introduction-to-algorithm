#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> nums;
vector<int> dp;

int mx_money(int i, int endIdx)
{

    if (i > endIdx)
        return 0;
    if (dp[i] != -1)
        return dp[i];
    int item = mx_money(i + 2, endIdx) + nums[i];
    int skip = mx_money(i + 1, endIdx);

    return dp[i] = max(item, skip);
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        nums.push_back(a);
    }
    dp.assign(n, -1);
    // cout << n;
    int rob1 = mx_money(0, n - 2);
    dp.assign(n, -1);
    int rob2 = mx_money(1, n - 1);
    cout << max(rob1, rob2);

    cout << endl;

    // for (int i = 0; i < n; i++)
    // {
    //     cout << nums[i] << " ";
    // }

    return 0;
}