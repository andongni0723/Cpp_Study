#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define endl "\n";

vector<int> dp((int)1e6 + 10, -1);

// 當前數字為 i 時，減位數到 0 的最小步數
int f(int i)
{
    if(i <= 0) return 0;
    
    if(dp[i] != -1)
    {
        return dp[i];
    }
    else
    {
        string string_i = to_string(i);
        int count = string_i.size(); // 得到 string_i 的位數
        int min = (int)1e8, current_num;
        for (int j = 0; j < count; j++)
        {
            if(string_i[j] == '0')
                continue;

            current_num = f(i - (string_i[j] - '0')) + 1;

            if(current_num < min)
            {
                min = current_num;
            }
        }

        dp[i] = min;
        return dp[i];
    }
}

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    int i;
    cin >> i;
    cout << f(i);

}