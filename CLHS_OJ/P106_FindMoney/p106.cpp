#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    lint n, t, l;
    unordered_map<lint, lint> map;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        map[t] = i;
    }
    cin >> l;

    if(map.find(l) != map.end())
    {
        cout << map[l] << endl;
    }
    else
        cout << -1;
}