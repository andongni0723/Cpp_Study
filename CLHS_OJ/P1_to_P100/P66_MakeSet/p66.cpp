#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    lint t;
    vector<lint> vec;
    while (cin >> t)
    {
        if (!binary_search(vec.begin(), vec.end(), t))
        {
            vec.emplace_back(t);
            sort(vec.begin(), vec.end());
        }
    }

    for (auto it: vec)
    {
        cout << it << endl;
    }
}