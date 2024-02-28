#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

int main()
{   
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    lint n, q, t;
    cin >> n >> q;

    unordered_set<lint> set;

    for (int i = 0; i < n; i++)
    {
        cin >> t;
        set.insert(t);
    }

    for (int i = 0; i < q; i++)
    {
        cin >> t;
        if(set.find(t) != set.end())
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}
