#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> adj_list[100005];
bool vis[100005];
int n;
int mn = INT_MAX;

void dfs(int src)
{
    vis[src] = true;
    // cout << src << " ";
    for (pair<int, int> child : adj_list[src])
    {
        mn = min(mn, child.second);
        if (!vis[child.first])
        {
            dfs(child.first);
        }
    }
}

int main()
{
    // vector<vector<int>> roads = {{1, 2, 9}, {2, 3, 6}, {2, 4, 5}, {1, 4, 7}};
    vector<vector<int>> roads = {{3, 2, 1}, {1, 3, 3}};
    n = roads.size();
    memset(vis, false, sizeof(vis));
    // cout << "node size-> " << n;
    for (vector<int> item : roads)
    {
        int a = item[0];
        int b = item[1];
        int c = item[2];
        adj_list[a].push_back({b, c});
        adj_list[b].push_back({a, c});
    }
    dfs(1);
    cout << mn;
    // for (int i = 1; i <= n; i++)
    //     cout << i << " -> " << dis[i] << endl;

    return 0;
}