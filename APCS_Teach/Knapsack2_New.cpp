#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define endl "\n";

vector<pair<lint, lint> > vec; // w, v                                   //改了這裡
vector<vector<lint> > dp(110, vector<lint>((int)1e5 + 10, (int)1e9 + 10));

// 前i個物品中，背包價值為v時最小重量
lint f(lint i, lint v)
{
    if(v == 0) return 0;
    if(i < 0 || v < 0) return 1e18;

    if(dp[i][v] != (int)1e9 + 10)
    {
        return dp[i][v];
    }
    else
    {
        lint no_choose = f(i - 1, v);

        lint choose = (int)1e9;

        if(v >= vec[i].second)
            choose = f(i - 1, v - vec[i].second) + vec[i].first;

                    //改了這裡
        dp[i][v] = min(no_choose, choose);
        return dp[i][v];
    }
}

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    int n, w, t1, t2;
    cin >> n >> w;
    for (int i = 0; i < n; i++)
    {
        cin >> t1 >> t2;
        vec.emplace_back(t1, t2);
    }

    lint current_w = 0;
    lint max_v = 0;
    for (int iv = 0; iv <= (int)1e5; iv++)
    {
        current_w = f(n-1, iv);

        // 在越接近 W 的情況下，v要越大
        // => ?
        if(current_w <= w) // 判斷式要如何寫？
        {
            max_v = iv;
        }
    }

    cout << max_v;

}
