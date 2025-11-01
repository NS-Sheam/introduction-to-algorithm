#include <bits/stdc++.h>
using namespace std;
vector<int> vis;
vector<vector<int>> result;
int n;

void dfs(int src, vector<vector<int>> &graph)
{
    vis.push_back(src);
    if (src == n - 1)
        result.push_back(vis);
    for (int child : graph[src])
    {
        dfs(child, graph);
    }
    vis.pop_back();
}

int main()
{
    vector<vector<int>> graph = {{1, 2}, {3}, {3}, {}};
    n = graph.size();
    dfs(0, graph);
    for (int i = 0; i < result.size(); i++)
    {
        for (int item : result[i])
        {
            cout << item << " ";
        }
        cout << endl;
    }

    return 0;
}