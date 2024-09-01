#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define endl "\n";

vector<vector<lint>> dp(160000, vector<lint>(30, -1));
vector<lint> vec;

lint f(int i, int k)
{
    if(i == 0) return vec[0];
    // if(k < 0) return -1000;
    if(dp[i][k] != -1)
        return dp[i][k];

    if(k == 0)
        dp[i][k] = max(f(i-1, k) + vec[i], vec[i]);
    else
        dp[i][k] = max(f(i-1, k-1), f(i-1, k) + vec[i]);
    return dp[i][k];
}
int main()
{
    int n, k;
    cin >> n >> k;

    int t;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        vec.emplace_back(t);
    }

    lint maxResult = 0;
    for (int i = 0; i < n; i++)
        maxResult = max(maxResult, f(i, k));

    cout << maxResult;
}
