#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define endl "\n";

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    lint n, m;
    lint a, b, c;
    lint max_c = 0;

    vector<lint> vec((int)1e5 + 10);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> c;
        vec[a]++;
        vec[b]++;
        max_c = max(max_c, c);
    }



}