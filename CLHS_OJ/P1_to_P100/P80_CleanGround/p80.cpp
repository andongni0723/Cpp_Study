#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

int main()
{   
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    lint n, m, t, safe_count = 0, unsafe_count = 0;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> t;

        if(t == 1)
            safe_count++;
        else if(t == 9)
        {
            if(n == 0) continue;
            n--;
            safe_count++;
        }
    }

    cout << safe_count;
}