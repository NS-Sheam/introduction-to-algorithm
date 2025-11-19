#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<vector<pair<ll, ll>>> adj_list;
vector<ll> dis;
vector<ll> parent;

class cmp
{
public:
    bool operator()(pair<ll, ll> a, pair<ll, ll> b)
    {
        return a.second > b.second;
    }
};

void dijkstra(ll src)
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, cmp> pq;
    pq.push({src, 0});
    dis[src] = 0;
    while (!pq.empty())
    {
        pair<ll, ll> par = pq.top();
        pq.pop();
        ll par_node = par.first;
        ll par_dis = par.second;
        for (pair<ll, ll> child : adj_list[par_node])
        {
            ll child_node = child.first;
            ll child_dis = child.second;
            if (par_dis + child_dis < dis[child_node])
            {
                dis[child_node] = par_dis + child_dis;
                pq.push({child_node, dis[child_node]});
                parent[child_node] = par_node;
            }
        }
    }
}

int main()
{
    int n, e;

    cin >> n >> e;
    dis.assign(n + 1, LLONG_MAX);
    adj_list.resize(n + 1);
    parent.assign(n + 1, -1);
    while (e--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        adj_list[a].push_back({b, c});
        adj_list[b].push_back({a, c});
    }
    dijkstra(1);
    if (dis[n] == LLONG_MAX)
        cout << -1 << endl;
    else
    {
        ll node = n;
        vector<ll> path;
        while (node != -1)
        {
            path.push_back(node);
            node = parent[node];
        }
        reverse(path.begin(), path.end());
        for (int x : path)
        {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
