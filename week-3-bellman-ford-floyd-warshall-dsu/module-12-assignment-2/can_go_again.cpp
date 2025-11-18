#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    long long int a, b, c;
    Edge(long long a, long long b, long long c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

vector<Edge> edge_list;
vector<long long int> dis;
int n, e;
bool cycle = false;
void bellmen_ford()
{
    for (int i = 0; i < n - 1; i++)
    {
        for (Edge ed : edge_list)
        {
            int a = ed.a;
            int b = ed.b;
            long long int c = ed.c;
            if (dis[a] != LLONG_MAX && dis[a] + c < dis[b])
            {
                dis[b] = dis[a] + c;
            }
        }
    }

    for (Edge ed : edge_list)
    {
        int a = ed.a;
        int b = ed.b;
        long long int c = ed.c;
        if (dis[a] != LLONG_MAX && dis[a] + c < dis[b])
        {
            cycle = true;
            break;
        }
    }
}

int main()
{
    cin >> n >> e;
    dis.assign(n + 5, LLONG_MAX);
    while (e--)
    {
        long long int a, b, c;
        cin >> a >> b >> c;
        // cout << a << " " << b << " " << c << endl;
        Edge e(a, b, c);
        edge_list.push_back(e);
    }
    // cout << n << e;

    for (int i = 0; i < n; i++)
    {
        dis[i] = LLONG_MAX;
    }
    int src;
    cin >> src;
    dis[src] = 0;
    // cout << src << endl;
    bellmen_ford();

    if (cycle)
    {

        cout << "Negative Cycle Detected" << endl;
        return 0;
    }

    int t;
    cin >> t;
    while (t--)
    {
        int dist;
        cin >> dist;
        if (dis[dist] == LLONG_MAX)
            cout << "Not Possible" << endl;
        else
            cout << dis[dist] << endl;
    }

    return 0;
}