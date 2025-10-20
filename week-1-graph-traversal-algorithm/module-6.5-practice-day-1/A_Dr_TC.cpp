#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int oneCnt = 0;
        for (int ch : s)
        {
            if (ch == '1')
                oneCnt++;
        }
        int totalCnt = 0;
        for (int ch : s)
        {
            if (ch == '1')
                totalCnt += (oneCnt - 1);
            else
                totalCnt += (oneCnt + 1);
        }
        cout << totalCnt << endl;
    }
    return 0;
}