#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define endl "\n";

int main()
{
    int n, m, k;
    cin >> n >> m;
    vector<pair<int, int>> vec;

    int t, t1, t2;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        vec.emplace_back(t, m);
    }

    cin >> k;
    lint result = 0;
    for (int i = 0; i < k; i++)
    {
        cin >> t >> t1 >> t2;

        for (int i = 0; i < n; i++)
        {
            if(t <= vec[i].first && vec[i].first <= t1)
            {
                vec[i].second = t2;
                // cout << it.second;
                // it = make_pair(it.first, t2);
                // cout << "d";
            }
        }
    }

    for(auto it : vec)
    {
        result += it.second;
    }

    cout << result;
}