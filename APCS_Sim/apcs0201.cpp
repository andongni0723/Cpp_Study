#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define endl "\n";

int main()
{
    cout.sync_with_stdio(false);
    cin.tie(nullptr);

    int c1, c2, v1, v2;
    cin >> c1 >> c2 >> v1 >> v2;

    if(c1 * v1 * 2 == c2 * v2 * 5)
    {
        cout << "Yes" << endl;
        cout << c1 * v1 * 2;
    }
    else
    {
        cout << "No";
    }
}