#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

int main()
{   
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    lint n, t;
    set<lint> set;

    for (int i = 0; i < n; i++)
    {
        cin >> t;
        set.insert(t);
    }

    for(auto it : set)
    {
        cout << it;
    }
}