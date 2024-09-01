#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define endl "\n";

vector<int> food((int)1e6 + 10);
vector<int> leftest((int)1e6 + 10, 1);
vector<int> visited((int)1e6 + 10, -1);
vector<vector<lint>> dp((int)1e6 + 10, vector<lint>(30, -1));

lint f(int i,int k)
{
    if(i <= 0 || k <= 0) return 0;
    if(dp[i][k] != -1)
        return dp[i][k];

    dp[i][k] = max(f(i-1, k), f(leftest[i] - 1, k-1) + (i - leftest[i] + 1));
    return dp[i][k];
}
int main()
{
    int n, k;
    cin >> n >> k;

    int t;
    for (int i = 1; i <= n; i++)
    {
        cin >> t;
        food[i] = t;
    }

    for (int i = n; i > 0; i--)
    {
        if(visited[food[i]] != -1)
        {
            leftest[visited[food[i]]] = i+1;
            visited[food[i]] = i;
        }
        else
            visited[food[i]] = i;
    }

    cout << f(n, k);
}
