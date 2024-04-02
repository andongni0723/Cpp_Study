#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define endl "\n";

vector<vector<int>> dp(10, vector<int>(30, -1));

// f(3, 2) 是 300~399 的階梯數字
int f(int i, int j)
{
    if(dp[i][j] != -1)
        return dp[i][j];

    if(j == 0)
    {
        dp[i][j] = 1;
        return dp[i][j];
    }

    int result = 0;
    for (int k = i; k <= 9; k++)
    {
        result += f(k, j-1);
    }

    dp[i][j] = result;
    return dp[i][j];
}

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);
    dp[0][0] = 0;

    int n, ans = 0;
    cin >> n;

    // 23432
    //25
    int past = 0, stop;
    bool isInRange = false;
    string sn = to_string(n);
    for (int i = 0; i < sn.size(); i++)
    {
        isInRange = false;

        // 下限從前一位數開始
        if(i != 0)
            past = (sn[i-1] - '0') > past ? (sn[i-1] - '0') : past;

        // 上限到當前數-1，最後一個數無此限制
        stop = i != sn.size() - 1 ? sn[i] - '0' : sn[i] - '0' + 1;

        for (int j = past; j < stop; j++)
        {
            ans += f(j, sn.size()- (1+i));
            isInRange = true;
        }

        // 如果此回合沒動過
        // => n的當時位數小於上個位數
        // => 不會有答案出現了
        if(!isInRange) break;
    }

//    if(sn[sn.size()-1] - '0' = sn[sn.size()-2] - '0')
//        ans++;

    cout << ans;
}