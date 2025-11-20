#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> grid(10005, vector<int>(10005));
vector<vector<bool>> vis(10005, vector<bool>(false));
vector<pair<int, int>> dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
int n, m;
bool is_valid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}