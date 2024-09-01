#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define endl "\n";

vector<lint> dp((int)1e7, -1);
vector<lint> vec;

lint f(int i)
{
    if(i == 0) return vec[0];
    if(dp[i] != -1)
        return dp[i];

    dp[i] = max(f(i-1) + vec[i], vec[i]);
    return dp[i];
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
    {
        maxResult = max(maxResult, f(i));
    }

    cout << maxResult;
}
