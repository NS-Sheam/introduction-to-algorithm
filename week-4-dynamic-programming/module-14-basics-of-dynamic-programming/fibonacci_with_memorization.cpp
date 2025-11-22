#include <bits/stdc++.h>
using namespace std;
vector<int> dp;
int fibo(int n)
{
    if (n == 0 || n == 1)
        return n;

    dp[n] = fibo(n - 1) + fibo(n - 2);
    return dp[n];
}
int main()
{
    int n;
    cin >> n;
    dp.assign(n + 1, -1);
    cout << fibo(n) << endl;
    return 0;
}