#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define endl "\n";

int main()
{
    lint cost = 0;
    int n, L;
    vector<pair<int, int>> vec; // time, pos
    set<int> mySet;
    cin >> n >> L;

    mySet.insert(0);
    mySet.insert(L);

    int t1, t2;
    for (int i = 0; i < n; i++)
    {
        cin >> t1 >> t2;
        vec.emplace_back(t2, t1);
    }

    sort(vec.begin(), vec.end());

    for (int i = 0; i < n; i++)
    {
        mySet.insert(vec[i].second);
        auto currentIndex = mySet.find(vec[i].second);
        auto R = mySet.upper_bound(vec[i].second);
        auto L = --mySet.lower_bound(vec[i].second);

        cost += *R - *L;
    }
    cout << cost;
}
