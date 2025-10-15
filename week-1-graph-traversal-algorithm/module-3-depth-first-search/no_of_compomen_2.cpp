#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj_list(1005);
vector<bool> vis(1005);
void dfs(int src)
{

    vis[src] = true;
    cout << src << " ";
    for (int child : adj_list[src])
    {
        if (!vis[child])
        {
            dfs(child);
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << i << " -> ";
    //     for (int child : adj_list[i])
    //     {
    //         cout << child << " ";
    //     }
    //     cout << endl;
    // }

    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
            cnt++;
        }
    }
    cout << endl;

    cout << "Component -> " << cnt << endl;

    return 0;
}