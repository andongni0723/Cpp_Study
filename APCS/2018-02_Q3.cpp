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
    vector<lint> cut0;
    int n, k, t;
    cin >> n >> k;

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

    //cut0
    for (int i = 0; i < n; i++)
    {
        cut0.emplace_back(vec[i] * (i+1));
    }




    return 0;
}