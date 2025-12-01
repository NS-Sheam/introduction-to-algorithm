#include <bits/stdc++.h>
using namespace std;
void print_with_space(int n)
{
    if (n <= 0)
        return;
    print_with_space(n / 10);
    cout << n % 10 << " ";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        print_with_space(n);
        cout << endl;
    }

    return 0;
}