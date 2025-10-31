#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int total = a + b + c;

        if (total % 3 == 0 && a <= total / 3 && b <= total / 3)
        {
            cout << "YES\n";
        }
        else
            cout << "NO\n";
    }
    return 0;
}