#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define endl "\n";

int m, n;
vector<lint> vec((int)1e5);
vector<lint> dp((int)1e5, -1);

lint f(int i)
{
    if(i == 0) return vec[0];
    if(dp[i] == -1)
    {
        dp[i] = max(f(i-1) + vec[i], vec[i]);
    }

    return dp[i];
}
int main()
{
    cin >> m >> n;

    int t;
    for (int ix = 0; ix < n; ix++)
    {
        cin >> t;
        vec[ix] = t;
    }

    lint result = 0;
    for (int i = 0; i < n; i++)
    {
        result = max(result, f(i));
    }
    cout << result;
}
