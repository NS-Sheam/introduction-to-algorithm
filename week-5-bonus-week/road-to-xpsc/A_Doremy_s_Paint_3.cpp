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
        vector<int> ar(n);
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            mp[a]++;
            ar[i] = a;
            // cout << mp[a] << " ";
        }
        // for (int i = 0; i < n; i++)
        // {
        //     cout << ar[i] << " ";
        // }
        // for (auto it = mp.begin(); it != mp.end(); ++it)
        // {
        //     cout << "Key: " << it->first << ", Value: " << it->second << endl;
        // }
        if (mp.size() > 2)
        {
            cout << "No" << endl;
        }
        else
        {

            if (mp.size() == 2)
            {
                int diff = 0;
                for (pair<int, int> p : mp)
                {
                    diff = abs(diff - p.second);
                }
                if (diff > 1)
                    cout << "No" << endl;
                else
                    cout << "Yes" << endl;
            }
            else
                cout << "Yes" << endl;
        }
    }

    return 0;
}