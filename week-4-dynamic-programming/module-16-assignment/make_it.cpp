#include <bits/stdc++.h>
using namespace std;
vector<bool> dp;
bool solution(long long n)
{
    while (n > 1)
    {
        if (n % 2 == 0)
        {
            n /= 2;
        }
        else
        {
            n -= 3;
        }
        if (n < 1)
            return false;
    }
    return n == 1;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        dp.assign(n + 1, false);
        cout << (solution(n) ? "YES" : "NO") << endl;
    }

    return 0;
}