#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

int main()
{   
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    stack<pair<lint, lint>> sta; // x, index
    lint n, t;

    sta.emplace(0, 0);
    cin >> n;
    for (lint i = 0; i < n; i++)
    {
        cin >> t;
        for (int j = 0; j < i + 1; j++)
        {
            if(sta.top().first >= t)
            {
                sta.pop();
            }
            else
            {
                cout << sta.top().second << " ";
                sta.emplace(t, i + 1);
                break;
            }
        }
    }
}