#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t1, t2;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> t1 >> t2;
        // -15
        cout << max(abs(t1), abs(t2)) - 15 << endl;
    }
}