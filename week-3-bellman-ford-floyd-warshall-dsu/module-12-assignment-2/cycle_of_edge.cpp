#include <bits/stdc++.h>
using namespace std;

vector<int> par(100005, -1);
vector<int> group_size(100005, 1);
int find(int node)
{
    if (par[node] == -1)
    {
        return node;
    }
    int leader = find(par[node]);
    par[node] = leader;
    return leader;
}

void dsu_union(int node1, int node2)
{
    int leader1 = find(node1);
    int leader2 = find(node2);

    if (group_size[leader1] >= group_size[leader2])
    {
        par[leader2] = leader1;
        group_size[leader1] += group_size[leader2];
    }
    else
    {
        par[leader1] = leader2;
        group_size[leader2] += group_size[leader1];
    }
}

int main()
{

    int n, e;
    cin >> n >> e;
    int cycle = 0;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        // cout << "a-> " << a << " b-> " << b << endl;
        int leader1 = find(a);
        int leader2 = find(b);
        // cout << "Leader " << leader1 << " " << leader2 << endl;
        if (leader1 == leader2)
            cycle += 1;
        else
            dsu_union(a, b);
    }
    cout << cycle << endl;
    return 0;
}