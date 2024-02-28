#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

int main()
{   
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    lint t, n, m;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n >> m;

        if(abs(n - m) > 1000)
            cout << (n + m) / 8 % 7 << endl;
        else if(abs(n - m) < 1000)
            cout << (n + m) * 6 % 9 << endl;
        else
            cout << 0 << endl;
    }
}