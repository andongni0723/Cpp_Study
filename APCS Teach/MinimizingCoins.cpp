#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

lint n, target, t;
vector<lint> vec;
lint dp[(lint)1e7 + 10];

lint f(lint c_target)
{
    if(c_target == 0) return 0;
    if(c_target < 0) return 1e7 + 10;

    if(dp[c_target] != -1)
    {
        return dp[c_target];
    }
    else
    {
        lint min_count = 1e7 + 10;
        for (int i = 0; i < n; i++)
        {
            min_count = min(min_count, f(c_target - vec[i]) + 1);
        }

        dp[c_target] = min_count;
        return dp[c_target];
    }
}
int main()
{   
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> target;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        vec.emplace_back(t);
    }

    // INIT
    for (lint i = 0; i < (lint)1e7; i++)
    {
        dp[i] = -1;
    }

    if(f(target) == 1e7 + 10)
        cout << -1;
    else
        cout << f(target);
}