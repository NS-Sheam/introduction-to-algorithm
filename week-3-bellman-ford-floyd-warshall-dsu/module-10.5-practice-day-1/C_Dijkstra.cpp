#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<long long int, long long int>>> adj_list(100005);
vector<long long int> dis(100005, LLONG_MAX);
vector<long long int> parent(100005, -1);

class cmp
{
public:
    bool operator()(pair<long long int, long long int> a, pair<long long int, long long int> b)
    {
        return a.second > b.second;
    }
};

void dijkstra(long long int src, long long int n)
{
    priority_queue<pair<long long int, long long int>, vector<pair<long long int, long long int>>, cmp> pq;
    pq.push({src, 0});
    dis[src] = 0;

    while (!pq.empty())
    {
        auto [par_node, par_dist] = pq.top();
        pq.pop();

        if (par_dist > dis[par_node])
            continue;

        for (auto [child_node, child_dist] : adj_list[par_node])
        {
            if (par_dist + child_dist < dis[child_node])
            {
                dis[child_node] = par_dist + child_dist;
                parent[child_node] = par_node;
                pq.push({child_node, dis[child_node]});
            }
        }
    }
}

int main()
{
    long long int n, e;
    cin >> n >> e;
    while (e--)
    {
        long long int a, b, c;
        cin >> a >> b >> c;
        adj_list[a].push_back({b, c});
        adj_list[b].push_back({a, c});
    }

    dijkstra(1, n);

    if (dis[n] == LLONG_MAX)
    {
        cout << -1 << endl;
    }
    else
    {
        vector<long long int> path;
        for (long long int v = n; v != -1; v = parent[v])
            path.push_back(v);
        reverse(path.begin(), path.end());
        for (long long int v : path)
            cout << v << " ";
        cout << endl;
    }
}
