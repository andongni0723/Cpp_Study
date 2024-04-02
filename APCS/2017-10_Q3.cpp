#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define endl "\n";


vector<vector<int>> vec((int)1e6 + 100, vector<int>());
vector<bool> haveParent((int)1e6 + 100, false);
int rootIndex = -1;
int n, t, c;

vector<int> dp((int)1e6 + 100, -1);

int h(int i) // 節點i的高度
{
    // have ans
    if(dp[i] != -1) return dp[i];

    // leaf node
    if(vec[i].size() == 0)
    {
        dp[i] = 0;
        return dp[i];
    }

    // other
    int high = 0;
    for (int j = 0; j < vec[i].size(); j++)
    {
        high = max(h(vec[i][j]), high);
    }
    dp[i] = high + 1;
    return dp[i];
}

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> t;
        for (int j = 0; j < t; j++) // child
        {
            cin >> c;
            haveParent[c] = true;
            vec[i].emplace_back(c);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if(!haveParent[i])
            rootIndex = i;
    }
    cout << rootIndex << endl;

    lint sumHigh = 0;
    for (int i = 1; i <= n; i++)
    {
        sumHigh += h(i);
    }

    cout << sumHigh;


}