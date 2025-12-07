#include <bits/stdc++.h>
using namespace std;
vector<int> dp;
int tetranacci(int n)
{

    if (n == 0)
        return n;
    if (n == 1 || n == 2)
        return 1;
    if (n == 3)
        return 2;
    dp[n] = tetranacci(n - 1) + tetranacci(n - 2) + tetranacci(n - 3) + tetranacci(n - 4);
    return dp[n];
}
int main()
{
    int n;
    cin >> n;
    dp.assign(n + 1, -1);
    cout << tetranacci(n);

    return 0;
}