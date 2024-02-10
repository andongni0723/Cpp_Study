#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

bool cmp( pair<int, int> const & p1, pair<int, int> const& p2)
{
    return p1.first < p2.first;
}

int main()
{   
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    lint n, t1, t2;
    vector<pair<int, int>> tasks;
    cin >> n;
    for (lint i = 0; i < n; i++)
    {
        cin >> t1 >> t2;
        tasks.emplace_back(t1, t2);
    }

    sort(tasks.begin(), tasks.end(), cmp);

    lint time = 0, reward = 0;
    for(auto it : tasks)
    {
        time += it.first;
        reward += it.second - time;
    }

    cout << reward;
}