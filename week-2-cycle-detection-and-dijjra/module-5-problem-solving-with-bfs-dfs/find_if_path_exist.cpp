#include <bits/stdc++.h>
using namespace std;
int n, e;
vector<vector<int>> adj_list(1005);
vector<bool> vis(1005, false);

void dfs(int src)
{
    // cout << src << " ";
    vis[src] = true;

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
    cin >> n >> e;

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    int src, dist;
    cin >> src >> dist;

    dfs(src);
    cout << vis[dist];

    return 0;
}