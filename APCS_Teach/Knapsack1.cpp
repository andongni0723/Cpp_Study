#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

lint n, w, w1, v1;
vector<pair<lint, lint>> vec(n);
lint dp[(lint)1e5 + 10][110];

lint f(lint _w, lint _i)
{
    if(_i == -1) return 0;

    if(dp[_w][_i] != -1)
    {
        return dp[_w][_i];
    }
    else
    {
        lint f_v1 = 0;

        if(_w >= vec[_i].first)
            f_v1 = f(_w - vec[_i].first, _i - 1) + vec[_i].second;

        lint f_v2 = f(_w, _i - 1);
        dp[_w][_i] = max(dp[_w][_i], max(f_v1, f_v2));
        return dp[_w][_i];
    }

}

int main()
{   
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    for (lint i = 0; i < (lint) 1e5 + 10; i++)
    {
        for(lint j = 0 ; j < 110 ; j++)
        {
            dp[i][j] = -1;
        }
    }

    cin >> n >> w;

    for (int i = 0; i < n; i++)
    {
        cin >> w1 >> v1;
        vec.emplace_back(w1, v1);
    }



    cout << f(w, n-1);
}