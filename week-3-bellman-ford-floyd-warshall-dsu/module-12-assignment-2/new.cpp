#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<long long, long long>>> adj_list;
vector<long long> dis;

class cmp
{
public:
    bool operator()(pair<long long, long long> a, pair<long long, long long> b)
    {
        return a.second > b.second;
    }
};

void dijkstra(int src, int n)
{
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, cmp> pq;
    dis.assign(n + 1, LLONG_MAX);
    pq.push({src, 0});
    dis[src] = 0;

    while (!pq.empty())
    {
        auto par = pq.top();
        pq.pop();
        long long u = par.first;
        long long dist_u = par.second;

        if (dist_u != dis[u])
            continue;

        for (auto &child : adj_list[u])
        {
            long long v = child.first;
            long long w = child.second;
            if (dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
                pq.push({v, dis[v]});
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    adj_list.resize(n + 1);

    while (e--)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        adj_list[a].push_back({b, c});
    }

    int q;
    cin >> q;
    vector<pair<int, int>> queries(q);
    vector<int> unique_sources;
    vector<bool> is_source(n + 1, false);

    for (int i = 0; i < q; i++)
    {
        cin >> queries[i].first >> queries[i].second;
        int src = queries[i].first;
        if (!is_source[src])
        {
            unique_sources.push_back(src);
            is_source[src] = true;
        }
    }

    vector<vector<long long>> all_dis(n + 1);
    for (int src : unique_sources)
    {
        dijkstra(src, n);
        all_dis[src] = dis;
    }

    for (auto &[src, dst] : queries)
    {
        if (all_dis[src][dst] == LLONG_MAX)
            cout << -1 << "\n";
        else
            cout << all_dis[src][dst] << "\n";
    }

    return 0;
}
