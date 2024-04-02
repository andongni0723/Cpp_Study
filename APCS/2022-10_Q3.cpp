#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define endl "\n";

lint result = 0;
vector<int> numVec;
vector<vector<int>> tree((int)1e6+100, vector<int>());

void input(int parent)
{
    int t;
    int levelChildCount;
    cin >> t;
    numVec.emplace_back(t);
    levelChildCount = t % 2 == 0 ? 2 : 3;
    levelChildCount = t == 0 ? 0 : levelChildCount;

    if (parent != -1 && t != 0) // isFirst
    {
        tree[parent].emplace_back(t);
        result += abs(parent - t);
    }

    for (int i = 0; i < levelChildCount; i++)
    {
        input(t);
    }
}

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    input(-1);

    cout << result;
}