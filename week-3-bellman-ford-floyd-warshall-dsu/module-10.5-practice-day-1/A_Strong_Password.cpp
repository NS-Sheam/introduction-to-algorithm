#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        bool isInsert = false;
        for (long long int i = 0; i < s.size() - 1; i++)
        {
            cout << s[i];
            if (s[i + 1] == s[i] && !isInsert)
            {
                isInsert = true;
                if (s[i] == 'a')
                    cout << "b";
                else
                    cout << "a";
            }
        }
        cout << s[s.size() - 1];
        if (!isInsert)
        {
            if (s[s.size() - 1] == 'a')
                cout << "b";
            else
                cout << "a";
        }
        cout << endl;
    }
    return 0;
}
