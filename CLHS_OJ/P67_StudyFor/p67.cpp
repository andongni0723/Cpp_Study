#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    lint n, t = 1;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << t << endl;
        t++;
    }
}