#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

struct hasher
{
    auto operator()(lint const& a) const
    {
        auto ret = 20231225;
        ret ^= a + 0xdefaced;
        return ret;
    }
};

int main()
{   
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    lint n, target, t;
    cin >> n >> target;
    vector<lint> vec;
    unordered_map<lint, lint, hasher> usedNumMap;

    for (lint i = 0; i < n; i++)
    {
        cin >> t;
        vec.emplace_back(t);
    }

    for(lint i = 0 ; i < vec.size() ; i++)
    {
        if(usedNumMap.find(target - vec[i]) != usedNumMap.end()) // Find answer
        {
           cout << usedNumMap[target - vec[i]] << " " << i + 1 ;
           return 0;
        }
        else
        {
            usedNumMap[vec[i]] = i + 1;
        }
    }

    cout << "IMPOSSIBLE";
}