#include <bits/stdc++.h>
using namespace std;
class Edge
{
public:
    int a, b, c;
    Edge(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

bool cmp(Edge l, Edge r)
{
    return l.c < r.c;
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<Edge> edge_list;
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a, b, c));
    }
    sort(edge_list.begin(), edge_list.end(), cmp);
    for (auto edge : edge_list)
    {
        cout << edge.a << " " << edge.b << " " << edge.c << endl;
    }
    return 0;
}