#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

int gcd(int a, int b)
{

    if(b == 0)
        return a;
    else
        return gcd(b, a%b);
}

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t1, t2;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> t1 >> t2;
        cout << gcd(t1, t2) << endl;
    }
}