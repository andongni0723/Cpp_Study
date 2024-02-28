#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

lint n, t;
vector<lint> vec;
lint dp[(int)2e7 + 10] = {0};

lint maxN;

lint f(lint i)
{
    if(i == 1) return vec[0];

    if(dp[i] != (lint)-1e18)
    {
        return dp[i];
    }
    else
    {
        dp[i] = max(f(i-1) + vec[i-1], vec[i-1]);
        maxN = maxN < dp[i] ? dp[i] : maxN ;
        return dp[i];
    }
}
int main()
{   
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < (int)2e7; i++)
    {
        dp[i] = -1e18;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> t;
        vec.emplace_back(t);
    }

    maxN = vec[0];

    f(n);
    cout << maxN;
}