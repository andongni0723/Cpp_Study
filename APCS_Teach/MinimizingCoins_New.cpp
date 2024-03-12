#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define endl "\n";
#define INF (int)1e7 + 10

vector<int> vec;
vector<int> dp((int)1e6 + 10, -1);

int n, target, t;

// 湊出 i 元最少需要幾個硬幣
int f(int i)
{
    if(i == 0) return 0;
    if(i < 0) return INF;

    if(dp[i] != -1)
    {
        return dp[i];
    }
    else
    {
        int ans = INF;
        for (int j = 0; j < n; j++)
        {
            ans = min(f(i - vec[j]) + 1, ans);
        }

        dp[i] = ans;
        return dp[i];
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

    int ans = f(target);

    if(ans == INF)
        cout << -1;
    else
        cout << ans;

}