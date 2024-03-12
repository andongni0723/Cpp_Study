#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define endl "\n";

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);
    stack<int> sta;
    vector<vector<int>> vec(100, vector<int>(100));
    int y, x, t, result = 0;

    cin >> y >> x;
    sta.emplace(-1);
    for (int iy = 0; iy < y; iy++)
    {
        for (int ix = 0; ix < x; ix++)
        {
            cin >> t;
            if(sta.top() == t)
            {
                sta.pop();
                result += t;
            }
            else
            {
                sta.emplace(t);
            }
        }
    }

    cout << result;
}