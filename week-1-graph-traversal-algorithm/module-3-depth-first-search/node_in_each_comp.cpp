#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj_list(1005);
vector<bool> vis(1005);
void dfs(int src, int &cnt)
{

    vis[src] = true;
    cout << src << " ";
    cnt++;
    for (int child : adj_list[src])
    {
        if (!vis[child])
        {
            dfs(child, cnt);
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

    vector<int> nodes;

    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        if (!vis[i])
        {
            dfs(i, cnt);
            nodes.push_back(cnt);
        }
    }
    cout << endl;

    sort(nodes.begin(), nodes.end());
    cout << "Component -> " << endl;
    for (int node : nodes)
    {
        cout << node << " ";
    }

    return 0;
}