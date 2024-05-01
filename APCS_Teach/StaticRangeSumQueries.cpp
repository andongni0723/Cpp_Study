#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define endl "\n";

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    vector<lint> vec;
    vector<lint> prefix;
    int n, q;
    lint t, t1;
    cin >> n >> q;

    for (int i = 0; i < n; i++)
    {
        cin >> t;
        vec.emplace_back(t);
    }

    //prefix
    prefix.emplace_back(0);
    for (int i = 0; i < n; i++)
    {
        prefix.emplace_back(prefix[i] + vec[i]);
    }

    for (int i = 0; i < q; i++)
    {
        cin >> t >> t1;
        cout << prefix[t1] - prefix[t-1] << endl;
    }
}