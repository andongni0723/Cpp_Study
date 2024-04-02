#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define endl "\n";
#define MAXN (int)1e5 + 10


int n, p, c;
int rootIndex;
vector<vector<int>> vec(MAXN, vector<int>());
vector<bool> haveParent(MAXN, false);
vector<bool> visited(MAXN, false);

// dfs result
// distance index
vector<pair<int, int>> resultIndex(3,pair<int, int>(make_pair(-1, -1)));

void dfs(int i, int callID, int distance = 0)
{
    visited[i] = true;

    // Update current the most deep leaf node
    if(resultIndex[callID].first < distance)
        resultIndex[callID] = make_pair(distance, i);

    // for the child
    for(auto it : vec[i])
    {
        if(!visited[it])
        {
            dfs(it, callID, distance + 1);
        }
    }


}
int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);


    cin >> n;

    // input
    for (int i = 0; i < n-1; i++)
    {
        cin >> p >> c;
        vec[p].emplace_back(c);
        haveParent[c] = true;
        vec[c].emplace_back(p);
    }

    // find root
    for (int i = 0; i < n; i++)
    {
        if(!haveParent[i])
        {
            rootIndex = i;
            break;
        }
    }

    dfs(rootIndex, 0);
    visited.clear();
    visited.resize(MAXN, false);

    dfs(resultIndex[0].second, 1);
    cout << resultIndex[1].first;
}