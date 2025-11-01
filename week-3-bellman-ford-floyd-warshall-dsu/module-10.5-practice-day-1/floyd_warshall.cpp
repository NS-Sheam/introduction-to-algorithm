#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<vector<long long>> dis = {{0, 4, LLONG_MAX, 5, LLONG_MAX}, {LLONG_MAX, 0, 1, LLONG_MAX, 6}, {2, LLONG_MAX, 0, 3, LLONG_MAX}, {LLONG_MAX, LLONG_MAX, 1, 0, 2}, {1, LLONG_MAX, LLONG_MAX, 4, 0}};

    for (int i = 0; i < dis.size(); i++)
    {
        for (int j = 0; j < dis.size(); j++)
        {
            cout << dis[i][j] << " ";
        }
        cout << endl;
    }

    for (long long k = 0; k < dis.size(); k++)
    {
        for (long long i = 0; i < dis.size(); i++)
        {
            for (long long j = 0; j < dis.size(); j++)
            {
                if (dis[i][k] != LLONG_MAX && dis[k][j] != LLONG_MAX && dis[i][k] + dis[k][j] < dis[i][j])
                {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }
    for (long long i = 0; i < dis.size(); i++)
    {
        for (long long j = 0; j < dis.size(); j++)
        {
            cout << dis[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}