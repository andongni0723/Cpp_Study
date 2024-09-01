#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define endl "\n";

vector<pair<int, int>> vec;
vector<vector<lint>> dp((int)2e7 + 10, vector<lint>(200));
int n, k;

lint f(int i, int m)
{
    return 0;
    // if()
}

int main()
{
    cin >> n >> k;
    int t, t1;
    for (int i = 0; i < n; i++)
    {
        cin >> t >> t1;
        vec.emplace_back(t, t1);
    }

    // sort(vec.begin(), vec.end());
}
