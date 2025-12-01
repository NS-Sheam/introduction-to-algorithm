#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> nums;
vector<int> dp;

int mx_money(int i)
{

    if (i >= n)
        return 0;
    if (dp[i] != -1)
        return dp[i];
    int item = mx_money(i + 2) + nums[i];
    int skip = mx_money(i + 1);

    return dp[i] = max(item, skip);
}
int main()
{
    cin >> n;
    dp.assign(n, -1);
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        nums.push_back(a);
    }
    // cout << n;
    int rob = mx_money(0);
    cout << rob;

    cout << endl;

    // for (int i = 0; i < n; i++)
    // {
    //     cout << nums[i] << " ";
    // }

    return 0;
}