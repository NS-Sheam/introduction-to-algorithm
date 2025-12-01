#include <bits/stdc++.h>
using namespace std;
vector<int> dp;
int fact(int n)
{
    if (n == 1 || n == 0)
        return 1;
    if (dp[n] != -1)
        return dp[n];
    dp[n] = n * fact(n - 1);
    return dp[n];
}
int main()
{
    int n;
    cin >> n;
    dp.assign(n + 1, -1);
    cout << fact(n);
    return 0;
}