#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

int main()
{   
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    vector<int> vec;
    unordered_map<int, int> hash_map;

    for (int i = 0; i < 3; i++)
    {
        cin >> t;
        vec.emplace_back(t);
        hash_map[t]++;
    }

    sort(vec.begin(), vec.end(), greater<int>());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());

    int maxCount = 0;
    for(auto it : vec)
    {
        if(hash_map[it] > maxCount)
            maxCount = hash_map[it];
    }

    cout << maxCount << " ";

    for(auto it : vec)
    {
        cout << it << " ";
    }


}