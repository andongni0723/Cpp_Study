#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

vector<pair<lint, lint>> vec; // w, v
lint dp[(lint)1e5 + 10][110]; // v, i


lint f(int _i, int _v)
{
    if(_i < 0 || _v < 0) return 0;

    if(dp[_v][_i] != -1)
    {
        return dp[_v][_i];
    }
    else
    {
        lint choose = f(_i - 1, _v - vec[_i].second) + vec[_i].first;
        lint no_choose = f(_i - 1, _v);
        dp[_v][_i] = max(choose, no_choose);
        return dp[_v][_i];
    }
}

int main()
{   
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    lint n, w, t1, t2;
    cin >> n >> w;

    for (int i = 0; i < n; i++)
    {
        cin >> t1 >> t2;
        vec.emplace_back(t1, t2);
    }

    for (lint i = 0; i < (lint) 1e5; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            dp[i][j] = -1;
        }
    }

    lint appr_w = 0;
    lint max_v = 0;
    lint c_w;
    for (int i = 0; i < 1e5; i++)
    {
        c_w = f(n, i);

        if(c_w > appr_w && c_w <= w)
        {
            appr_w = c_w;
            max_v = i;
        }
    }

    cout << max_v;

}