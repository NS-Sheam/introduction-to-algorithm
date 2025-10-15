#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> adj_list[1005];

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        // cout << a << b << "a b" << endl;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    int q;
    cin >> q;
    while (q--)
    {
        int a;
        cin >> a;
        sort(adj_list[a].begin(), adj_list[a].end(), greater<int>());

        if (!adj_list[a].size())
        {
            cout << -1 << endl;
            continue;
        }

        for (int child : adj_list[a])
        {
            cout << child << " ";
        }

        cout << endl;
    }

    return 0;
}