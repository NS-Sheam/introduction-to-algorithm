#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj_list(1005);
vector<bool> visited(1005);
int cnt = 0;

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;
    cout << src << " ";
    cnt++;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        for (int child : adj_list[par])
        {
            if (!visited[child])
            {
                cout << child << " ";
                cnt++;
                q.push(child);
                visited[child] = true;
            }
        }
    }
    cout << endl;
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

    int src;
    cin >> src;
    bfs(src);

    cout << " visited -> " << cnt << endl;
    return 0;
}