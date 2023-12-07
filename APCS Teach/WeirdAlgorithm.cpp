#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
int main()
{   
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    lint n;
    cin >> n;
    cout << n << " ";

    while (n != 1)
    {
        if(n % 2 == 0) // even
        {
            n /= 2;
        }
        else // odd
        {
            n = n * 3 + 1;
        }

        cout << n << " ";
    }
}