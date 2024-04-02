#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define endl "\n";


int n, t;
vector<vector<int>> vec((int)2e5 + 100, vector<int>());
vector<int> dp((int)2e5 + 100, -1);

int getChildTreeSize(int index) // one-based
{
    if(dp[index] != -1) return dp[index];

    int result = 0;
    int childSize = vec[index].size();
    for (int k = 0; k < childSize; k++)
    {
        result += getChildTreeSize(vec[index][k]);
    }
    dp[index] = result + 1;
    return dp[index];
}

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        cin >> t;
        vec[t].emplace_back(i);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << getChildTreeSize(i) - 1 << " ";
    }

}