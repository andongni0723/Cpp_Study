#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define endl "\n";

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> vec;
    vector<int> diff;
    vector<int> result;
    int n, q, t ,t1, k;

    cin >> n >> q;

    vec.emplace_back(0);
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        vec.emplace_back(t);
    }

    diff.emplace_back(0);
    for (int i = 1; i <= n; i++)
    {
        diff.emplace_back(vec[i] - vec[i-1]);
    }

    for(auto it : diff) cout << it << " ";
    cout << endl;

    for (int i = 0; i < q; i++)
    {
        cin >> t >> t1 >> k;
        diff[t] += k;
        diff[t1+1] -= k;

        cout << endl;
    }

    result.emplace_back(diff[0]);
    for (int i = 0; i < n; i++)
    {
        result.emplace_back(result[i] + diff[i+1]);
    }

    for(int i = 1; i <= n; i++) cout << result[i] << " ";
}