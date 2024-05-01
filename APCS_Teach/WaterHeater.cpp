#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define endl "\n";

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    lint n, k, start, end, cost, maxTime = 0;
    vector<lint> vec;
    vector<lint> diff((int)2e5 + 10, 0);

    cin >> n >> k;
    for (lint i = 0; i < n; i++)
    {
        cin >> start >> end >> cost;
        maxTime = max(maxTime, end);

        diff[start] += cost;
        diff[end] -= cost;
    }

    vec.emplace_back(0);
    for (lint i = 0; i <= maxTime; i++)
    {
        vec.emplace_back(vec[i] + diff[i+1]);
    }

    bool ans = true; // true : yes , false: no
    for (lint i = 1; i <= maxTime; i++)
    {
        if(vec[i] > k)
        {
            ans = false;
            break;
        }
    }

    cout << (ans ? "Yes" : "No");

}

//   1 2 3 4 5
// 0 1 1 1 1 1
//   1 3 4 5 5
// 0 1 2 1 1 0
//     +1    -1
