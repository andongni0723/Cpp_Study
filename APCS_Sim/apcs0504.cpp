#include <bits/stdc++.h>
using namespace std;
#define lint long long

vector<vector<int>> tree((int)2e5 + 10, vector<int>());
vector<bool> visited((int)2e5 + 10, false);
vector<vector<int>> realTree((int)2e5 + 10, vector<int>());
// ^^ 把tree 排成順序的「鏈」
//  1
//2   3    =>  1-2-3

vector<lint> cost;
vector<bool> hasCalled((int)2e5 + 10, false);
int root;
int n;

void dfs(int index)
{
    visited[index] = true;

    for(auto c : tree[index])
    {
        if(!visited[c])
        {
            realTree[index].emplace_back(c);
            dfs(c);
        }
    }
}

// find tree root point
void findRoot()
{
    for (int i = 1; i <= n; i++)
    {
        if(tree[i].size() > 0)
            hasCalled[tree[i][0]] = true;
    }

    for (int i = 1; i <= n; i++)
    {
        if(!hasCalled[i])
            root = i;
    }
}

#define MAXN 1e17;
vector<vector<lint>> dp((int)2e5 + 10, vector<lint>(10, -1));

//以第 j 個節點為根的子樹全部點亮的最小花費，b = 0/1 表示第 j 個節點有 / 沒有發電機
lint f(int b, lint j)
{
    if(tree[j].size() == 0) return b;

    if(dp[b][j] != -1)
        return dp[b][j];

    if(b == 1)
    {
        //所以對他的每一個 child k 我們選 min(dp(0, k), dp(1, k))
        for(auto c : tree[j])
            dp[b][j] = min(f(0, c), f(1,c));
    }
    else if(b == 0)
    {
        // 所以先檢查他的 child k 有沒有 dp(1, k) < dp(0, k) 的
        bool isbig = false;
        for(auto c : tree[j])
        {
            if(f(1, c) < f(0, c))
            {
                isbig = true;
                break;
            }
        }

        if(isbig)
        {
            // 有的話就照 dp(1, j) 的選法；
            for(auto c : tree[j])
                dp[b][j] = min(dp[b][j], min(f(0, c), f(1,c)));
        }
        else
        {
            //沒有的話就先把所有的 dp(0, k) 加起來，
            lint sum = 0;
            for(auto c : tree[j])
                sum += f(0, c);

            //之後掃一遍看把哪個 dp(0, k) 換成 dp(1, k) 最划算
            //( dp(1, k) - dp(0, k) 最小)
            lint minC = MAXN;
            for(auto c : tree[j])
            {
                sum -= f(0, c);
                sum += f(1, c);
                minC = min(minC, sum);
                sum += f(0, c);
                sum -= f(1, c);
            }

            sum -= f(0, minC);
            sum += f(1, minC);
            dp[b][j] = sum;
        }
    }

    return dp[b][j];
}

int main()
{
    cin >> n;

    int t1, t2;
    //input
    for (int i = 1; i <= n-1; i++)
    {
        cin >> t1 >> t2;
        tree[t1].emplace_back(t2);
        // tree[t2].emplace_back(t1);
    }

    for (int i = 0; i < n; i++)
    {
        cin >> t1;
        cost.emplace_back(t1);
    }

    findRoot();
    dfs(root);

    // cout << f(root, 0);
    cout << min(f(0, root), f(1, root));
}