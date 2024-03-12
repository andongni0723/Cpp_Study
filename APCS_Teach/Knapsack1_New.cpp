#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define endl "\n";

int n, max_w, t1, t2;
vector<pair<lint, lint>> vec; // weight, value
vector<vector<lint>> dp(1000, vector<lint>(100010, -1));

lint f(lint i, lint w)
{
    if(i == -1 || w < 0) return 0;

    if(dp[i][w] != -1)
    {
        return dp[i][w];
    }
    else
    {
        lint choose = 0;
        lint not_choose = f(i-1, w);
        if(w - vec[i].first >= 0)
        {
            choose = f(i-1, w - vec[i].first) + vec[i].second;
        }
        dp[i][w] = max(choose, not_choose);
        return dp[i][w];
    }
}

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> max_w;

    for (int i = 0; i < n; i++)
    {
        cin >> t1 >> t2;
        vec.emplace_back(t1, t2);
    }

//    sort(vec.begin(), vec.end());

    cout << f(n-1, max_w);


}