#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

int main()
{   
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    int n, in, out;
    map<int, int> timeMap;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> in >> out;
        ++timeMap[in];
        --timeMap[out];
    }

    int currentCustom = 0, maxCustom = 0;
    for (auto it : timeMap) {
        maxCustom = max(maxCustom, currentCustom += it.second);
    }

    cout << maxCustom;
}