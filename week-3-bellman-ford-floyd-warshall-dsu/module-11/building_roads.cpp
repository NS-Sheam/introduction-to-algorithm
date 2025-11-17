#include <bits/stdc++.h>
using namespace std;

int par[1000005];
int group_size[1000005];

int find(int node)
{
    if (par[node] == -1)
        return node;
    return par[node] = find(par[node]);
}

void dsu_union(int a, int b)
{
    int leaderA = find(a);
    int leaderB = find(b);

    if (leaderA == leaderB)
        return;

    if (group_size[leaderA] >= group_size[leaderB])
    {
        par[leaderB] = leaderA;
        group_size[leaderA] += group_size[leaderB];
    }
    else
    {
        par[leaderA] = leaderB;
        group_size[leaderB] += group_size[leaderA];
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    // initialize DSU
    memset(par, -1, sizeof(par));
    for (int i = 1; i <= n; i++)
        group_size[i] = 1;

    // read initial roads
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        dsu_union(a, b);
    }

    vector<int> leaders;

    // collect all unique component leaders
    for (int i = 1; i <= n; i++)
    {
        if (find(i) == i)
        {
            leaders.push_back(i);
        }
    }

    // the number of roads needed = components - 1
    cout << leaders.size() - 1 << "\n";

    // connect components in a chain
    for (int i = 1; i < leaders.size(); i++)
    {
        cout << leaders[i - 1] << " " << leaders[i] << "\n";
    }

    return 0;
}
