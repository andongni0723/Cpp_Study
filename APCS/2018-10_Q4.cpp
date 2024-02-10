#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

vector<lint> vec;
lint dp[110][(lint)2e5 + 10];

lint f(lint i, lint need_s)
{
    if(need_s == 0 || need_s < -vec[i]) return 0;
    if(i < 0) return 2e5 + 10;

    if(dp[i][need_s] != -1)
    {
        return dp[i][need_s];
    }
    else
    {
        lint choose = f(i-1, need_s - vec[i]) + vec[i];
        lint no_choose = f(i-1, need_s);
        dp[i][need_s] = min(choose, no_choose);
        return dp[i][need_s];
    }
}

int main()
{   
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    lint n, m, s, t, sum_out = 0, have;
    cin >> n >> m >> s;

    for (int i = 0; i < n; i++)
    {
        cin >> t;
        vec.emplace_back(t);
        sum_out += t;
    }
    have = s - (m - sum_out);

    // INIT
    for (int i = 0; i < 100; i++)
    {
        for (lint j = 0; j < (lint)2e5; j++)
        {
            dp[i][j] = -1;
        }
    }


    cout << f(n, have);
}