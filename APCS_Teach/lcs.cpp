#include <bits/stdc++.h>
using namespace std;
using lint = long long int;


//int dp[1010][1010] = {0};
vector<vector<int>> dp(1010, vector<int>(1010, -1));
string s1, s2;

int f(int i, int j)
{
    if(i <= 0 || j <= 0) return 0;

    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }
    else
    {
        if(s1[i-1] == s2[j-1])
        {
            dp[i][j] = f(i-1, j-1) + 1;
            return dp[i][j];
        }
        else
        {
            dp[i][j] = max(f(i-1, j), f(i, j-1));
            return dp[i][j];
        }
    }
}

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    while(cin >> s1)
    {
        cin >> s2;
        cout << f(s1.size(), s2.size()) << endl;
    }
}