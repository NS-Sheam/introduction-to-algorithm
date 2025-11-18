#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<long long int, long long int>>> adj_list;
vector<long long int> dis;

class cmp
{
public:
    bool operator()(pair<long long int, long long int> a, pair<long long int, long long int> b)
    {
        return a.second > b.second;
    }
};

void dijkstra(int src)
{
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, cmp> pq;
    dis.assign(dis.size(), LLONG_MAX);
    pq.push({src, 0});
    dis[src] = 0;
    while (!pq.empty())
    {
        pair<long long, long long> par = pq.top();
        pq.pop();

        long long int par_node = par.first;
        long long int par_dist = par.second;

        if (par_dist != dis[par_node])
            continue;
        for (pair<long long, long long> child : adj_list[par_node])
        {
            long long child_node = child.first;
            long long child_dist = child.second;

            if (par_dist + child_dist < dis[child_node])
            {
                dis[child_node] = par_dist + child_dist;
                pq.push({child_node, dis[child_node]});
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    adj_list.resize(n + 1);
    dis.assign(n + 1, LLONG_MAX);
    while (e--)
    {
        long long int a, b, c;
        cin >> a >> b >> c;
        adj_list[a].push_back({b, c});
    }

    int q;
    cin >> q;
    while (q--)
    {
        int src, dist;
        cin >> src >> dist;
        dijkstra(src);
        if (dis[dist] == LLONG_MAX)
            cout << -1 << endl;
        else
            cout << dis[dist] << endl;
    }

    return 0;
}