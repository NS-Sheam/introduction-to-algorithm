#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int nums[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << nums[i] << " ";
    // }

    int mxL = 0;
    for (int i = 0; i < n; i++)
    {
        set<int> evenSet;
        set<int> oddSet;

        for (int j = i; j < n; j++)
        {
            if (nums[j] % 2 == 0)
                evenSet.insert(nums[j]);
            else
                oddSet.insert(nums[j]);

            if (evenSet.size() == oddSet.size())
            {
                mxL = max(mxL, j - i + 1);
            }
        }
    }

    cout << mxL << endl;

    // for (auto i = evenMap.begin(); i != evenMap.end(); i++)
    // {
    //     cout << i->first << " -> " << i->second << endl;
    // }
    // for (auto i = oddMap.begin(); i != oddMap.end(); i++)
    // {
    //     cout << i->first << " -> " << i->second << endl;
    // }
    return 0;
}