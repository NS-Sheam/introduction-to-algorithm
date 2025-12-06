#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> tng;

void make_tng(int totalRows)
{
    if (totalRows == 0)
    {
        tng.push_back({1});
        return;
    }

    make_tng(totalRows - 1);

    vector<int> prev = tng.back();
    vector<int> row(totalRows + 1);

    row[0] = row[totalRows] = 1;

    for (int i = 1; i < totalRows; i++)
    {
        row[i] = prev[i - 1] + prev[i];
    }

    tng.push_back(row);
}

int main()
{
    int numRows;
    cin >> numRows;

    // make_tng(numRows - 1);

    // for (auto &r : tng)
    // {
    //     for (int x : r)
    //         cout << x << " ";
    //     cout << "\n";
    // }
    vector<vector<int>> dp(numRows);

    for (int r = 0; r < numRows; r++)
    {
        dp[r].resize(r + 1);
        dp[r][0] = dp[r][r] = 1; // edges are always 1

        // fill mid values using DP relation
        for (int c = 1; c < r; c++)
        {
            dp[r][c] = dp[r - 1][c - 1] + dp[r - 1][c];
        }
    }

    for (auto i : dp)
    {
        for (int x : i)
        {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
