#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        vector<int> freq(7, 0);
        int prb_needed = 0;
        for (int c : s)
        {
            // cout << freq[c - 'A'] << endl;
            freq[c - 'A']++;
        }
        for (int i : freq)
        {
            // cout << "m-> " << m << " i-> " << i << " (m - i)-> " << (m - i) << endl;
            if (i < m)
                prb_needed += m - i;
        };
        cout << prb_needed << endl;
    }

    return 0;
}