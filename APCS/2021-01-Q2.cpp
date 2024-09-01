#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define endl "\n";

int n, m , k;
vector<vector<int>> vec(100, vector<int>(100));
int main()
{
    cin >> n >> m >> k;

    int t;
    for (int iy = 0; iy < n; iy++)
    {
        for (int ix = 0; ix < m; ix++)
        {
            cin >> t;
            vec[iy][ix] = t;
        }
    }

    lint cost = 0;
    int city;
    for (int i = 0; i < k; i++)
    {
        for (int s = 0; s < n; s++)
        {
            cin >> city;

        }
    }
}
