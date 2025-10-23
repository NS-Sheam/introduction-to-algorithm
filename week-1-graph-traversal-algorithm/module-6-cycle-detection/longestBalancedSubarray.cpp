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

    map<int, int> evenMap;
    map<int, int> oddMap;
    int mxL = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] % 2 == 0)
            evenMap[nums[i]]++;
        else
            oddMap[nums[i]]++;
        cout << " evenSize =-> " << evenMap.size() << " oddSize-> " << oddMap.size() << " i-> " << i << endl;
        if (evenMap.size() == oddMap.size())
        {
            mxL = max(mxL, i + 1);
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