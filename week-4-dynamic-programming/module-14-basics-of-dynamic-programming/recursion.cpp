#include <bits/stdc++.h>
using namespace std;
int rec(int n)
{
    if (n > 5)
        return 0;
    int sum = n + rec(n + 1);
    return sum;
}
int main()
{
    // rec(1);
    cout << rec(1) << endl;
    return 0;
}