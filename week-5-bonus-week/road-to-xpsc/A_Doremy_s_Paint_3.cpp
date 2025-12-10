#include <bits/stdc++.h>
using namespace std;
map<int, int> freq;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> ar(n);
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            freq[a]++;
            if (freq[a] > 2)
            {
                cout << "NO" << endl;
                break;
            }
            ar[i] = a;
            // cout << freq[a] << " ";
        }
        // for (int i = 0; i < n; i++)
        // {
        //     cout << ar[i] << " ";
        // }
        cout << endl;
    }

    return 0;
}