#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj_list(1005);
vector<bool> vis(1005, false);
void dfs(int src)
{
    cout << src << " ";
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
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    vector<int> reps;

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            reps.push_back(i);
            dfs(i);
        }
    }
    cout << endl;
    for (int i = 1; i < reps.size(); i++)
    {
        cout << reps[i - 1] << " " << reps[i] << endl;
    }

    return 0;
}