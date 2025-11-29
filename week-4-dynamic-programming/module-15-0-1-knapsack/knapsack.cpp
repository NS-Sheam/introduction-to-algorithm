#include <bits/stdc++.h>
using namespace std;
int val[1005], weight[1005];
int knapsack(int i, int mx_weight)
{
    if (i < 0 || mx_weight <= 0)
        return 0;

    if (weight[i] <= mx_weight)
    // 2 option
    // 1. put in bag, 2. not put in the bag
    {
        int opt1 = knapsack(i - 1, mx_weight - weight[i]) + val[i];
        int opt2 = knapsack(i - 1, mx_weight);
        return max(opt1, opt2);
    }
    else
    {

        return knapsack(i - 1, mx_weight);
    }
}

int main()
{
    int n, mx_weight;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> val[i];
    for (int i = 0; i < n; i++)
        cin >> weight[i];
    cin >> mx_weight;
    cout << knapsack(n - 1, mx_weight) << endl;

    return 0;
}