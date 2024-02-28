#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

int n;
vector<int> dp(100, -1);

int fib(int a)
{
    if(a == 1 || a == 2) return 1;
    if(dp[a] != -1) return dp[a];

    dp[a] = fib(a-1) + fib(a-2);
    return dp[a];
}
int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    cout << fib(n);
}