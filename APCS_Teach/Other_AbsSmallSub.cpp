#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define endl "\n";

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    vector<pair<int, int>> vec; // value index
    vector<pair<int, int>> prefix; // value index
    int n, t;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> t;
        vec.emplace_back(make_pair(t, i+1));
    }
    
    //prefix
    prefix.emplace_back(make_pair(0, 0));
    for (int i = 0; i < n; i++)
    {
        prefix.emplace_back(make_pair(prefix[i].first + vec[i].first, i + 1));
    }

    sort(prefix.begin(), prefix.end());

    int L, R;
    L = min(prefix[0].second, prefix[1].second) + 1;
    R = max(prefix[0].second, prefix[1].second);
    cout << L << " " << R;
    
}