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
        int ht[n];
        for (int i = 0; i < n; i++)
        {
            cin >> ht[i];
        }
        for (int i = 0; i < n; i++)
        {
            // cout << ht[i] << " ";
        }
        // cout << endl;

        int left = 0;
        int right = n - 1;
        pair<int, int> mx_idx;
        int mx = 0;
        while (left < right)
        {
            int volume = (right - left) * min(ht[left], ht[right]);
            if (volume > mx)
            {
                mx = volume;
                mx_idx = {left, right};
            }
            if (ht[left] < ht[right])
                left++;
            else
                right--;
        }
        cout << mx_idx.first << " " << mx_idx.second << endl;
    }
    return 0;
}