#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> ht(n);

        int mx1 = INT_MIN;
        int mx1_idx = -1;
        int mx2 = INT_MIN;
        int mx2_idx = -1;

        for (int i = 0; i < n; i++)
        {
            cin >> ht[i];

            if (ht[i] > mx1)
            {
                mx2 = mx1;
                mx2_idx = mx1_idx;

                mx1 = ht[i];
                mx1_idx = i;
            }
            else if (ht[i] > mx2)
            {
                mx2 = ht[i];
                mx2_idx = i;
            }
        }

        if (mx1_idx < mx2_idx)
        {
            cout << mx1_idx << " " << mx2_idx << endl;
        }
        else
        {
            cout << mx2_idx << " " << mx1_idx << endl;
        }
    }
    return 0;
}