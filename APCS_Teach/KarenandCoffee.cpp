#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define endl "\n";

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    lint n, k, q, l, r, maxR = 0;
    vector<lint> diff((int)2e5 + 10, 0);
    vector<lint> prefix;
    vector<lint> vec;

    cin >> n >> k >> q;
    for (lint i = 0; i < n; i++)
    {
        cin >> l >> r;
        maxR = max(maxR, r);

        diff[l]++;
        diff[r+1]--;
    }

    vec.emplace_back(0);
    for (lint i = 0; i < maxR; i++)
    {
        vec.emplace_back(vec[i] + diff[i + 1]);
    }

//    for (int i = 0; i < maxR; i++)
//    {
////        cout << vec[i] << " ";
//    }

    prefix.emplace_back(0);
    for (int i = 0; i < maxR; i++)
    {
        prefix.emplace_back(prefix[i] + diff[i]);
    }




    for (lint i = 0; i < q; i++)
    {
        lint result = 0;
        cin >> l >> r;

        cout << prefix[r] - prefix[i] << endl;
    }
}