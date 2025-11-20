#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
bool vis[1005];
int parent[1005];
bool cycle;

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;

    while (!q.empty())
    {
        int par = q.front();
        // cout << par << " ";
        q.pop();
        for (int child : adj_list[par])
        {
            cout << "child => " << child << " parent=> " << par << " parent[par]=> " << parent[par] << " " << (parent[par] != child) << endl;
            if (vis[child] && parent[par] != child)
            {
                // cout << "child => " << child << " parent=> " << par << " parent[par]=> " << parent[par] << " " << (parent[par] != child) << endl;

                cycle = true;
            }
            if (!vis[child])
            {
                q.push(child);
                vis[child] = true;
                parent[child] = par;
            }
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
    memset(vis, false, sizeof(vis));
    memset(parent, -1, sizeof(parent));
    cycle = false;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            bfs(i);
        }
    }

    cout << (cycle ? "DETECTED" : "NO CYCLE");
    // for (int i = 0; i < n; i++)
    // {
    //     cout << i << " parent-> " << parent[i] << endl;
    // }

    return 0;
}